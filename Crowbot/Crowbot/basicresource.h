#ifndef BASICRESOURCE_H_INCLUDED
#define BASICRESOURCE_H_INCLUDED

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <ctime>
/*
#include <conio.h>
*/

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
/*
#include <tchar.h>
*/
#include <unordered_map>
#include <vector>
/*
#include <wchar.h>
#include <windows.h>
#include <wininet.h>
*/

//lua.hpp covers the extern "C"
#include <lua.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

// Frame Definitions
enum class FRAMETYPE : int
{
    INVALID=0,
    STARTSCREEN,
    STAGE
};

// Font Definitions
enum class FONTTYPE : int
{
    ARIAL=0,
    FFF_TUSJ,
    FREEDOM,
    MONTESERRAT,
    MONTESERRAT_B,
    AMBLE,
    AMBLE_B,
    AMBLE_I,
    AMBLE_BI,
    ORBITRON,
    ORBITRON_LT,
    ORBITRON_B
};

#define FONT_DEFAULT_GAME FONTTYPE::MONTESERRAT
#define FONT_SIZE_DEFAULT_GAME 15
#define FONT_SIZE_LARGE_GAME 48

//Audio Definitions
enum class AUDIOTYPE : int
{
    INVALID=0
};

// Image Definitions
enum class IMAGETYPE : int
{
    INVALID=0,
    RECTANGLE,
    DEFAULT_BUTTON,
    DEFAULT_BUTTON_H,
    DEFAULT_BUTTON_D,
    SPRITESHEET_ENTITY_CROWBOT,
    SPRITESHEET_PROJECTILE_BULLET
};

// Entity Definitions
enum class ENTITYTYPE : int
{
    INVALID=0,
    CROWBOT
};

// Projectile Definitions
enum class PROJECTILETYPE : int
{
    INVALID=0,
    BULLET
};

// Event Definitions
enum class EVENTTYPE : int
{
    INVALID=0,
    TIMER,
    KEYPRESS,
    COLLECTGARBAGE
};

// Event Options Definitions
enum class EVENTOPTIONS : int
{
    INVALID=0,
    WILDCARD
};

// Button Definitions
enum class BUTTONTYPE : int
{
    INVALID=0
};

// Mouse Definitions
enum class MOUSEBUTTON : int
{
    LEFT=0,
    RIGHT
};

// Color Definitions
#define AL_COL_BLACK (al_map_rgb(0, 0, 0))
#define AL_COL_WHITE (al_map_rgb(255, 255, 255))
#define AL_COL_RED (al_map_rgb(255, 0, 0))
#define AL_COL_GREEN (al_map_rgb(0, 255, 0))
#define AL_COL_BLUE (al_map_rgb(0, 0, 255))

// Math Macros
#define M_PI 3.141592653589793238
#define DEG_TO_RAD(_a) (_a*M_PI/180.0)
#define RAD_TO_DEG(_a) (_a/M_PI*180.0)

// Lua Macros
#define lua_emptystack(_a) {lua_settop(_a, 0)}
#define lua_makecfunction(_a, _b, _c) {lua_pushcfunction(_a,_b);lua_setglobal(_a,_c);}
#define lua_makelfunction(_a, _b, _c) {if(luaL_loadfile(_a,_b)==LUA_OK)lua_setglobal(_a,_c);}
#define lua_regmfunctions(_a, _b) {luaL_newmetatable(_a,_b);lua_pushvalue(_a,-1);lua_setfield(_a,-2,"__index");}
#define lua_makememfunction(_a, _b, _c) ([](lua_State*l)->int{_a*obj=*static_cast<_a**>(luaL_testudata(l,1,_b));lua_remove(l,1);(_c);})
#define lua_makemfunction(_a, _b, _c, _d, _e) {lua_pushcfunction(_a,lua_makememfunction(_d,_c,_e));lua_setfield(_a,-2,_b);}
#define lua_prepmfunctions(_a, _b, _c, _d, _e) {*static_cast<_d**>(lua_newuserdata(_a,sizeof(_d*)))=_e;luaL_setmetatable(_a,_c);lua_setglobal(_a,_b);lua_remove(_a,1);}
#define luaE_beginmfunctions(_a, _b) {lua_State*_ls=_a;_lua_temp_char_ptr=const_cast<char*>(_b)
#define luaE_regmfunctions() {luaL_newmetatable(_ls,const_cast<const char*>(_lua_temp_char_ptr));lua_pushvalue(_ls,-1);lua_setfield(_ls,-2,"__index");}
#define luaE_makememfunction(_a, _b) ([](lua_State*l)->int{_a*obj=*static_cast<_a**>(luaL_testudata(l,1,const_cast<const char*>(_lua_temp_char_ptr)));lua_remove(l,1);(_b);})
#define luaE_makemfunction(_a, _b, _c) {lua_pushcfunction(_ls,luaE_makememfunction(_b,_c));lua_setfield(_ls,-2,_a);}
#define luaE_prepmfunctions(_a, _b, _c) {*static_cast<_b**>(lua_newuserdata(_ls,sizeof(_b*)))=_c;luaL_setmetatable(_ls,const_cast<const char*>(_lua_temp_char_ptr));lua_setglobal(_ls,_a);lua_remove(_ls,1);}
#define luaE_endmfunctions() _lua_temp_char_ptr=nullptr;}

// Other Macros
#define internalData(_a) internal##_a##AnimatedConstructorData

#endif // BASICRESOURCE_H_INCLUDED
