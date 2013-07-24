#include "resource.h"

#define SHOW_TOKENS

void Parser::parse(Lexxer &lexxer, std::string name, std::string directory)
{
    std::ofstream fout(directory+name+".lua");
    if(lexxer.getNextToken()=="__BEGIN")
    {
#ifdef SHOW_TOKENS
        printf("<Token: [__BEGIN]>\n");
#endif
        int indent=4;
        std::string tok, line;
        fout<<"function "<<name<<"("<<")"<<std::endl;
        while(tok!="__END")
        {
            tok=lexxer.getNextToken();
#ifdef SHOW_TOKENS
            printf("<Token: [%s]>\n", tok.c_str());
#endif
            if(tok=="__FUNC")
            {
                std::string function_name=lexxer.getNextToken();
                line+=function_name+"(";
#ifdef SHOW_TOKENS
                printf("<Function Token: [%s]>\n", function_name.c_str());
#endif
                tok=lexxer.getNextToken();
                while(tok!="__/FUNC")
                {
#ifdef SHOW_TOKENS
                    printf("<Argument Token: [%s]>\n", tok.c_str());
#endif
                    line+=tok+" ";
                    tok=lexxer.getNextToken();
                }
                line+=")";
            }
            else if(tok=="output")
            {
                line+="io.print(\"";
                tok=lexxer.getNextToken();
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
    lexxer.resetLexxer();
    fout.close();
}
