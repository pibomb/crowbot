#include "resource.h"

#define SHOW_TOKENS

void Parser::parse(Lexer &lexer, std::string name, std::string fargs, std::string directory)
{
    std::ofstream fout(directory+name+".lua");
    if(lexer.getNextToken()=="__BEGIN")
    {
#ifdef SHOW_TOKENS
        printf("<Token: [__BEGIN]>\n");
#endif
        int indent=4;
        std::string tok, line;
        fout<<"function "<<name<<"("<<fargs<<")"<<std::endl;
        while(tok!="__END")
        {
            tok=lexer.getNextToken();
#ifdef SHOW_TOKENS
            printf("<Token: [%s]>\n", tok.c_str());
#endif
            if(tok=="__FUNC")
            {
                std::string function_name=lexer.getNextToken();
                line+=function_name+"(";
#ifdef SHOW_TOKENS
                printf("<Function Token: [%s]>\n", function_name.c_str());
#endif
                tok=lexer.getNextToken();
                for(int i=0; tok!="__/FUNC"; i++)
                {
#ifdef SHOW_TOKENS
                    printf("<Argument Token: [%s]>\n", tok.c_str());
#endif
                    if(i>0)
                    {
                        line+=", ";
                    }
                    line+=tok;
                    tok=lexer.getNextToken();
                }
                line+=")";
            }
            else if(tok=="__FOR")
            {
                line+="for "+lexer.getNextToken()+", "+lexer.getNextToken()+", "+lexer.getNextToken()+" do";
            }
            else if(tok=="__/FOR")
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
                line+="io.print(\"";
                tok=lexer.getNextToken();
#ifdef SHOW_TOKENS
                printf("<Output Token: [%s]>\n", tok.c_str());
#endif
                line+=tok+"\")";
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
