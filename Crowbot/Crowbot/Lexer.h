#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include "basicresource.h"

class Lexer
{
private:
    int current_token;
    int current_expression;
    std::vector<std::string> expressions;
    std::vector<std::string> tokens;
    void generateExpressions(std::string raw);
    std::string getNextExpression();
    std::string getNextValidExpression();
    std::string peekNextExpression(int distance_arg=0);
    std::string peekNextValidExpression();
    void skipNextExpression();
    int getCurrentExpressionPosition();
    void resetExpressions();
public:
    std::string generateTokens(std::string raw);
    std::string getNextToken();
    std::string peekNextToken(int distance_arg=0);
    void skipNextToken();
    void resetLexer();
};

#endif // LEXER_H_INCLUDED
