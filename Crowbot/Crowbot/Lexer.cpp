#include "resource.h"

void Lexer::generateExpressions(std::string raw)
{
    removeAllSpaces(raw);
    raw+="\n";
    expressions.clear();
    unsigned int pos=raw.find("\n");
    do
    {
        expressions.push_back(raw.substr(0, pos));
        //raw.erase(0, raw.find_first_not_of("\n", pos));
        raw.erase(0, pos+1);
        pos=raw.find("\n");
    }
    while(pos!=std::string::npos);
}

std::string Lexer::getNextExpression()
{
    if(current_expression==static_cast<int>(expressions.size()))
    {
        return "__EOF";
    }
    return expressions[current_expression++];
}

std::string Lexer::peekNextExpression(int distance_arg)
{
    if(current_expression+distance_arg>=static_cast<int>(expressions.size()))
    {
        return "__EOF";
    }
    if(current_expression+distance_arg<0)
    {
        return "__INVALID";
    }
    return expressions[current_expression+distance_arg];
}

std::string Lexer::getNextValidExpression()
{
    std::string valid_expression=getNextExpression();
    while(valid_expression.empty())
    {
        valid_expression=getNextExpression();
    }
    return valid_expression;
}

void Lexer::skipNextExpression()
{
    if(current_expression!=static_cast<int>(expressions.size()))
    {
        current_expression++;
    }
}

int Lexer::getCurrentExpressionPosition()
{
    return current_expression;
}

void Lexer::resetExpressions()
{
    current_expression=0;
}

std::string Lexer::generateTokens(std::string raw)
{
    try
    {
        resetExpressions();
        generateExpressions(raw);
        tokens.clear();
        tokens.push_back("__BEGIN");
        std::stack<std::string> braces;
        std::string tempString;
        std::string curExpr;
        std::string lastExpr;
        curExpr=getNextValidExpression();
        unsigned int pos=0;
        unsigned int epos=curExpr.find_first_of("\"()[]{}", pos+1);
        while(curExpr!="__EOF")
        {
            if(curExpr[epos]=='"')
            {
                lastExpr="__S/STRLIT"; // String Literal
                unsigned int qpos=curExpr.find("\"", epos+1);
                tempString=curExpr.substr(epos, qpos-epos);
            }
            else if(curExpr[epos]=='(')
            {
                if(epos>=2 && curExpr.substr(epos-2, 2)=="if")
                {
                    lastExpr="__S/IF"; // If Statement
                    tokens.push_back("__IF");
                    unsigned int ppos=curExpr.length()-1;
                    tempString=curExpr.substr(epos+1, ppos-epos-1);
                    if(tempString.empty())
                    {
                        throw std::string("Empty if statement at line ")+intToStr(getCurrentExpressionPosition()+1);
                    }
                    unsigned int spos;
                    while(!tempString.empty())
                    {
                        spos=tempString.find_first_of("!&|=<>");
                        if(spos==0)
                        {
                            if(tempString[spos]=='!')
                            {
                                tokens.push_back("__NOT");
                            }
                            else if(tempString[spos]=='&')
                            {
                                tokens.push_back("__AND");
                            }
                            else if(tempString[spos]=='|')
                            {
                                tokens.push_back("__OR");
                            }
                            else if(tempString[spos]=='=')
                            {
                                tokens.push_back("__EQUALS");
                            }
                            else if(tempString[spos]=='<')
                            {
                                tokens.push_back("__LESS");
                            }
                            else if(tempString[spos]=='>')
                            {
                                tokens.push_back("__GREATER");
                            }
                            tempString.erase(0, 1);
                        }
                        else
                        {
                            tokens.push_back(tempString.substr(0, spos));
                            if(spos==std::string::npos)
                            {
                                tempString.clear();
                                break;
                            }
                            tempString.erase(0, spos);
                        }
                    }
                    tokens.push_back("__/IF");
                }
                else if(epos>=3 && curExpr.substr(epos-3, 3)=="for")
                {
                    lastExpr="__S/FOR"; // For loop
                    tokens.push_back("__FOR");
                    unsigned int ppos=curExpr.length()-1;
                    tempString=curExpr.substr(epos+1, ppos-epos-1);
                    if(tempString.empty())
                    {
                        throw std::string("Empty for loop at line ")+intToStr(getCurrentExpressionPosition()+1);
                    }
                    unsigned int spos;
                    int for_args=0;
                    while(!tempString.empty())
                    {
                        spos=tempString.find(";");
                        tokens.push_back(tempString.substr(0, spos));
                        if(spos==std::string::npos)
                        {
                            tempString.clear();
                            break;
                        }
                        for_args++;
                        tempString.erase(0, spos+1);
                    }
                    if(for_args<3)
                    {
                        tokens.push_back("1");
                    }
                }
                else
                {
                    lastExpr="__S/FUNC"; // Function
                    tokens.push_back("__FUNC");
                    unsigned int ppos;
                    if(curExpr.empty())
                    {
                        ppos=std::string::npos;
                    }
                    else
                    {
                        ppos=curExpr.length()-1;
                    }
                    tokens.push_back(curExpr.substr(pos, epos-pos));
                    tempString=curExpr.substr(epos+1, ppos-epos-1);
                    unsigned int spos;
                    while(!tempString.empty())
                    {
                        spos=tempString.find(",");
                        tokens.push_back(tempString.substr(0, spos));
                        if(spos==std::string::npos)
                        {
                            tempString.clear();
                            break;
                        }
                        tempString.erase(0, spos+1);
                    }
                    tokens.push_back("__/FUNC");
                }
            }
            else if(curExpr[epos]=='{')
            {
                braces.push(lastExpr);
                lastExpr="__S/OBRACE"; // Open Braces
                tokens.push_back("__INDENT");
            }
            else if(curExpr[epos]=='}')
            {
                lastExpr="__S/CBRACE"; // Close Braces
                if(braces.empty())
                {
                    throw std::string("Missing opening brace at line ")+intToStr(getCurrentExpressionPosition()+1);
                }
                tempString=braces.top();
                braces.pop();
                tokens.push_back("__/INDENT");
            }
            else
            {
                tempString=curExpr.substr(pos, epos-pos-1);
            }
            if(!tempString.empty())
            {
                tokens.push_back(tempString);
                tempString.clear();
            }
            curExpr=getNextValidExpression();
            pos=0;
            epos=curExpr.find_first_of("\"()[]{}");
        }
        resetExpressions();
        resetLexer();
    }
    catch(std::string lexer_exception)
    {
        return lexer_exception;
    }
    catch(const char *lexer_exception)
    {
        return std::string(lexer_exception);
    }
    for(int i=0; i<(int)tokens.size(); i++)
    {
        std::cout<<tokens[i]<<std::endl;
    }
    return "";
}

std::string Lexer::getNextToken()
{
    if(current_token==static_cast<int>(tokens.size()))
    {
        return "__END";
    }
    return tokens[current_token++];
}

std::string Lexer::peekNextToken(int distance_arg)
{
    if(current_token+distance_arg>=static_cast<int>(tokens.size()))
    {
        return "__END";
    }
    if(current_token+distance_arg<0)
    {
        return "__INVALID";
    }
    return tokens[current_token+distance_arg];
}

void Lexer::skipNextToken()
{
    if(current_token!=static_cast<int>(tokens.size()))
    {
        current_token++;
    }
}

void Lexer::resetLexer()
{
    current_token=0;
}
