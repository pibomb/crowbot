#include "resource.h"

void Lexer::generateTokens(std::string raw)
{
    tokens.clear();
    tokens.push_back("__BEGIN");
    removeAllSpaces(raw);
    raw=" "+raw;
    unsigned int pos=0;
    unsigned int epos=raw.find_first_of("\"()[]{}", pos+1);
    std::string possible_token;
    std::stack<std::string> braces;
    std::string lastExpr;
    while(epos!=std::string::npos)
    {
        if(raw[epos]=='"')
        {
            lastExpr="__S/STRLIT"; // String Literal
            unsigned int qpos=raw.find("\"", epos+1);
            possible_token=raw.substr(epos+1, qpos-epos-1);
            pos=qpos+1;
        }
        else if(raw[epos]=='(')
        {
            if(epos>=3 && raw.substr(epos-2, 2)=="if")
            {
                lastExpr="__S/IF"; // If Statement
                tokens.push_back("__IF");
                unsigned int ppos=raw.find(")\n", epos);
                possible_token=raw.substr(epos+1, ppos-epos-1);
                unsigned int spos;
                while(!possible_token.empty())
                {
                    spos=possible_token.find_first_of("!&|=<>");
                    if(spos==0)
                    {
                        if(possible_token[spos]=='!')
                        {
                            tokens.push_back("__NOT");
                        }
                        else if(possible_token[spos]=='&')
                        {
                            tokens.push_back("__AND");
                        }
                        else if(possible_token[spos]=='|')
                        {
                            tokens.push_back("__OR");
                        }
                        else if(possible_token[spos]=='=')
                        {
                            tokens.push_back("__EQUALS");
                        }
                        else if(possible_token[spos]=='<')
                        {
                            tokens.push_back("__LESS");
                        }
                        else if(possible_token[spos]=='>')
                        {
                            tokens.push_back("__GREATER");
                        }
                        possible_token.erase(0, 1);
                    }
                    else
                    {
                        tokens.push_back(possible_token.substr(0, spos));
                        if(spos==std::string::npos)
                        {
                            possible_token.clear();
                            break;
                        }
                        possible_token.erase(0, spos);
                    }
                }
                tokens.push_back("__/IF");
                pos=ppos;
            }
            else if(epos>=4 && raw.substr(epos-3, 3)=="for")
            {
                lastExpr="__S/FOR"; // For loop
                tokens.push_back("__FOR");
                unsigned int ppos=raw.find(")\n", epos);
                possible_token=raw.substr(epos+1, ppos-epos-1);
                unsigned int spos;
                int for_args=0;
                while(!possible_token.empty())
                {
                    spos=possible_token.find(";");
                    tokens.push_back(possible_token.substr(0, spos));
                    if(spos==std::string::npos)
                    {
                        possible_token.clear();
                        break;
                    }
                    for_args++;
                    possible_token.erase(0, spos+1);
                }
                if(for_args<3)
                {
                    tokens.push_back("1");
                }
                pos=ppos;
            }
            else
            {
                lastExpr="__S/FUNC"; // Function
                tokens.push_back("__FUNC");
                unsigned int ppos=raw.find(")\n", epos+1);
                tokens.push_back(raw.substr(pos+1, epos-pos-1));
                possible_token=raw.substr(epos+1, ppos-epos-1);
                unsigned int spos;
                while(!possible_token.empty())
                {
                    spos=possible_token.find(",");
                    tokens.push_back(possible_token.substr(0, spos));
                    if(spos==std::string::npos)
                    {
                        possible_token.clear();
                        break;
                    }
                    possible_token.erase(0, spos+1);
                }
                tokens.push_back("__/FUNC");
                pos=ppos;
            }
        }
        else if(raw[epos]=='{')
        {
            braces.push(lastExpr);
            lastExpr="__S/OBRACE"; // Open Braces
            tokens.push_back("__INDENT");
            pos=epos;
        }
        else if(raw[epos]=='}')
        {
            lastExpr="__S/CBRACE"; // Close Braces
            possible_token=braces.top();
            braces.pop();
            tokens.push_back("__/INDENT");
            pos=epos;
        }
        else
        {
            possible_token=raw.substr(pos+1, epos-pos-1);
            pos=epos;
        }
        epos=raw.find_first_of("\n\"()[]{}", pos+1);
        if(!possible_token.empty())
        {
            tokens.push_back(possible_token);
            possible_token.clear();
        }
    }
    resetLexer();
    for(int i=0; i<(int)tokens.size(); i++)
    {
        std::cout<<tokens[i]<<std::endl;
    }
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
