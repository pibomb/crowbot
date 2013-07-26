#include "resource.h"

void Lexer::generateTokens(std::string raw)
{
    tokens.clear();
    tokens.push_back("__BEGIN");
    raw=" "+raw+" ";
    unsigned int pos=0;
    unsigned int epos=raw.find_first_of(" \"()[]{}", pos+1);
    std::string possible_token;
    std::stack<std::string> braces;
    std::string lastExpr;
    while(epos!=std::string::npos)
    {
        if(raw[epos]=='"')
        {
            lastExpr="__/STRLIT"; // String Literal
            unsigned int qpos=raw.find("\"", epos+1);
            possible_token=raw.substr(epos+1, qpos-epos-1);
            pos=qpos+1;
        }
        else if(raw[epos]=='(')
        {
            if(epos>=4 && raw.substr(epos-3, 3)=="for")
            {
                lastExpr="__/FOR"; // For loop
                tokens.push_back("__FOR");
                unsigned int ppos=raw.find(")", epos);
                possible_token=raw.substr(epos+1, ppos-epos-1);
                unsigned int spos;
                while(!possible_token.empty())
                {
                    spos=possible_token.find(";");
                    tokens.push_back(trimSpaces(possible_token.substr(0, spos)));
                    possible_token.erase(0, possible_token.find_first_not_of(" ;", spos));
                }
                pos=ppos;
            }
            else
            {
                lastExpr="__/FUNC"; // Function
                tokens.push_back("__FUNC");
                unsigned int ppos=raw.find(")", epos+1);
                tokens.push_back(raw.substr(pos+1, epos-pos-1));
                possible_token=raw.substr(epos+1, ppos-epos-1);
                unsigned int spos;
                while(!possible_token.empty())
                {
                    spos=possible_token.find(",");
                    tokens.push_back(trimSpaces(possible_token.substr(0, spos)));
                    possible_token.erase(0, possible_token.find_first_not_of(" ,", spos));
                }
                tokens.push_back("__/FUNC");
                pos=ppos;
            }
        }
        else if(raw[epos]=='{')
        {
            braces.push(lastExpr);
            lastExpr="__/OBRACE"; // Open Braces
            tokens.push_back("__INDENT");
            pos=epos;
        }
        else if(raw[epos]=='}')
        {
            lastExpr="__/CBRACE"; // Close Braces
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
        epos=raw.find_first_of(" \"()[]{}", pos+1);
        if(!possible_token.empty())
        {
            tokens.push_back(possible_token);
            possible_token.clear();
        }
    }
    resetLexer();
}

std::string Lexer::getNextToken()
{
    if(current_token==static_cast<int>(tokens.size()))
    {
        return "__END";
    }
    return tokens[current_token++];
}

void Lexer::resetLexer()
{
    current_token=0;
}
