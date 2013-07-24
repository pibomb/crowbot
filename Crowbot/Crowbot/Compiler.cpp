#include "resource.h"

//#define SHOW_TOKENS

std::function<void(Robot*, std::vector<int>)> Compiler::compile(Lexxer lexxer)
{
    if(lexxer.getNextToken()=="__BEGIN")
    {
#ifdef SHOW_TOKENS
        printf("<Token: [__BEGIN]>\n");
#endif
        std::vector<std::function<void(Robot*, std::vector<int>)>> lines;
        std::string tok;
        while(tok!="__END")
        {
            tok=lexxer.getNextToken();
#ifdef SHOW_TOKENS
            printf("<Token: [%s]>\n", tok.c_str());
#endif
            if(tok=="__FUNC")
            {
                std::string function_name=lexxer.getNextToken();
#ifdef SHOW_TOKENS
                printf("<Function Token: [%s]>\n", function_name.c_str());
#endif
                std::vector<int> args;
                tok=lexxer.getNextToken();
                while(tok!="__/FUNC")
                {
#ifdef SHOW_TOKENS
                    printf("<Argument Token: [%s]>\n", tok.c_str());
#endif
                    args.push_back(strToInt(tok));
                    tok=lexxer.getNextToken();
                }
                lines.push_back([function_name, args](Robot* robot_arg, std::vector<int> args_arg)
                                {
                                    robot_arg->executeFunction(function_name, args);
                                }
                                );
            }
            else if(tok=="output")
            {
                tok=lexxer.getNextToken();
#ifdef SHOW_TOKENS
                printf("<Output Token: [%s]>\n", tok.c_str());
#endif
                lines.push_back([tok](Robot* robot_arg, std::vector<int> args_arg)
                                {
                                    std::cout<<tok;
                                }
                                );
            }
            else if(tok=="dump")
            {
                lines.push_back([](Robot *robot_arg, std::vector<int> args_arg)
                                {
                                    for(auto &it : args_arg)
                                    {
                                        printf("%d\n", it);
                                    }
                                }
                                );
            }
        }
        return [lines](Robot *robot_arg, std::vector<int> args_arg)
                        {
                            for(auto &it : lines)
                            {
                                it(robot_arg, args_arg);
                            }
                        };
    }
    return [](Robot *robot_arg, std::vector<int>){};
}
