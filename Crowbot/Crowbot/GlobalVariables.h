#ifndef GLOBALVARIABLES_H_INCLUDED
#define GLOBALVARIABLES_H_INCLUDED

#include "basicresource.h"

class ResourceSystem;
class GarbageCollection;
class EventSystem;
class Entity;
class Projectile;

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_DISPLAY_MODE disp_data;
extern lua_State *lua_state;
extern b2World world;
extern ResourceSystem resource;
extern GarbageCollection sysGC;
extern EventSystem sysEvents;
extern Entity **activeEntity;
extern Projectile **activeBullet;
extern char* _lua_temp_char_ptr;

#endif // GLOBALVARIABLES_H_INCLUDED
