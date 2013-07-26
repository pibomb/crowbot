#include "resource.h"

std::string intToStr(int _int)
{
    std::stringstream _ss;
    _ss<<_int;
    std::string _str;
    _ss>>_str;
    return _str;
}

int strToInt(std::string _str)
{
    std::stringstream _ss(_str);
    int _int;
    _ss>>_int;
    return _int;
}

std::string leadZero(std::string str, unsigned int zeroes)
{
    while(str.length()<zeroes)
    {
        str="0"+str;
    }
    return str;
}

bool is_pixel_onscreen(Pixel& px)
{
    return px.getX()>=0 && px.getY()>=0 && px.getX()<disp_data.width && px.getY()<disp_data.height;
}

void lua_setlfunctionarg(bool bool_arg)
{
    lua_pushboolean(lua_state, bool_arg);
}

void lua_setlfunctionarg(int int_arg)
{
    lua_pushinteger(lua_state, int_arg);
}

void lua_setlfunctionarg(long long_arg)
{
    lua_pushinteger(lua_state, long_arg);
}

void lua_setlfunctionarg(std::string string_arg)
{
    lua_pushstring(lua_state, string_arg.c_str());
}

void lua_setlfunctionargs()
{
    //
}
