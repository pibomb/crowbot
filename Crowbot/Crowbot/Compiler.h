#ifndef COMPILER_H_INCLUDED
#define COMPILER_H_INCLUDED

#include "basicresource.h"

class Lexer;
class Robot;

class Compiler
{
private:
public:
    std::function<void(Robot*, std::vector<int>)> compile(Lexer lexer);
};

#endif // COMPILER_H_INCLUDED
