#include "resource.h"

ALLEGRO_DISPLAY *display;
ALLEGRO_DISPLAY_MODE disp_data;
lua_State *lua_state;
b2World world(b2Vec2(0, 0));
ResourceSystem resource;
GarbageCollection sysGC;
EventSystem sysEvents;
char *_lua_temp_char_ptr=nullptr;
