#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "basicresource.h"

class Parser
{
private:
public:
    void parse(Lexxer &lexxer, std::string name, std::string fargs, std::string directory);
};

#endif // PARSER_H_INCLUDED
