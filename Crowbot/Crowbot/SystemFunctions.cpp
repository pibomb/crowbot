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

std::string leadZero(std::string _str, unsigned int zeroes)
{
    while(_str.length()<zeroes)
    {
        _str="0"+_str;
    }
    return _str;
}

void removeAllSpaces(std::string& _str)
{
    bool quote=false;
    for(unsigned int i=0; i<_str.length(); i++)
    {
        if(_str[i]=='"')
        {
            quote=!quote;
        }
        else if(_str[i]==' ' && !quote)
        {
            _str.erase(i, 1);
            i--;
        }
    }
}

std::string trimSpaces(std::string _str)
{
    unsigned int _pos=_str.find_first_not_of(" ");
    return _str.substr(_pos, _str.find_last_not_of(" ")-_pos+1);
}

bool is_pixel_onscreen(Pixel& px)
{
    return px.getX()>0 && px.getY()>0 && px.getX()<disp_data.width && px.getY()<disp_data.height;
}

bool is_pixel_onscreen(Vec2& px)
{
    return px.getX()>0 && px.getY()>0 && px.getX()<disp_data.width && px.getY()<disp_data.height;
}

bool is_pixel_onscreen(b2Vec2& px)
{
    return px.x>PX_TO_M(0) && px.y<PX_TO_M(0) && px.x<PX_TO_M(disp_data.width) && px.y>-PX_TO_M(disp_data.height);
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
