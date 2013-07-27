#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include "basicresource.h"

class Lexer
{
private:
    int current_token;
    std::vector<std::string> tokens;
public:
    void generateTokens(std::string raw);
    std::string getNextToken();
    std::string peekNextToken();
    void skipNextToken();
    void resetLexer();
};

#endif // LEXER_H_INCLUDED
