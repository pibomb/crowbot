#ifndef SYSTEMFUNCTIONS_H_INCLUDED
#define SYSTEMFUNCTIONS_H_INCLUDED

#include "basicresource.h"

std::string intToStr(int _int);
int strToInt(std::string _str);
std::string leadZero(std::string str, unsigned int zeroes);
void lua_setlfunctionarg(bool bool_arg);
void lua_setlfunctionarg(int int_arg);
void lua_setlfunctionarg(long long_arg);
void lua_setlfunctionarg(std::string string_arg);
void lua_setlfunctionargs();
template<class T, class... Args>
void lua_setlfunctionargs(T first_arg, Args... args)
{
    lua_setlfunctionarg(first_arg);
    lua_setlfunctionargs(args...);
}
template<class... Args>
void lua_runlfunction(lua_State *lstate_arg, const char *name_arg, Args... args)
{
    lua_getglobal(lstate_arg, name_arg);
    lua_setlfunctionargs(args...);
    lua_pcall(lstate_arg, sizeof...(args), LUA_MULTRET, 0);
}

#endif // SYSTEMFUNCTIONS_H_INCLUDED
