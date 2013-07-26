#include "resource.h"

int main(int argc, char **argv)
{
	//opening lua
	lua_state = luaL_newstate();
	//opening libraries for lua, otherwise functions dont work
	luaL_openlibs(lua_state);
	/*
	//testing lua, will fit perfectly with the system in place
    lua_makecfunction(lua_state,
                     [](lua_State *l) -> int
                     {
                         (reinterpret_cast<Frame*>(luaL_checkint(l, 1)))->delayTime();
                         (reinterpret_cast<Frame*>(luaL_checkint(l, 1)))->update();
                         (reinterpret_cast<Frame*>(luaL_checkint(l, 1)))->render();
                         return 0;
                     }
                     , "updateloop");
    */
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

    Frame game(Rect(0, 0, disp_data.width, disp_data.height), 0);
    lua_regmfunctions(lua_state, "FrameMT");
    lua_makemfunction(lua_state, "delay", "FrameMT", Frame,
                                             {
                                                 obj->delayTime();
                                                 return 0;
                                             });
    lua_makemfunction(lua_state, "update", "FrameMT", Frame,
                                            {
                                                obj->update();
                                                return 0;
                                            });
    lua_makemfunction(lua_state, "render", "FrameMT", Frame,
                                            {
                                                obj->render();
                                                return 0;
                                            });
    lua_prepmfunctions(lua_state, "the_frame", "FrameMT", Frame, &game);
    al_set_target_bitmap(al_get_backbuffer(display));
    /*
    Lexer lex;
    Parser psr;
    lex.generateTokens("updateloop(f)");
    psr.parse(lex, "updatelua", "f", "luascripts/");
    */
    lua_makelfunction(lua_state, "luascripts/updatelua.lua", "updatelua");
    // Temp
    Robot rob(0, Pixel(0, 0), 0);
    rob.push(&game);
    /*
    lua_regmfunctions(lua_state, "RobotMT");
    lua_makemfunction(lua_state, "press", "RobotMT", Robot,
                                             {
                                                 obj->onKeyPress(luaL_checkint(l, 1), ALLEGRO_KEY_RIGHT, luaL_checkint(l, 2));
                                                 return 0;
                                             });
    lua_prepmfunctions(lua_state, "the_robot", "RobotMT", Robot, &rob);
    *//*
    luaE_beginmfunctions(lua_state, "RobotMT");
    luaE_regmfunctions();
    luaE_makemfunction("press", Robot,
                                     {
                                         obj->onKeyPress(luaL_checkint(l, 1), ALLEGRO_KEY_RIGHT, luaL_checkint(l, 2));
                                         return 0;
                                     });
    luaE_prepmfunctions("the_robot", Robot, &rob);
    luaE_endmfunctions();
    */
    game.addObserver(&rob);
    game.start(FRAMETYPE::STARTSCREEN);
    while(game)
    {
        //menu flickering caused by unlimited framerate?
        lua_runlfunction(lua_state, "updatelua");
        /*
        game.delayTime();
        game.update();//unskippable stuff
        game.render();//frame-skippable stuff
        */
        al_flip_display();
    }
    game.end();
    game.destroy();
    /*
    // Events example
    EventHandler *evHandler=new EventHandler([]()
                                             {
                                                 std::cout<<"Goodbye, World!\n";
                                             });
    sysEvents.addEventHandler(evHandler);
    evHandler->push(sysEvents[EVENTTYPE::INVALID]);
    evHandler->add(EVENTTYPE::INVALID);
    sysEvents[EVENTTYPE::INVALID].fire();
    */
    /*
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
    lua_close(lua_state);
    al_destroy_display(display);

    return 0;
}
