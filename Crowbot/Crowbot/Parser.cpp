#include "resource.h"

#define SHOW_TOKENS

void Parser::parse(Lexer &lexer, std::string name, std::string fargs, std::string directory)
{
    std::ofstream fout(directory+name+".lua");
    if(lexer.getNextToken()=="__BEGIN")
    {
        int indent=4;
        std::string tok, line;
        fout<<"function "<<name<<"("<<fargs<<")"<<std::endl;
        while(tok!="__END")
        {
            tok=lexer.getNextToken();
            if(tok=="__FUNC")
            {
                line+=lexer.getNextToken()+"(";
                tok=lexer.getNextToken();
                for(int i=0; tok!="__/FUNC"; i++)
                {
                    if(i>0)
                    {
                        line+=", ";
                    }
                    line+=tok;
                    tok=lexer.getNextToken();
                }
                line+=")";
            }
            else if(tok=="__IF")
            {
                line+="if ";
                tok=lexer.getNextToken();
                while(tok!="__/IF")
                {
                    if(tok=="__NOT")
                    {
                        if(lexer.peekNextToken()=="__EQUALS")
                        {
                            lexer.skipNextToken();
                            line+="~= ";
                        }
                        else
                        {
                            line+="not ";
                        }
                    }
                    else if(tok=="__AND")
                    {
                        if(lexer.peekNextToken()=="__AND")
                        {
                            lexer.skipNextToken();
                            line+="and ";
                        }
                    }
                    else if(tok=="__OR")
                    {
                        if(lexer.peekNextToken()=="__OR")
                        {
                            lexer.skipNextToken();
                            line+="or ";
                        }
                    }
                    else if(tok=="__EQUALS")
                    {
                        if(lexer.peekNextToken()=="__EQUALS")
                        {
                            lexer.skipNextToken();
                            line+="or ";
                        }
                    }
                    else if(tok=="__LESS")
                    {
                        if(lexer.peekNextToken()=="__EQUALS")
                        {
                            lexer.skipNextToken();
                            line+="<= ";
                        }
                        else
                        {
                            line+="< ";
                        }
                    }
                    else if(tok=="__GREATER")
                    {
                        if(lexer.peekNextToken()=="__EQUALS")
                        {
                            lexer.skipNextToken();
                            line+=">= ";
                        }
                        else
                        {
                            line+="< ";
                        }
                    }
                    else
                    {
                        line+=tok+" ";
                    }
                    tok=lexer.getNextToken();
                }
                line+="then";
            }
            else if(tok=="__S/IF")
            {
                line+="end";
            }
            else if(tok=="__FOR")
            {
                line+="for "+lexer.getNextToken();
                line+=", "+lexer.getNextToken();
                line+=", "+lexer.getNextToken()+" do";
            }
            else if(tok=="__S/FOR")
            {
                line+="end";
            }
            else if(tok=="__INDENT")
            {
                indent+=4;
                continue;
            }
            else if(tok=="__/INDENT")
            {
                indent-=4;
                continue;
            }
            else if(tok=="output")
            {
                line+="io.print(\""+lexer.getNextToken()+"\")";
            }
            else
            {
                continue;
            }
            for(int i=0; i<indent; i++)
            {
                fout<<" ";
            }
            fout<<line<<std::endl;
            line.clear();
        }
        fout<<"end"<<std::endl;
    }
    lexer.resetLexer();
    fout.close();
}
