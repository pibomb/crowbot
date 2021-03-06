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

std::string Lexer::peekNextValidExpression()
{
    int i=0;
    while(peekNextExpression(i).empty())
    {
        i++;
    }
    return peekNextExpression(i);
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
        std::stack<int> previousIf;
        std::string tempString;
        std::string curExpr;
        std::string lastExpr;
        curExpr=getNextValidExpression();
        int ifBlock=0;
        unsigned int pos=0;
        unsigned int epos=curExpr.find_first_of("\"()[]{}", pos+1);
        while(curExpr!="__EOF")
        {
            if(curExpr=="else")
            {
                if(ifBlock==0 || ifBlock==3)
                {
                    throw "else without a previous if";
                }
                lastExpr="__S/ELSE"; // If Statement
                ifBlock=3;
                tokens.push_back("__ELSE");
                if(curExpr.length()!=4)
                {
                    throw "Unexpected code after 'else'";
                }
            }
            else if(curExpr[epos]=='"')
            {
                lastExpr="__S/STRLIT"; // String Literal
                unsigned int qpos=curExpr.find("\"", epos+1);
                tempString=curExpr.substr(epos, qpos-epos);
            }
            else if(curExpr[epos]=='(')
            {
                if(epos==2 && curExpr.substr(0, 2)=="if")
                {
                    previousIf.push(ifBlock);
                    lastExpr="__S/IF"; // If Statement
                    ifBlock=1;
                    tokens.push_back("__IF");
                    unsigned int ppos=curExpr.length()-1;
                    tempString=curExpr.substr(epos+1, ppos-epos-1);
                    if(tempString.empty())
                    {
                        throw "Empty if statement";
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
                else if(epos==6 && curExpr.substr(0, 6)=="elseif")
                {
                    if(ifBlock==0 || ifBlock==3)
                    {
                        throw "elseif without a previous if";
                    }
                    lastExpr="__S/ELSEIF"; // If Statement
                    ifBlock=2;
                    tokens.push_back("__ELSEIF");
                    unsigned int ppos=curExpr.length()-1;
                    tempString=curExpr.substr(epos+1, ppos-epos-1);
                    if(tempString.empty())
                    {
                        throw "Empty else if statement";
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
                    tokens.push_back("__/ELSEIF");
                }
                else if(epos==3 && curExpr.substr(0, 3)=="for")
                {
                    lastExpr="__S/FOR"; // For loop
                    tokens.push_back("__FOR");
                    unsigned int ppos=curExpr.length()-1;
                    tempString=curExpr.substr(epos+1, ppos-epos-1);
                    if(tempString.empty())
                    {
                        throw "Empty for loop";
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
                    if(for_args<2)
                    {
                        throw "For loop missing arguments";
                    }
                    else if(for_args==2)
                    {
                        tokens.push_back("1");
                    }
                }
                else
                {
                    lastExpr="__S/FUNC"; // Function
                    tokens.push_back("__FUNC");
                    size_t ppos;
                    if(curExpr.empty())
                    {
                        ppos=std::string::npos;
                    }
                    else
                    {
                        ppos=curExpr.length()-1;
                    }
                    tempString=curExpr.substr(pos, epos-pos);
                    std::replace(tempString.begin(), tempString.end(), '.', ':');
                    tokens.push_back(tempString);
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
                if(ifBlock<=1)
                {
                    braces.push(lastExpr);
                    lastExpr="__S/OBRACE"; // Open Braces
                    tokens.push_back("__INDENT");
                }
            }
            else if(curExpr[epos]=='}')
            {
                if(ifBlock)
                {
                    if((ifBlock==3 && braces.top()=="__S/IF") || (ifBlock==2 && !(peekNextValidExpression()=="else" || peekNextValidExpression().substr(0, 7)=="elseif(")))
                    {
                        ifBlock=previousIf.top();
                        previousIf.pop();
                    }
                    else
                    {
                        curExpr=getNextValidExpression();
                        pos=0;
                        epos=curExpr.find_first_of("\"()[]{}");
                        continue;
                    }
                }
                lastExpr="__S/CBRACE"; // Close Braces
                if(braces.empty())
                {
                    throw "Missing opening brace";
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
        if(!braces.empty())
        {
            throw intToStr(braces.size())+" unclosed braces in total";
        }
        resetExpressions();
        resetLexer();
    }
    catch(std::string lexer_exception)
    {
        return lexer_exception+" at line "+intToStr(getCurrentExpressionPosition()+1);
    }
    catch(const char *lexer_exception)
    {
        return std::string(lexer_exception)+" at line "+intToStr(getCurrentExpressionPosition()+1);
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
