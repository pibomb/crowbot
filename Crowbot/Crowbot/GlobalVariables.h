#ifndef GLOBALVARIABLES_H_INCLUDED
#define GLOBALVARIABLES_H_INCLUDED

#include "basicresource.h"

class ResourceSystem;

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_DISPLAY_MODE disp_data;
extern lua_State *lua_state;
extern ResourceSystem resource;

#endif // GLOBALVARIABLES_H_INCLUDED
