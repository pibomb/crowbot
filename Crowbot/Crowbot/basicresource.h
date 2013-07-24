#ifndef BASICRESOURCE_H_INCLUDED
#define BASICRESOURCE_H_INCLUDED

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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
#include <set>
#include <sstream>
#include <string>
#include <typeinfo>
/*
#include <tchar.h>
*/
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
    DEFAULT_BUTTON_D
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

// Lua Macros
#define lua_makefunction(_a, _b, _c) lua_pushcfunction(_a, _b);lua_setglobal(_a, _c);

#endif // BASICRESOURCE_H_INCLUDED
