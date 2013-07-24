#ifndef COMPILER_H_INCLUDED
#define COMPILER_H_INCLUDED

#include "basicresource.h"

class Lexxer;
class Robot;

class Compiler
{
private:
public:
    std::function<void(Robot*, std::vector<int>)> compile(Lexxer lexxer);
};

#endif // COMPILER_H_INCLUDED
