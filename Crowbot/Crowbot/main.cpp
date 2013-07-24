#include "resource.h"

int addition(lua_State *l)
{
    // number of input arguments
    int argc = lua_gettop(l);
    // print input arguments
    std::cout << "[C++] Function called from Lua with " << argc
              << " input arguments" << std::endl;
    int sum=0;
    for(int i=0; i<argc; i++)
    {
        std::cout << " input argument #" << argc-i << ": "
                  << lua_tostring(l, lua_gettop(l)) << std::endl;
        sum+=lua_tointeger(l, lua_gettop(l));
        lua_pop(l, 1);
    }
    // push to the stack the multiple return values
    std::cout << "[C++] Returning the sum" << std::endl;
    lua_pushnumber(l, sum);
    // number of return values
    return 1;
}

int main(int argc, char **argv)
{
	//opening lua
	lua_state = luaL_newstate();
	//opening libraries for lua, otherwise functions dont work
	luaL_openlibs(lua_state);
	//testing lua, will fit perfectly with the system in place
    // push the C++ function to be called from Lua
    std::cout << "[C++] Pushing the C++ function" << std::endl;
    lua_pushcfunction(lua_state, addition);
    lua_setglobal(lua_state, "addition");
    // load the script
    std::cout << "[C++] Loading the Lua script" << std::endl;
    int status = luaL_loadfile(lua_state, "luascripts/luascript.lua");
    std::cout << " return: " << status << std::endl;
    // run the script with the given arguments
    std::cout << "[C++] Running script" << std::endl;
    int result = 0;
    if(status == LUA_OK)
    {
        result = lua_pcall(lua_state, 0, LUA_MULTRET, 0);
    }
    else
    {
        std::cout << " Could not load the script." << std::endl;
    }
    std::cout<<"[C++] The return of result is: "<<result<<std::endl;
	//initializing allegro
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_get_display_mode(al_get_num_display_modes()-1, &disp_data);
    //al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
    disp_data.width*=0.8;
    disp_data.height*=0.8;
    display=al_create_display(disp_data.width, disp_data.height);
	if(!display)
    {
        return -1;
    }
	al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(5);
    resource.initialize();
    /*
    Lexxer lex;
    //std::string str;
    //std::getline(std::cin, str);
    //lex.generateTokens(str);
    lex.generateTokens("output \"Hello, World!\n\" dump");
    Compiler cmp;
    Robot robo;
    auto f=cmp.compile(lex);
    lex.generateTokens("hello(1, 2) hello(3, 4, 5, 6)");
    auto g=cmp.compile(lex);
    robo.addFunction("hello", f);
    robo.addFunction("function", g);
    robo.executeFunction("hello");
    robo.executeFunction("function");
    robo.executeFunction("function");
    */
    resource.cleanup();
    al_destroy_display(display);

    return 0;
}
