#include "resource.h"

int main(int argc, char **argv)
{
	//opening lua
	lua_state = luaL_newstate();
	//opening libraries for lua, otherwise functions dont work
	luaL_openlibs(lua_state);
	//testing lua, will fit perfectly with the system in place
    lua_makecfunction(lua_state,
                     [](lua_State *l) -> int
                     {
                         ((Frame*)lua_tointeger(l, 1))->delayTime();
                         ((Frame*)lua_tointeger(l, 1))->update();
                         ((Frame*)lua_tointeger(l, 1))->render();
                         lua_pop(l, 1);
                         return 0;
                     }
                     , "updateloop");
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
    game.start(FRAMETYPE::STARTSCREEN);
    al_set_target_bitmap(al_get_backbuffer(display));
    Lexer lex;
    Parser psr;
    lex.generateTokens("updateloop(f)");
    psr.parse(lex, "updatelua", "f", "luascripts/");
    lua_makelfunction(lua_state, "luascripts/updatelua.lua", "updatelua");
    while(game)
    {
        //menu flickering caused by unlimited framerate?
        lua_runlfunction(lua_state, "updatelua", intptr_t(&game));
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
