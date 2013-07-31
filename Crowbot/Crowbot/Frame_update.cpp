#include "resource.h"

void Frame::update()
{
    if(!valid)
    {
        return;
    }
    switch(id)
    {
    case FRAMETYPE::STARTSCREEN:
    {
        for(ALLEGRO_EVENT ev; valid && al_get_next_event(event_queue, &ev);)
        {
            switch(ev.type)
            {
            case ALLEGRO_EVENT_TIMER:
            {
                invalidate();
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            {
                valid=false;
                return;
            }
            case ALLEGRO_EVENT_KEY_DOWN:
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_A:
                {
                    key[ALLEGRO_KEY_A]=true;
                    break;
                }
                case ALLEGRO_KEY_B:
                {
                    key[ALLEGRO_KEY_B]=true;
                    break;
                }
                case ALLEGRO_KEY_C:
                {
                    key[ALLEGRO_KEY_C]=true;
                    break;
                }
                case ALLEGRO_KEY_D:
                {
                    key[ALLEGRO_KEY_D]=true;
                    break;
                }
                case ALLEGRO_KEY_E:
                {
                    key[ALLEGRO_KEY_E]=true;
                    break;
                }
                case ALLEGRO_KEY_F:
                {
                    key[ALLEGRO_KEY_F]=true;
                    break;
                }
                case ALLEGRO_KEY_G:
                {
                    key[ALLEGRO_KEY_G]=true;
                    break;
                }
                case ALLEGRO_KEY_H:
                {
                    key[ALLEGRO_KEY_H]=true;
                    break;
                }
                case ALLEGRO_KEY_I:
                {
                    key[ALLEGRO_KEY_I]=true;
                    break;
                }
                case ALLEGRO_KEY_J:
                {
                    key[ALLEGRO_KEY_J]=true;
                    break;
                }
                case ALLEGRO_KEY_K:
                {
                    key[ALLEGRO_KEY_K]=true;
                    break;
                }
                case ALLEGRO_KEY_L:
                {
                    key[ALLEGRO_KEY_L]=true;
                    break;
                }
                case ALLEGRO_KEY_M:
                {
                    key[ALLEGRO_KEY_M]=true;
                    break;
                }
                case ALLEGRO_KEY_N:
                {
                    key[ALLEGRO_KEY_N]=true;
                    break;
                }
                case ALLEGRO_KEY_O:
                {
                    key[ALLEGRO_KEY_O]=true;
                    break;
                }
                case ALLEGRO_KEY_P:
                {
                    key[ALLEGRO_KEY_P]=true;
                    break;
                }
                case ALLEGRO_KEY_Q:
                {
                    key[ALLEGRO_KEY_Q]=true;
                    break;
                }
                case ALLEGRO_KEY_R:
                {
                    key[ALLEGRO_KEY_R]=true;
                    break;
                }
                case ALLEGRO_KEY_S:
                {
                    key[ALLEGRO_KEY_S]=true;
                    break;
                }
                case ALLEGRO_KEY_T:
                {
                    key[ALLEGRO_KEY_T]=true;
                    break;
                }
                case ALLEGRO_KEY_U:
                {
                    key[ALLEGRO_KEY_U]=true;
                    break;
                }
                case ALLEGRO_KEY_V:
                {
                    key[ALLEGRO_KEY_V]=true;
                    break;
                }
                case ALLEGRO_KEY_W:
                {
                    key[ALLEGRO_KEY_W]=true;
                    break;
                }
                case ALLEGRO_KEY_X:
                {
                    key[ALLEGRO_KEY_X]=true;
                    break;
                }
                case ALLEGRO_KEY_Y:
                {
                    key[ALLEGRO_KEY_Y]=true;
                    break;
                }
                case ALLEGRO_KEY_Z:
                {
                    key[ALLEGRO_KEY_Z]=true;
                    break;
                }
                case ALLEGRO_KEY_0:
                {
                    key[ALLEGRO_KEY_0]=true;
                    break;
                }
                case ALLEGRO_KEY_1:
                {
                    key[ALLEGRO_KEY_1]=true;
                    break;
                }
                case ALLEGRO_KEY_2:
                {
                    key[ALLEGRO_KEY_2]=true;
                    break;
                }
                case ALLEGRO_KEY_3:
                {
                    key[ALLEGRO_KEY_3]=true;
                    break;
                }
                case ALLEGRO_KEY_4:
                {
                    key[ALLEGRO_KEY_4]=true;
                    break;
                }
                case ALLEGRO_KEY_5:
                {
                    key[ALLEGRO_KEY_5]=true;
                    break;
                }
                case ALLEGRO_KEY_6:
                {
                    key[ALLEGRO_KEY_6]=true;
                    break;
                }
                case ALLEGRO_KEY_7:
                {
                    key[ALLEGRO_KEY_7]=true;
                    break;
                }
                case ALLEGRO_KEY_8:
                {
                    key[ALLEGRO_KEY_8]=true;
                    break;
                }
                case ALLEGRO_KEY_9:
                {
                    key[ALLEGRO_KEY_9]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_0:
                {
                    key[ALLEGRO_KEY_PAD_0]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_1:
                {
                    key[ALLEGRO_KEY_PAD_1]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_2:
                {
                    key[ALLEGRO_KEY_PAD_2]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_3:
                {
                    key[ALLEGRO_KEY_PAD_3]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_4:
                {
                    key[ALLEGRO_KEY_PAD_4]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_5:
                {
                    key[ALLEGRO_KEY_PAD_5]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_6:
                {
                    key[ALLEGRO_KEY_PAD_6]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_7:
                {
                    key[ALLEGRO_KEY_PAD_7]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_8:
                {
                    key[ALLEGRO_KEY_PAD_8]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_9:
                {
                    key[ALLEGRO_KEY_PAD_9]=true;
                    break;
                }
                case ALLEGRO_KEY_F1:
                {
                    key[ALLEGRO_KEY_F1]=true;
                    break;
                }
                case ALLEGRO_KEY_F2:
                {
                    key[ALLEGRO_KEY_F2]=true;
                    break;
                }
                case ALLEGRO_KEY_F3:
                {
                    key[ALLEGRO_KEY_F3]=true;
                    break;
                }
                case ALLEGRO_KEY_F4:
                {
                    key[ALLEGRO_KEY_F4]=true;
                    break;
                }
                case ALLEGRO_KEY_F5:
                {
                    key[ALLEGRO_KEY_F5]=true;
                    break;
                }
                case ALLEGRO_KEY_F6:
                {
                    key[ALLEGRO_KEY_F6]=true;
                    break;
                }
                case ALLEGRO_KEY_F7:
                {
                    key[ALLEGRO_KEY_F7]=true;
                    break;
                }
                case ALLEGRO_KEY_F8:
                {
                    key[ALLEGRO_KEY_F8]=true;
                    break;
                }
                case ALLEGRO_KEY_F9:
                {
                    key[ALLEGRO_KEY_F9]=true;
                    break;
                }
                case ALLEGRO_KEY_F10:
                {
                    key[ALLEGRO_KEY_F10]=true;
                    break;
                }
                case ALLEGRO_KEY_F11:
                {
                    key[ALLEGRO_KEY_F11]=true;
                    break;
                }
                case ALLEGRO_KEY_F12:
                {
                    key[ALLEGRO_KEY_F12]=true;
                    break;
                }
                case ALLEGRO_KEY_ESCAPE:
                {
                    key[ALLEGRO_KEY_ESCAPE]=true;
                    break;
                }
                case ALLEGRO_KEY_TILDE:
                {
                    key[ALLEGRO_KEY_TILDE]=true;
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    key[ALLEGRO_KEY_MINUS]=true;
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    key[ALLEGRO_KEY_EQUALS]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSPACE:
                {
                    key[ALLEGRO_KEY_BACKSPACE]=true;
                    break;
                }
                case ALLEGRO_KEY_TAB:
                {
                    key[ALLEGRO_KEY_TAB]=true;
                    break;
                }
                case ALLEGRO_KEY_OPENBRACE:
                {
                    key[ALLEGRO_KEY_OPENBRACE]=true;
                    break;
                }
                case ALLEGRO_KEY_CLOSEBRACE:
                {
                    key[ALLEGRO_KEY_CLOSEBRACE]=true;
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    key[ALLEGRO_KEY_ENTER]=true;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON:
                {
                    key[ALLEGRO_KEY_SEMICOLON]=true;
                    break;
                }
                case ALLEGRO_KEY_QUOTE:
                {
                    key[ALLEGRO_KEY_QUOTE]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH:
                {
                    key[ALLEGRO_KEY_BACKSLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH2:
                {
                    key[ALLEGRO_KEY_BACKSLASH2]=true;
                    break;
                }
                case ALLEGRO_KEY_COMMA:
                {
                    key[ALLEGRO_KEY_COMMA]=true;
                    break;
                }
                case ALLEGRO_KEY_FULLSTOP:
                {
                    key[ALLEGRO_KEY_FULLSTOP]=true;
                    break;
                }
                case ALLEGRO_KEY_SLASH:
                {
                    key[ALLEGRO_KEY_SLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_SPACE:
                {
                    key[ALLEGRO_KEY_SPACE]=true;
                    break;
                }
                case ALLEGRO_KEY_INSERT:
                {
                    key[ALLEGRO_KEY_INSERT]=true;
                    break;
                }
                case ALLEGRO_KEY_DELETE:
                {
                    key[ALLEGRO_KEY_DELETE]=true;
                    break;
                }
                case ALLEGRO_KEY_HOME:
                {
                    key[ALLEGRO_KEY_HOME]=true;
                    break;
                }
                case ALLEGRO_KEY_END:
                {
                    key[ALLEGRO_KEY_END]=true;
                    break;
                }
                case ALLEGRO_KEY_PGUP:
                {
                    key[ALLEGRO_KEY_PGUP]=true;
                    break;
                }
                case ALLEGRO_KEY_PGDN:
                {
                    key[ALLEGRO_KEY_PGDN]=true;
                    break;
                }
                case ALLEGRO_KEY_LEFT:
                {
                    key[ALLEGRO_KEY_LEFT]=true;
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    key[ALLEGRO_KEY_RIGHT]=true;
                    break;
                }
                case ALLEGRO_KEY_UP:
                {
                    key[ALLEGRO_KEY_UP]=true;
                    break;
                }
                case ALLEGRO_KEY_DOWN:
                {
                    key[ALLEGRO_KEY_DOWN]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_SLASH:
                {
                    key[ALLEGRO_KEY_PAD_SLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_ASTERISK:
                {
                    key[ALLEGRO_KEY_PAD_ASTERISK]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_MINUS:
                {
                    key[ALLEGRO_KEY_PAD_MINUS]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_PLUS:
                {
                    key[ALLEGRO_KEY_PAD_PLUS]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_DELETE:
                {
                    key[ALLEGRO_KEY_PAD_DELETE]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_ENTER:
                {
                    key[ALLEGRO_KEY_PAD_ENTER]=true;
                    break;
                }
                case ALLEGRO_KEY_PRINTSCREEN:
                {
                    key[ALLEGRO_KEY_PRINTSCREEN]=true;
                    break;
                }
                case ALLEGRO_KEY_PAUSE:
                {
                    key[ALLEGRO_KEY_PAUSE]=true;
                    break;
                }
                case ALLEGRO_KEY_ABNT_C1:
                {
                    key[ALLEGRO_KEY_ABNT_C1]=true;
                    break;
                }
                case ALLEGRO_KEY_YEN:
                {
                    key[ALLEGRO_KEY_YEN]=true;
                    break;
                }
                case ALLEGRO_KEY_KANA:
                {
                    key[ALLEGRO_KEY_KANA]=true;
                    break;
                }
                case ALLEGRO_KEY_CONVERT:
                {
                    key[ALLEGRO_KEY_CONVERT]=true;
                    break;
                }
                case ALLEGRO_KEY_NOCONVERT:
                {
                    key[ALLEGRO_KEY_NOCONVERT]=true;
                    break;
                }
                case ALLEGRO_KEY_AT:
                {
                    key[ALLEGRO_KEY_AT]=true;
                    break;
                }
                case ALLEGRO_KEY_CIRCUMFLEX:
                {
                    key[ALLEGRO_KEY_CIRCUMFLEX]=true;
                    break;
                }
                case ALLEGRO_KEY_COLON2:
                {
                    key[ALLEGRO_KEY_COLON2]=true;
                    break;
                }
                case ALLEGRO_KEY_KANJI:
                {
                    key[ALLEGRO_KEY_KANJI]=true;
                    break;
                }
                case ALLEGRO_KEY_LSHIFT:
                {
                    key[ALLEGRO_KEY_LSHIFT]=true;
                    break;
                }
                case ALLEGRO_KEY_RSHIFT:
                {
                    key[ALLEGRO_KEY_RSHIFT]=true;
                    break;
                }
                case ALLEGRO_KEY_LCTRL:
                {
                    key[ALLEGRO_KEY_LCTRL]=true;
                    break;
                }
                case ALLEGRO_KEY_RCTRL:
                {
                    key[ALLEGRO_KEY_RCTRL]=true;
                    break;
                }
                case ALLEGRO_KEY_ALT:
                {
                    key[ALLEGRO_KEY_ALT]=true;
                    break;
                }
                case ALLEGRO_KEY_ALTGR:
                {
                    key[ALLEGRO_KEY_ALTGR]=true;
                    break;
                }
                case ALLEGRO_KEY_LWIN:
                {
                    key[ALLEGRO_KEY_LWIN]=true;
                    break;
                }
                case ALLEGRO_KEY_RWIN:
                {
                    key[ALLEGRO_KEY_RWIN]=true;
                    break;
                }
                case ALLEGRO_KEY_MENU:
                {
                    key[ALLEGRO_KEY_MENU]=true;
                    break;
                }
                case ALLEGRO_KEY_SCROLLLOCK:
                {
                    key[ALLEGRO_KEY_SCROLLLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_NUMLOCK:
                {
                    key[ALLEGRO_KEY_NUMLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_CAPSLOCK:
                {
                    key[ALLEGRO_KEY_CAPSLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_EQUALS:
                {
                    key[ALLEGRO_KEY_PAD_EQUALS]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKQUOTE:
                {
                    key[ALLEGRO_KEY_BACKQUOTE]=true;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON2:
                {
                    key[ALLEGRO_KEY_SEMICOLON2]=true;
                    break;
                }
                case ALLEGRO_KEY_COMMAND:
                {
                    key[ALLEGRO_KEY_COMMAND]=true;
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_UP:
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_A:
                {
                    key[ALLEGRO_KEY_A]=false;
                    break;
                }
                case ALLEGRO_KEY_B:
                {
                    key[ALLEGRO_KEY_B]=false;
                    break;
                }
                case ALLEGRO_KEY_C:
                {
                    key[ALLEGRO_KEY_C]=false;
                    break;
                }
                case ALLEGRO_KEY_D:
                {
                    key[ALLEGRO_KEY_D]=false;
                    break;
                }
                case ALLEGRO_KEY_E:
                {
                    key[ALLEGRO_KEY_E]=false;
                    break;
                }
                case ALLEGRO_KEY_F:
                {
                    key[ALLEGRO_KEY_F]=false;
                    break;
                }
                case ALLEGRO_KEY_G:
                {
                    key[ALLEGRO_KEY_G]=false;
                    break;
                }
                case ALLEGRO_KEY_H:
                {
                    key[ALLEGRO_KEY_H]=false;
                    break;
                }
                case ALLEGRO_KEY_I:
                {
                    key[ALLEGRO_KEY_I]=false;
                    break;
                }
                case ALLEGRO_KEY_J:
                {
                    key[ALLEGRO_KEY_J]=false;
                    break;
                }
                case ALLEGRO_KEY_K:
                {
                    key[ALLEGRO_KEY_K]=false;
                    break;
                }
                case ALLEGRO_KEY_L:
                {
                    key[ALLEGRO_KEY_L]=false;
                    break;
                }
                case ALLEGRO_KEY_M:
                {
                    key[ALLEGRO_KEY_M]=false;
                    break;
                }
                case ALLEGRO_KEY_N:
                {
                    key[ALLEGRO_KEY_N]=false;
                    break;
                }
                case ALLEGRO_KEY_O:
                {
                    key[ALLEGRO_KEY_O]=false;
                    break;
                }
                case ALLEGRO_KEY_P:
                {
                    key[ALLEGRO_KEY_P]=false;
                    break;
                }
                case ALLEGRO_KEY_Q:
                {
                    key[ALLEGRO_KEY_Q]=false;
                    break;
                }
                case ALLEGRO_KEY_R:
                {
                    key[ALLEGRO_KEY_R]=false;
                    break;
                }
                case ALLEGRO_KEY_S:
                {
                    key[ALLEGRO_KEY_S]=false;
                    break;
                }
                case ALLEGRO_KEY_T:
                {
                    key[ALLEGRO_KEY_T]=false;
                    break;
                }
                case ALLEGRO_KEY_U:
                {
                    key[ALLEGRO_KEY_U]=false;
                    break;
                }
                case ALLEGRO_KEY_V:
                {
                    key[ALLEGRO_KEY_V]=false;
                    break;
                }
                case ALLEGRO_KEY_W:
                {
                    key[ALLEGRO_KEY_W]=false;
                    break;
                }
                case ALLEGRO_KEY_X:
                {
                    key[ALLEGRO_KEY_X]=false;
                    break;
                }
                case ALLEGRO_KEY_Y:
                {
                    key[ALLEGRO_KEY_Y]=false;
                    break;
                }
                case ALLEGRO_KEY_Z:
                {
                    key[ALLEGRO_KEY_Z]=false;
                    break;
                }
                case ALLEGRO_KEY_0:
                {
                    key[ALLEGRO_KEY_0]=false;
                    break;
                }
                case ALLEGRO_KEY_1:
                {
                    key[ALLEGRO_KEY_1]=false;
                    break;
                }
                case ALLEGRO_KEY_2:
                {
                    key[ALLEGRO_KEY_2]=false;
                    break;
                }
                case ALLEGRO_KEY_3:
                {
                    key[ALLEGRO_KEY_3]=false;
                    break;
                }
                case ALLEGRO_KEY_4:
                {
                    key[ALLEGRO_KEY_4]=false;
                    break;
                }
                case ALLEGRO_KEY_5:
                {
                    key[ALLEGRO_KEY_5]=false;
                    break;
                }
                case ALLEGRO_KEY_6:
                {
                    key[ALLEGRO_KEY_6]=false;
                    break;
                }
                case ALLEGRO_KEY_7:
                {
                    key[ALLEGRO_KEY_7]=false;
                    break;
                }
                case ALLEGRO_KEY_8:
                {
                    key[ALLEGRO_KEY_8]=false;
                    break;
                }
                case ALLEGRO_KEY_9:
                {
                    key[ALLEGRO_KEY_9]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_0:
                {
                    key[ALLEGRO_KEY_PAD_0]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_1:
                {
                    key[ALLEGRO_KEY_PAD_1]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_2:
                {
                    key[ALLEGRO_KEY_PAD_2]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_3:
                {
                    key[ALLEGRO_KEY_PAD_3]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_4:
                {
                    key[ALLEGRO_KEY_PAD_4]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_5:
                {
                    key[ALLEGRO_KEY_PAD_5]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_6:
                {
                    key[ALLEGRO_KEY_PAD_6]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_7:
                {
                    key[ALLEGRO_KEY_PAD_7]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_8:
                {
                    key[ALLEGRO_KEY_PAD_8]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_9:
                {
                    key[ALLEGRO_KEY_PAD_9]=false;
                    break;
                }
                case ALLEGRO_KEY_F1:
                {
                    key[ALLEGRO_KEY_F1]=false;
                    break;
                }
                case ALLEGRO_KEY_F2:
                {
                    key[ALLEGRO_KEY_F2]=false;
                    break;
                }
                case ALLEGRO_KEY_F3:
                {
                    key[ALLEGRO_KEY_F3]=false;
                    break;
                }
                case ALLEGRO_KEY_F4:
                {
                    key[ALLEGRO_KEY_F4]=false;
                    break;
                }
                case ALLEGRO_KEY_F5:
                {
                    key[ALLEGRO_KEY_F5]=false;
                    break;
                }
                case ALLEGRO_KEY_F6:
                {
                    key[ALLEGRO_KEY_F6]=false;
                    break;
                }
                case ALLEGRO_KEY_F7:
                {
                    key[ALLEGRO_KEY_F7]=false;
                    break;
                }
                case ALLEGRO_KEY_F8:
                {
                    key[ALLEGRO_KEY_F8]=false;
                    break;
                }
                case ALLEGRO_KEY_F9:
                {
                    key[ALLEGRO_KEY_F9]=false;
                    break;
                }
                case ALLEGRO_KEY_F10:
                {
                    key[ALLEGRO_KEY_F10]=false;
                    break;
                }
                case ALLEGRO_KEY_F11:
                {
                    key[ALLEGRO_KEY_F11]=false;
                    break;
                }
                case ALLEGRO_KEY_F12:
                {
                    key[ALLEGRO_KEY_F12]=false;
                    break;
                }
                case ALLEGRO_KEY_ESCAPE:
                {
                    key[ALLEGRO_KEY_ESCAPE]=false;
                    break;
                }
                case ALLEGRO_KEY_TILDE:
                {
                    key[ALLEGRO_KEY_TILDE]=false;
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    key[ALLEGRO_KEY_MINUS]=false;
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    key[ALLEGRO_KEY_EQUALS]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSPACE:
                {
                    key[ALLEGRO_KEY_BACKSPACE]=false;
                    break;
                }
                case ALLEGRO_KEY_TAB:
                {
                    key[ALLEGRO_KEY_TAB]=false;
                    break;
                }
                case ALLEGRO_KEY_OPENBRACE:
                {
                    key[ALLEGRO_KEY_OPENBRACE]=false;
                    break;
                }
                case ALLEGRO_KEY_CLOSEBRACE:
                {
                    key[ALLEGRO_KEY_CLOSEBRACE]=false;
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    key[ALLEGRO_KEY_ENTER]=false;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON:
                {
                    key[ALLEGRO_KEY_SEMICOLON]=false;
                    break;
                }
                case ALLEGRO_KEY_QUOTE:
                {
                    key[ALLEGRO_KEY_QUOTE]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH:
                {
                    key[ALLEGRO_KEY_BACKSLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH2:
                {
                    key[ALLEGRO_KEY_BACKSLASH2]=false;
                    break;
                }
                case ALLEGRO_KEY_COMMA:
                {
                    key[ALLEGRO_KEY_COMMA]=false;
                    break;
                }
                case ALLEGRO_KEY_FULLSTOP:
                {
                    key[ALLEGRO_KEY_FULLSTOP]=false;
                    break;
                }
                case ALLEGRO_KEY_SLASH:
                {
                    key[ALLEGRO_KEY_SLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_SPACE:
                {
                    key[ALLEGRO_KEY_SPACE]=false;
                    break;
                }
                case ALLEGRO_KEY_INSERT:
                {
                    key[ALLEGRO_KEY_INSERT]=false;
                    break;
                }
                case ALLEGRO_KEY_DELETE:
                {
                    key[ALLEGRO_KEY_DELETE]=false;
                    break;
                }
                case ALLEGRO_KEY_HOME:
                {
                    key[ALLEGRO_KEY_HOME]=false;
                    break;
                }
                case ALLEGRO_KEY_END:
                {
                    key[ALLEGRO_KEY_END]=false;
                    break;
                }
                case ALLEGRO_KEY_PGUP:
                {
                    key[ALLEGRO_KEY_PGUP]=false;
                    break;
                }
                case ALLEGRO_KEY_PGDN:
                {
                    key[ALLEGRO_KEY_PGDN]=false;
                    break;
                }
                case ALLEGRO_KEY_LEFT:
                {
                    key[ALLEGRO_KEY_LEFT]=false;
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    key[ALLEGRO_KEY_RIGHT]=false;
                    break;
                }
                case ALLEGRO_KEY_UP:
                {
                    key[ALLEGRO_KEY_UP]=false;
                    break;
                }
                case ALLEGRO_KEY_DOWN:
                {
                    key[ALLEGRO_KEY_DOWN]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_SLASH:
                {
                    key[ALLEGRO_KEY_PAD_SLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_ASTERISK:
                {
                    key[ALLEGRO_KEY_PAD_ASTERISK]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_MINUS:
                {
                    key[ALLEGRO_KEY_PAD_MINUS]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_PLUS:
                {
                    key[ALLEGRO_KEY_PAD_PLUS]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_DELETE:
                {
                    key[ALLEGRO_KEY_PAD_DELETE]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_ENTER:
                {
                    key[ALLEGRO_KEY_PAD_ENTER]=false;
                    break;
                }
                case ALLEGRO_KEY_PRINTSCREEN:
                {
                    key[ALLEGRO_KEY_PRINTSCREEN]=false;
                    break;
                }
                case ALLEGRO_KEY_PAUSE:
                {
                    key[ALLEGRO_KEY_PAUSE]=false;
                    break;
                }
                case ALLEGRO_KEY_ABNT_C1:
                {
                    key[ALLEGRO_KEY_ABNT_C1]=false;
                    break;
                }
                case ALLEGRO_KEY_YEN:
                {
                    key[ALLEGRO_KEY_YEN]=false;
                    break;
                }
                case ALLEGRO_KEY_KANA:
                {
                    key[ALLEGRO_KEY_KANA]=false;
                    break;
                }
                case ALLEGRO_KEY_CONVERT:
                {
                    key[ALLEGRO_KEY_CONVERT]=false;
                    break;
                }
                case ALLEGRO_KEY_NOCONVERT:
                {
                    key[ALLEGRO_KEY_NOCONVERT]=false;
                    break;
                }
                case ALLEGRO_KEY_AT:
                {
                    key[ALLEGRO_KEY_AT]=false;
                    break;
                }
                case ALLEGRO_KEY_CIRCUMFLEX:
                {
                    key[ALLEGRO_KEY_CIRCUMFLEX]=false;
                    break;
                }
                case ALLEGRO_KEY_COLON2:
                {
                    key[ALLEGRO_KEY_COLON2]=false;
                    break;
                }
                case ALLEGRO_KEY_KANJI:
                {
                    key[ALLEGRO_KEY_KANJI]=false;
                    break;
                }
                case ALLEGRO_KEY_LSHIFT:
                {
                    key[ALLEGRO_KEY_LSHIFT]=false;
                    break;
                }
                case ALLEGRO_KEY_RSHIFT:
                {
                    key[ALLEGRO_KEY_RSHIFT]=false;
                    break;
                }
                case ALLEGRO_KEY_LCTRL:
                {
                    key[ALLEGRO_KEY_LCTRL]=false;
                    break;
                }
                case ALLEGRO_KEY_RCTRL:
                {
                    key[ALLEGRO_KEY_RCTRL]=false;
                    break;
                }
                case ALLEGRO_KEY_ALT:
                {
                    key[ALLEGRO_KEY_ALT]=false;
                    break;
                }
                case ALLEGRO_KEY_ALTGR:
                {
                    key[ALLEGRO_KEY_ALTGR]=false;
                    break;
                }
                case ALLEGRO_KEY_LWIN:
                {
                    key[ALLEGRO_KEY_LWIN]=false;
                    break;
                }
                case ALLEGRO_KEY_RWIN:
                {
                    key[ALLEGRO_KEY_RWIN]=false;
                    break;
                }
                case ALLEGRO_KEY_MENU:
                {
                    key[ALLEGRO_KEY_MENU]=false;
                    break;
                }
                case ALLEGRO_KEY_SCROLLLOCK:
                {
                    key[ALLEGRO_KEY_SCROLLLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_NUMLOCK:
                {
                    key[ALLEGRO_KEY_NUMLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_CAPSLOCK:
                {
                    key[ALLEGRO_KEY_CAPSLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_EQUALS:
                {
                    key[ALLEGRO_KEY_PAD_EQUALS]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKQUOTE:
                {
                    key[ALLEGRO_KEY_BACKQUOTE]=false;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON2:
                {
                    key[ALLEGRO_KEY_SEMICOLON2]=false;
                    break;
                }
                case ALLEGRO_KEY_COMMAND:
                {
                    key[ALLEGRO_KEY_COMMAND]=false;
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_CHAR:
            {
                if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                {
                    valid=false;
                    break;
                }
                /*
                int unichar=ev.keyboard.unichar;
                if(unichar>=32)
                {
                    getChatlog()->insertChar(unichar);
                }
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_LEFT:
                {
                    if(chatlog->visible)
                    {
                        chatlog->posLeft();
                    }
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    if(chatlog->visible)
                    {
                        chatlog->posRight();
                    }
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_CTRL)
                    {
                        chatlog->retreat();
                    }
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_CTRL)
                    {
                        chatlog->advance();
                    }
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_SHIFT)
                    {
                        chatlog->visible=false;
                    }
                    else
                    {
                        if(getChatlog()->visible)
                        {
                            if(al_ustr_length(input))
                            {
                                getChatlog()->insert("Player "+intToStr(player->getTeamID()), al_cstr(input), AL_COL_WHITE, CMSG_USERNAME, 0);
                                al_ustr_truncate(input, 0);
                            }
                            else
                            {
                                chatlog->visible=false;
                            }
                        }
                        else
                        {
                            chatlog->visible=true;
                        }
                    }
                    break;
                }
                }
                */
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            {
                if(region.contains(ev.mouse.x, ev.mouse.y))
                {
                    switch(ev.mouse.button)
                    {
                    case 1:
                    {
                        //Left Click
                        mouse[MOUSEBUTTON::LEFT]=true;
                        onLeftClick();
                        break;
                    }
                    case 2:
                    {
                        mouse[MOUSEBUTTON::RIGHT]=true;
                        camera->setMouseX(ev.mouse.x);
                        camera->setMouseY(ev.mouse.y);
                        break;
                    }
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            {
                switch(ev.mouse.button)
                {
                case 1:
                {
                    mouse[MOUSEBUTTON::LEFT]=false;
                    onLeftUp();
                    break;
                }
                case 2:
                {
                    mouse[MOUSEBUTTON::RIGHT]=false;
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:
            {
                for(auto &it : buttons)
                {
                    it->hover=(it->contains(ev.mouse.x, ev.mouse.y));
                }
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            {
                std::fill(key.begin(), key.end(), false);
                for(auto &it : mouse)
                {
                    it.second=false;
                }
                for(auto &it : buttons)
                {
                    it->hover=false;
                }
                break;
            }
            }
        }
        break;
    }
    case FRAMETYPE::STAGE:
    {
        world.Step(1.0/60.0, 8, 3);
        for(ALLEGRO_EVENT ev; valid && al_get_next_event(event_queue, &ev);)
        {
            switch(ev.type)
            {
            case ALLEGRO_EVENT_TIMER:
            {
                sysEvents[EVENTTYPE::TIMER].fire();
                for(auto &it : observers)
                {
                    it->onTimerKeyState(key);
                }
                /*
                if(key[ALLEGRO_KEY_UP])
                {
                    camera->setY(camera->getY()+8);
                }
                if(key[ALLEGRO_KEY_DOWN])
                {
                    camera->setY(camera->getY()-8);
                }
                if(key[ALLEGRO_KEY_LEFT])
                {
                    camera->setX(camera->getX()+8);
                }
                if(key[ALLEGRO_KEY_RIGHT])
                {
                    camera->setX(camera->getX()-8);
                }
                */
                if(mouse[MOUSEBUTTON::RIGHT])
                {
                    al_get_mouse_state(&cursorState);
                    camera->moveMouse(cursorState.x, cursorState.y);
                }
                invalidate();
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            {
                valid=false;
                return;
            }
            case ALLEGRO_EVENT_KEY_DOWN:
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_A:
                {
                    key[ALLEGRO_KEY_A]=true;
                    break;
                }
                case ALLEGRO_KEY_B:
                {
                    key[ALLEGRO_KEY_B]=true;
                    break;
                }
                case ALLEGRO_KEY_C:
                {
                    key[ALLEGRO_KEY_C]=true;
                    break;
                }
                case ALLEGRO_KEY_D:
                {
                    key[ALLEGRO_KEY_D]=true;
                    break;
                }
                case ALLEGRO_KEY_E:
                {
                    key[ALLEGRO_KEY_E]=true;
                    break;
                }
                case ALLEGRO_KEY_F:
                {
                    key[ALLEGRO_KEY_F]=true;
                    break;
                }
                case ALLEGRO_KEY_G:
                {
                    key[ALLEGRO_KEY_G]=true;
                    break;
                }
                case ALLEGRO_KEY_H:
                {
                    key[ALLEGRO_KEY_H]=true;
                    break;
                }
                case ALLEGRO_KEY_I:
                {
                    key[ALLEGRO_KEY_I]=true;
                    break;
                }
                case ALLEGRO_KEY_J:
                {
                    key[ALLEGRO_KEY_J]=true;
                    break;
                }
                case ALLEGRO_KEY_K:
                {
                    key[ALLEGRO_KEY_K]=true;
                    break;
                }
                case ALLEGRO_KEY_L:
                {
                    key[ALLEGRO_KEY_L]=true;
                    break;
                }
                case ALLEGRO_KEY_M:
                {
                    key[ALLEGRO_KEY_M]=true;
                    break;
                }
                case ALLEGRO_KEY_N:
                {
                    key[ALLEGRO_KEY_N]=true;
                    break;
                }
                case ALLEGRO_KEY_O:
                {
                    key[ALLEGRO_KEY_O]=true;
                    break;
                }
                case ALLEGRO_KEY_P:
                {
                    key[ALLEGRO_KEY_P]=true;
                    break;
                }
                case ALLEGRO_KEY_Q:
                {
                    key[ALLEGRO_KEY_Q]=true;
                    break;
                }
                case ALLEGRO_KEY_R:
                {
                    key[ALLEGRO_KEY_R]=true;
                    break;
                }
                case ALLEGRO_KEY_S:
                {
                    key[ALLEGRO_KEY_S]=true;
                    break;
                }
                case ALLEGRO_KEY_T:
                {
                    key[ALLEGRO_KEY_T]=true;
                    break;
                }
                case ALLEGRO_KEY_U:
                {
                    key[ALLEGRO_KEY_U]=true;
                    break;
                }
                case ALLEGRO_KEY_V:
                {
                    key[ALLEGRO_KEY_V]=true;
                    break;
                }
                case ALLEGRO_KEY_W:
                {
                    key[ALLEGRO_KEY_W]=true;
                    break;
                }
                case ALLEGRO_KEY_X:
                {
                    key[ALLEGRO_KEY_X]=true;
                    break;
                }
                case ALLEGRO_KEY_Y:
                {
                    key[ALLEGRO_KEY_Y]=true;
                    break;
                }
                case ALLEGRO_KEY_Z:
                {
                    key[ALLEGRO_KEY_Z]=true;
                    break;
                }
                case ALLEGRO_KEY_0:
                {
                    key[ALLEGRO_KEY_0]=true;
                    break;
                }
                case ALLEGRO_KEY_1:
                {
                    key[ALLEGRO_KEY_1]=true;
                    break;
                }
                case ALLEGRO_KEY_2:
                {
                    key[ALLEGRO_KEY_2]=true;
                    break;
                }
                case ALLEGRO_KEY_3:
                {
                    key[ALLEGRO_KEY_3]=true;
                    break;
                }
                case ALLEGRO_KEY_4:
                {
                    key[ALLEGRO_KEY_4]=true;
                    break;
                }
                case ALLEGRO_KEY_5:
                {
                    key[ALLEGRO_KEY_5]=true;
                    break;
                }
                case ALLEGRO_KEY_6:
                {
                    key[ALLEGRO_KEY_6]=true;
                    break;
                }
                case ALLEGRO_KEY_7:
                {
                    key[ALLEGRO_KEY_7]=true;
                    break;
                }
                case ALLEGRO_KEY_8:
                {
                    key[ALLEGRO_KEY_8]=true;
                    break;
                }
                case ALLEGRO_KEY_9:
                {
                    key[ALLEGRO_KEY_9]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_0:
                {
                    key[ALLEGRO_KEY_PAD_0]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_1:
                {
                    key[ALLEGRO_KEY_PAD_1]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_2:
                {
                    key[ALLEGRO_KEY_PAD_2]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_3:
                {
                    key[ALLEGRO_KEY_PAD_3]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_4:
                {
                    key[ALLEGRO_KEY_PAD_4]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_5:
                {
                    key[ALLEGRO_KEY_PAD_5]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_6:
                {
                    key[ALLEGRO_KEY_PAD_6]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_7:
                {
                    key[ALLEGRO_KEY_PAD_7]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_8:
                {
                    key[ALLEGRO_KEY_PAD_8]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_9:
                {
                    key[ALLEGRO_KEY_PAD_9]=true;
                    break;
                }
                case ALLEGRO_KEY_F1:
                {
                    key[ALLEGRO_KEY_F1]=true;
                    break;
                }
                case ALLEGRO_KEY_F2:
                {
                    key[ALLEGRO_KEY_F2]=true;
                    break;
                }
                case ALLEGRO_KEY_F3:
                {
                    key[ALLEGRO_KEY_F3]=true;
                    break;
                }
                case ALLEGRO_KEY_F4:
                {
                    key[ALLEGRO_KEY_F4]=true;
                    break;
                }
                case ALLEGRO_KEY_F5:
                {
                    key[ALLEGRO_KEY_F5]=true;
                    break;
                }
                case ALLEGRO_KEY_F6:
                {
                    key[ALLEGRO_KEY_F6]=true;
                    break;
                }
                case ALLEGRO_KEY_F7:
                {
                    key[ALLEGRO_KEY_F7]=true;
                    break;
                }
                case ALLEGRO_KEY_F8:
                {
                    key[ALLEGRO_KEY_F8]=true;
                    break;
                }
                case ALLEGRO_KEY_F9:
                {
                    key[ALLEGRO_KEY_F9]=true;
                    break;
                }
                case ALLEGRO_KEY_F10:
                {
                    key[ALLEGRO_KEY_F10]=true;
                    break;
                }
                case ALLEGRO_KEY_F11:
                {
                    key[ALLEGRO_KEY_F11]=true;
                    break;
                }
                case ALLEGRO_KEY_F12:
                {
                    key[ALLEGRO_KEY_F12]=true;
                    break;
                }
                case ALLEGRO_KEY_ESCAPE:
                {
                    key[ALLEGRO_KEY_ESCAPE]=true;
                    break;
                }
                case ALLEGRO_KEY_TILDE:
                {
                    key[ALLEGRO_KEY_TILDE]=true;
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    key[ALLEGRO_KEY_MINUS]=true;
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    key[ALLEGRO_KEY_EQUALS]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSPACE:
                {
                    key[ALLEGRO_KEY_BACKSPACE]=true;
                    break;
                }
                case ALLEGRO_KEY_TAB:
                {
                    key[ALLEGRO_KEY_TAB]=true;
                    break;
                }
                case ALLEGRO_KEY_OPENBRACE:
                {
                    key[ALLEGRO_KEY_OPENBRACE]=true;
                    break;
                }
                case ALLEGRO_KEY_CLOSEBRACE:
                {
                    key[ALLEGRO_KEY_CLOSEBRACE]=true;
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    key[ALLEGRO_KEY_ENTER]=true;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON:
                {
                    key[ALLEGRO_KEY_SEMICOLON]=true;
                    break;
                }
                case ALLEGRO_KEY_QUOTE:
                {
                    key[ALLEGRO_KEY_QUOTE]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH:
                {
                    key[ALLEGRO_KEY_BACKSLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH2:
                {
                    key[ALLEGRO_KEY_BACKSLASH2]=true;
                    break;
                }
                case ALLEGRO_KEY_COMMA:
                {
                    key[ALLEGRO_KEY_COMMA]=true;
                    break;
                }
                case ALLEGRO_KEY_FULLSTOP:
                {
                    key[ALLEGRO_KEY_FULLSTOP]=true;
                    break;
                }
                case ALLEGRO_KEY_SLASH:
                {
                    key[ALLEGRO_KEY_SLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_SPACE:
                {
                    key[ALLEGRO_KEY_SPACE]=true;
                    break;
                }
                case ALLEGRO_KEY_INSERT:
                {
                    key[ALLEGRO_KEY_INSERT]=true;
                    break;
                }
                case ALLEGRO_KEY_DELETE:
                {
                    key[ALLEGRO_KEY_DELETE]=true;
                    break;
                }
                case ALLEGRO_KEY_HOME:
                {
                    key[ALLEGRO_KEY_HOME]=true;
                    break;
                }
                case ALLEGRO_KEY_END:
                {
                    key[ALLEGRO_KEY_END]=true;
                    break;
                }
                case ALLEGRO_KEY_PGUP:
                {
                    key[ALLEGRO_KEY_PGUP]=true;
                    break;
                }
                case ALLEGRO_KEY_PGDN:
                {
                    key[ALLEGRO_KEY_PGDN]=true;
                    break;
                }
                case ALLEGRO_KEY_LEFT:
                {
                    key[ALLEGRO_KEY_LEFT]=true;
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    key[ALLEGRO_KEY_RIGHT]=true;
                    break;
                }
                case ALLEGRO_KEY_UP:
                {
                    key[ALLEGRO_KEY_UP]=true;
                    break;
                }
                case ALLEGRO_KEY_DOWN:
                {
                    key[ALLEGRO_KEY_DOWN]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_SLASH:
                {
                    key[ALLEGRO_KEY_PAD_SLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_ASTERISK:
                {
                    key[ALLEGRO_KEY_PAD_ASTERISK]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_MINUS:
                {
                    key[ALLEGRO_KEY_PAD_MINUS]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_PLUS:
                {
                    key[ALLEGRO_KEY_PAD_PLUS]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_DELETE:
                {
                    key[ALLEGRO_KEY_PAD_DELETE]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_ENTER:
                {
                    key[ALLEGRO_KEY_PAD_ENTER]=true;
                    break;
                }
                case ALLEGRO_KEY_PRINTSCREEN:
                {
                    key[ALLEGRO_KEY_PRINTSCREEN]=true;
                    break;
                }
                case ALLEGRO_KEY_PAUSE:
                {
                    key[ALLEGRO_KEY_PAUSE]=true;
                    break;
                }
                case ALLEGRO_KEY_ABNT_C1:
                {
                    key[ALLEGRO_KEY_ABNT_C1]=true;
                    break;
                }
                case ALLEGRO_KEY_YEN:
                {
                    key[ALLEGRO_KEY_YEN]=true;
                    break;
                }
                case ALLEGRO_KEY_KANA:
                {
                    key[ALLEGRO_KEY_KANA]=true;
                    break;
                }
                case ALLEGRO_KEY_CONVERT:
                {
                    key[ALLEGRO_KEY_CONVERT]=true;
                    break;
                }
                case ALLEGRO_KEY_NOCONVERT:
                {
                    key[ALLEGRO_KEY_NOCONVERT]=true;
                    break;
                }
                case ALLEGRO_KEY_AT:
                {
                    key[ALLEGRO_KEY_AT]=true;
                    break;
                }
                case ALLEGRO_KEY_CIRCUMFLEX:
                {
                    key[ALLEGRO_KEY_CIRCUMFLEX]=true;
                    break;
                }
                case ALLEGRO_KEY_COLON2:
                {
                    key[ALLEGRO_KEY_COLON2]=true;
                    break;
                }
                case ALLEGRO_KEY_KANJI:
                {
                    key[ALLEGRO_KEY_KANJI]=true;
                    break;
                }
                case ALLEGRO_KEY_LSHIFT:
                {
                    key[ALLEGRO_KEY_LSHIFT]=true;
                    break;
                }
                case ALLEGRO_KEY_RSHIFT:
                {
                    key[ALLEGRO_KEY_RSHIFT]=true;
                    break;
                }
                case ALLEGRO_KEY_LCTRL:
                {
                    key[ALLEGRO_KEY_LCTRL]=true;
                    break;
                }
                case ALLEGRO_KEY_RCTRL:
                {
                    key[ALLEGRO_KEY_RCTRL]=true;
                    break;
                }
                case ALLEGRO_KEY_ALT:
                {
                    key[ALLEGRO_KEY_ALT]=true;
                    break;
                }
                case ALLEGRO_KEY_ALTGR:
                {
                    key[ALLEGRO_KEY_ALTGR]=true;
                    break;
                }
                case ALLEGRO_KEY_LWIN:
                {
                    key[ALLEGRO_KEY_LWIN]=true;
                    break;
                }
                case ALLEGRO_KEY_RWIN:
                {
                    key[ALLEGRO_KEY_RWIN]=true;
                    break;
                }
                case ALLEGRO_KEY_MENU:
                {
                    key[ALLEGRO_KEY_MENU]=true;
                    break;
                }
                case ALLEGRO_KEY_SCROLLLOCK:
                {
                    key[ALLEGRO_KEY_SCROLLLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_NUMLOCK:
                {
                    key[ALLEGRO_KEY_NUMLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_CAPSLOCK:
                {
                    key[ALLEGRO_KEY_CAPSLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_EQUALS:
                {
                    key[ALLEGRO_KEY_PAD_EQUALS]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKQUOTE:
                {
                    key[ALLEGRO_KEY_BACKQUOTE]=true;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON2:
                {
                    key[ALLEGRO_KEY_SEMICOLON2]=true;
                    break;
                }
                case ALLEGRO_KEY_COMMAND:
                {
                    key[ALLEGRO_KEY_COMMAND]=true;
                    break;
                }
                }
                for(auto &it : observers)
                {
                    it->onKeyPress(ev.keyboard.unichar, ev.keyboard.keycode, ev.keyboard.modifiers);
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_UP:
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_A:
                {
                    key[ALLEGRO_KEY_A]=false;
                    break;
                }
                case ALLEGRO_KEY_B:
                {
                    key[ALLEGRO_KEY_B]=false;
                    break;
                }
                case ALLEGRO_KEY_C:
                {
                    key[ALLEGRO_KEY_C]=false;
                    break;
                }
                case ALLEGRO_KEY_D:
                {
                    key[ALLEGRO_KEY_D]=false;
                    break;
                }
                case ALLEGRO_KEY_E:
                {
                    key[ALLEGRO_KEY_E]=false;
                    break;
                }
                case ALLEGRO_KEY_F:
                {
                    key[ALLEGRO_KEY_F]=false;
                    break;
                }
                case ALLEGRO_KEY_G:
                {
                    key[ALLEGRO_KEY_G]=false;
                    break;
                }
                case ALLEGRO_KEY_H:
                {
                    key[ALLEGRO_KEY_H]=false;
                    break;
                }
                case ALLEGRO_KEY_I:
                {
                    key[ALLEGRO_KEY_I]=false;
                    break;
                }
                case ALLEGRO_KEY_J:
                {
                    key[ALLEGRO_KEY_J]=false;
                    break;
                }
                case ALLEGRO_KEY_K:
                {
                    key[ALLEGRO_KEY_K]=false;
                    break;
                }
                case ALLEGRO_KEY_L:
                {
                    key[ALLEGRO_KEY_L]=false;
                    break;
                }
                case ALLEGRO_KEY_M:
                {
                    key[ALLEGRO_KEY_M]=false;
                    break;
                }
                case ALLEGRO_KEY_N:
                {
                    key[ALLEGRO_KEY_N]=false;
                    break;
                }
                case ALLEGRO_KEY_O:
                {
                    key[ALLEGRO_KEY_O]=false;
                    break;
                }
                case ALLEGRO_KEY_P:
                {
                    key[ALLEGRO_KEY_P]=false;
                    break;
                }
                case ALLEGRO_KEY_Q:
                {
                    key[ALLEGRO_KEY_Q]=false;
                    break;
                }
                case ALLEGRO_KEY_R:
                {
                    key[ALLEGRO_KEY_R]=false;
                    break;
                }
                case ALLEGRO_KEY_S:
                {
                    key[ALLEGRO_KEY_S]=false;
                    break;
                }
                case ALLEGRO_KEY_T:
                {
                    key[ALLEGRO_KEY_T]=false;
                    break;
                }
                case ALLEGRO_KEY_U:
                {
                    key[ALLEGRO_KEY_U]=false;
                    break;
                }
                case ALLEGRO_KEY_V:
                {
                    key[ALLEGRO_KEY_V]=false;
                    break;
                }
                case ALLEGRO_KEY_W:
                {
                    key[ALLEGRO_KEY_W]=false;
                    break;
                }
                case ALLEGRO_KEY_X:
                {
                    key[ALLEGRO_KEY_X]=false;
                    break;
                }
                case ALLEGRO_KEY_Y:
                {
                    key[ALLEGRO_KEY_Y]=false;
                    break;
                }
                case ALLEGRO_KEY_Z:
                {
                    key[ALLEGRO_KEY_Z]=false;
                    break;
                }
                case ALLEGRO_KEY_0:
                {
                    key[ALLEGRO_KEY_0]=false;
                    break;
                }
                case ALLEGRO_KEY_1:
                {
                    key[ALLEGRO_KEY_1]=false;
                    break;
                }
                case ALLEGRO_KEY_2:
                {
                    key[ALLEGRO_KEY_2]=false;
                    break;
                }
                case ALLEGRO_KEY_3:
                {
                    key[ALLEGRO_KEY_3]=false;
                    break;
                }
                case ALLEGRO_KEY_4:
                {
                    key[ALLEGRO_KEY_4]=false;
                    break;
                }
                case ALLEGRO_KEY_5:
                {
                    key[ALLEGRO_KEY_5]=false;
                    break;
                }
                case ALLEGRO_KEY_6:
                {
                    key[ALLEGRO_KEY_6]=false;
                    break;
                }
                case ALLEGRO_KEY_7:
                {
                    key[ALLEGRO_KEY_7]=false;
                    break;
                }
                case ALLEGRO_KEY_8:
                {
                    key[ALLEGRO_KEY_8]=false;
                    break;
                }
                case ALLEGRO_KEY_9:
                {
                    key[ALLEGRO_KEY_9]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_0:
                {
                    key[ALLEGRO_KEY_PAD_0]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_1:
                {
                    key[ALLEGRO_KEY_PAD_1]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_2:
                {
                    key[ALLEGRO_KEY_PAD_2]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_3:
                {
                    key[ALLEGRO_KEY_PAD_3]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_4:
                {
                    key[ALLEGRO_KEY_PAD_4]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_5:
                {
                    key[ALLEGRO_KEY_PAD_5]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_6:
                {
                    key[ALLEGRO_KEY_PAD_6]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_7:
                {
                    key[ALLEGRO_KEY_PAD_7]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_8:
                {
                    key[ALLEGRO_KEY_PAD_8]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_9:
                {
                    key[ALLEGRO_KEY_PAD_9]=false;
                    break;
                }
                case ALLEGRO_KEY_F1:
                {
                    key[ALLEGRO_KEY_F1]=false;
                    break;
                }
                case ALLEGRO_KEY_F2:
                {
                    key[ALLEGRO_KEY_F2]=false;
                    break;
                }
                case ALLEGRO_KEY_F3:
                {
                    key[ALLEGRO_KEY_F3]=false;
                    break;
                }
                case ALLEGRO_KEY_F4:
                {
                    key[ALLEGRO_KEY_F4]=false;
                    break;
                }
                case ALLEGRO_KEY_F5:
                {
                    key[ALLEGRO_KEY_F5]=false;
                    break;
                }
                case ALLEGRO_KEY_F6:
                {
                    key[ALLEGRO_KEY_F6]=false;
                    break;
                }
                case ALLEGRO_KEY_F7:
                {
                    key[ALLEGRO_KEY_F7]=false;
                    break;
                }
                case ALLEGRO_KEY_F8:
                {
                    key[ALLEGRO_KEY_F8]=false;
                    break;
                }
                case ALLEGRO_KEY_F9:
                {
                    key[ALLEGRO_KEY_F9]=false;
                    break;
                }
                case ALLEGRO_KEY_F10:
                {
                    key[ALLEGRO_KEY_F10]=false;
                    break;
                }
                case ALLEGRO_KEY_F11:
                {
                    key[ALLEGRO_KEY_F11]=false;
                    break;
                }
                case ALLEGRO_KEY_F12:
                {
                    key[ALLEGRO_KEY_F12]=false;
                    break;
                }
                case ALLEGRO_KEY_ESCAPE:
                {
                    key[ALLEGRO_KEY_ESCAPE]=false;
                    break;
                }
                case ALLEGRO_KEY_TILDE:
                {
                    key[ALLEGRO_KEY_TILDE]=false;
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    key[ALLEGRO_KEY_MINUS]=false;
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    key[ALLEGRO_KEY_EQUALS]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSPACE:
                {
                    key[ALLEGRO_KEY_BACKSPACE]=false;
                    break;
                }
                case ALLEGRO_KEY_TAB:
                {
                    key[ALLEGRO_KEY_TAB]=false;
                    break;
                }
                case ALLEGRO_KEY_OPENBRACE:
                {
                    key[ALLEGRO_KEY_OPENBRACE]=false;
                    break;
                }
                case ALLEGRO_KEY_CLOSEBRACE:
                {
                    key[ALLEGRO_KEY_CLOSEBRACE]=false;
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    key[ALLEGRO_KEY_ENTER]=false;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON:
                {
                    key[ALLEGRO_KEY_SEMICOLON]=false;
                    break;
                }
                case ALLEGRO_KEY_QUOTE:
                {
                    key[ALLEGRO_KEY_QUOTE]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH:
                {
                    key[ALLEGRO_KEY_BACKSLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH2:
                {
                    key[ALLEGRO_KEY_BACKSLASH2]=false;
                    break;
                }
                case ALLEGRO_KEY_COMMA:
                {
                    key[ALLEGRO_KEY_COMMA]=false;
                    break;
                }
                case ALLEGRO_KEY_FULLSTOP:
                {
                    key[ALLEGRO_KEY_FULLSTOP]=false;
                    break;
                }
                case ALLEGRO_KEY_SLASH:
                {
                    key[ALLEGRO_KEY_SLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_SPACE:
                {
                    key[ALLEGRO_KEY_SPACE]=false;
                    break;
                }
                case ALLEGRO_KEY_INSERT:
                {
                    key[ALLEGRO_KEY_INSERT]=false;
                    break;
                }
                case ALLEGRO_KEY_DELETE:
                {
                    key[ALLEGRO_KEY_DELETE]=false;
                    break;
                }
                case ALLEGRO_KEY_HOME:
                {
                    key[ALLEGRO_KEY_HOME]=false;
                    break;
                }
                case ALLEGRO_KEY_END:
                {
                    key[ALLEGRO_KEY_END]=false;
                    break;
                }
                case ALLEGRO_KEY_PGUP:
                {
                    key[ALLEGRO_KEY_PGUP]=false;
                    break;
                }
                case ALLEGRO_KEY_PGDN:
                {
                    key[ALLEGRO_KEY_PGDN]=false;
                    break;
                }
                case ALLEGRO_KEY_LEFT:
                {
                    key[ALLEGRO_KEY_LEFT]=false;
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    key[ALLEGRO_KEY_RIGHT]=false;
                    break;
                }
                case ALLEGRO_KEY_UP:
                {
                    key[ALLEGRO_KEY_UP]=false;
                    break;
                }
                case ALLEGRO_KEY_DOWN:
                {
                    key[ALLEGRO_KEY_DOWN]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_SLASH:
                {
                    key[ALLEGRO_KEY_PAD_SLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_ASTERISK:
                {
                    key[ALLEGRO_KEY_PAD_ASTERISK]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_MINUS:
                {
                    key[ALLEGRO_KEY_PAD_MINUS]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_PLUS:
                {
                    key[ALLEGRO_KEY_PAD_PLUS]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_DELETE:
                {
                    key[ALLEGRO_KEY_PAD_DELETE]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_ENTER:
                {
                    key[ALLEGRO_KEY_PAD_ENTER]=false;
                    break;
                }
                case ALLEGRO_KEY_PRINTSCREEN:
                {
                    key[ALLEGRO_KEY_PRINTSCREEN]=false;
                    break;
                }
                case ALLEGRO_KEY_PAUSE:
                {
                    key[ALLEGRO_KEY_PAUSE]=false;
                    break;
                }
                case ALLEGRO_KEY_ABNT_C1:
                {
                    key[ALLEGRO_KEY_ABNT_C1]=false;
                    break;
                }
                case ALLEGRO_KEY_YEN:
                {
                    key[ALLEGRO_KEY_YEN]=false;
                    break;
                }
                case ALLEGRO_KEY_KANA:
                {
                    key[ALLEGRO_KEY_KANA]=false;
                    break;
                }
                case ALLEGRO_KEY_CONVERT:
                {
                    key[ALLEGRO_KEY_CONVERT]=false;
                    break;
                }
                case ALLEGRO_KEY_NOCONVERT:
                {
                    key[ALLEGRO_KEY_NOCONVERT]=false;
                    break;
                }
                case ALLEGRO_KEY_AT:
                {
                    key[ALLEGRO_KEY_AT]=false;
                    break;
                }
                case ALLEGRO_KEY_CIRCUMFLEX:
                {
                    key[ALLEGRO_KEY_CIRCUMFLEX]=false;
                    break;
                }
                case ALLEGRO_KEY_COLON2:
                {
                    key[ALLEGRO_KEY_COLON2]=false;
                    break;
                }
                case ALLEGRO_KEY_KANJI:
                {
                    key[ALLEGRO_KEY_KANJI]=false;
                    break;
                }
                case ALLEGRO_KEY_LSHIFT:
                {
                    key[ALLEGRO_KEY_LSHIFT]=false;
                    break;
                }
                case ALLEGRO_KEY_RSHIFT:
                {
                    key[ALLEGRO_KEY_RSHIFT]=false;
                    break;
                }
                case ALLEGRO_KEY_LCTRL:
                {
                    key[ALLEGRO_KEY_LCTRL]=false;
                    break;
                }
                case ALLEGRO_KEY_RCTRL:
                {
                    key[ALLEGRO_KEY_RCTRL]=false;
                    break;
                }
                case ALLEGRO_KEY_ALT:
                {
                    key[ALLEGRO_KEY_ALT]=false;
                    break;
                }
                case ALLEGRO_KEY_ALTGR:
                {
                    key[ALLEGRO_KEY_ALTGR]=false;
                    break;
                }
                case ALLEGRO_KEY_LWIN:
                {
                    key[ALLEGRO_KEY_LWIN]=false;
                    break;
                }
                case ALLEGRO_KEY_RWIN:
                {
                    key[ALLEGRO_KEY_RWIN]=false;
                    break;
                }
                case ALLEGRO_KEY_MENU:
                {
                    key[ALLEGRO_KEY_MENU]=false;
                    break;
                }
                case ALLEGRO_KEY_SCROLLLOCK:
                {
                    key[ALLEGRO_KEY_SCROLLLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_NUMLOCK:
                {
                    key[ALLEGRO_KEY_NUMLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_CAPSLOCK:
                {
                    key[ALLEGRO_KEY_CAPSLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_EQUALS:
                {
                    key[ALLEGRO_KEY_PAD_EQUALS]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKQUOTE:
                {
                    key[ALLEGRO_KEY_BACKQUOTE]=false;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON2:
                {
                    key[ALLEGRO_KEY_SEMICOLON2]=false;
                    break;
                }
                case ALLEGRO_KEY_COMMAND:
                {
                    key[ALLEGRO_KEY_COMMAND]=false;
                    break;
                }
                }
                for(auto &it : observers)
                {
                    it->onKeyRelease(ev.keyboard.unichar, ev.keyboard.keycode, ev.keyboard.modifiers);
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_CHAR:
            {
                if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                {
                    valid=false;
                    break;
                }
                /*
                int unichar=ev.keyboard.unichar;
                if(unichar>=32)
                {
                    getChatlog()->insertChar(unichar);
                }
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_LEFT:
                {
                    if(chatlog->visible)
                    {
                        chatlog->posLeft();
                    }
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    if(chatlog->visible)
                    {
                        chatlog->posRight();
                    }
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_CTRL)
                    {
                        chatlog->retreat();
                    }
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_CTRL)
                    {
                        chatlog->advance();
                    }
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_SHIFT)
                    {
                        chatlog->visible=false;
                    }
                    else
                    {
                        if(getChatlog()->visible)
                        {
                            if(al_ustr_length(input))
                            {
                                getChatlog()->insert("Player "+intToStr(player->getTeamID()), al_cstr(input), AL_COL_WHITE, CMSG_USERNAME, 0);
                                al_ustr_truncate(input, 0);
                            }
                            else
                            {
                                chatlog->visible=false;
                            }
                        }
                        else
                        {
                            chatlog->visible=true;
                        }
                    }
                    break;
                }
                }
                */
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            {
                if(region.contains(ev.mouse.x, ev.mouse.y))
                {
                    switch(ev.mouse.button)
                    {
                    case 1:
                    {
                        //Left Click
                        mouse[MOUSEBUTTON::LEFT]=true;
                        onLeftClick();
                        break;
                    }
                    case 2:
                    {
                        mouse[MOUSEBUTTON::RIGHT]=true;
                        camera->setMouseX(ev.mouse.x);
                        camera->setMouseY(ev.mouse.y);
                        break;
                    }
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            {
                switch(ev.mouse.button)
                {
                case 1:
                {
                    mouse[MOUSEBUTTON::LEFT]=false;
                    onLeftUp();
                    break;
                }
                case 2:
                {
                    mouse[MOUSEBUTTON::RIGHT]=false;
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:
            {
                for(auto &it : buttons)
                {
                    it->hover=(it->contains(ev.mouse.x, ev.mouse.y));
                }
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            {
                std::fill(key.begin(), key.end(), false);
                for(auto &it : mouse)
                {
                    it.second=false;
                }
                for(auto &it : buttons)
                {
                    it->hover=false;
                }
                break;
            }
            }
        }
        break;
    }
/*
#ifdef ENET_ENABLED
    case FRAME_MULTIPLAYER_STRATEGY:
    {
        if(enet)
        {
            switch(enet_event.type)
            {
            case ENET_EVENT_TYPE_NONE:
            {
                //TODO
                break;
            }
            case ENET_EVENT_TYPE_CONNECT:
            {
                enet_event.peer->data=(void*)"Player 2";
                peer=enet_event.peer;
                if(!peer_valid)
                {
                    sendInfo(std::string(ENET_SERVER_UUID)+VERSION, true);
                }
                break;
            }
            case ENET_EVENT_TYPE_RECEIVE:
            {
                if(peer_valid)
                {
                    recvInfo(enet_event.packet);
                }
                else
                {
                    peer_valid=validatePeer(enet_event.packet);
                    if(!peer_valid)
                    {
                        if(enet_state==ENETSTATE::IS_SERVER)
                        {
                            //enet_peer_disconnect(peer, 0);
                            enet_peer_reset(peer);
                            peer=nullptr;
                        }
                        else if(enet_state==ENETSTATE::IS_CLIENT)
                        {
                            peer=nullptr;
                            restart(getRegion(), mapID, FRAME_STARTSCREEN, getPlayer());
                            return;
                        }
                    }
                    else if(enet_state==ENETSTATE::IS_CLIENT)
                    {
                        sendInfo(std::string(ENET_CLIENT_UUID)+VERSION);
                        bool good=true;
                        int count=0;
                        //line below is temp.
                        getPlayer()->state=PLAYSTATE::NOT_TURN;
                        while(good)
                        {
                            enet_host_service(host, &enet_event, 100);
                            switch(enet_event.type)
                            {
                            case ENET_EVENT_TYPE_RECEIVE:
                            {
                                count=0;
                                if(enet_event.packet->dataLength)
                                {
                                    switch(static_cast<ACTIONTYPE>(enet_event.packet->data[0]))
                                    {
                                    case ACTIONTYPE::TRANSFER_COMPLETE:
                                    {
                                        good=false;
                                        break;
                                    }
                                    default:
                                    {
                                        recvInfo(enet_event.packet);
                                    }
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                count++;
                                if(count>=50)
                                {
                                    peer=nullptr;
                                    restart(getRegion(), mapID, FRAME_STARTSCREEN, getPlayer());
                                    return;
                                }
                                break;
                            }
                            }
                        }
                        al_flush_event_queue(event_queue);
                    }
                    else if(enet_state==ENETSTATE::IS_SERVER)
                    {
                        sendInfo(getPacket(static_cast<char>(ACTIONTYPE::TRANSFER_ID), (char)2));
                        sendInfo(getPacket(getWorld()));
                        sendInfo(getPacket(static_cast<char>(ACTIONTYPE::TRANSFER_COMPLETE)));
                        getChatlog()->insert("System", std::string((const char*)enet_event.peer->data)+" has connected!", AL_COL_YELLOW, CMSG_NOTICE, 0);
                    }
                }
                enet_packet_destroy(enet_event.packet);
                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT:
            {
                //printf ("%s disconected.\n", enet_event.peer -> data);
                getChatlog()->insert("System", std::string((const char*)enet_event.peer->data)+" has disconnected!", AL_COL_YELLOW, CMSG_NOTICE, 0);
                enet_event.peer->data=nullptr;
                peer=nullptr;
                peer_valid=false;
                break;
            }
            }
        }
        for(ALLEGRO_EVENT ev; valid && al_get_next_event(event_queue, &ev);)
        {
            switch(ev.type)
            {
            case ALLEGRO_EVENT_TIMER:
            {
                if(chatlog->visible)
                {
                    //
                }
                else
                {
                    if(key[ALLEGRO_KEY_UP])
                    {
                        camera->setY(camera->getY()+8);
                    }
                    if(key[ALLEGRO_KEY_DOWN])
                    {
                        camera->setY(camera->getY()-8);
                    }
                    if(key[ALLEGRO_KEY_LEFT])
                    {
                        camera->setX(camera->getX()+8);
                    }
                    if(key[ALLEGRO_KEY_RIGHT])
                    {
                        camera->setX(camera->getX()-8);
                    }
                }
                if(key[ALLEGRO_KEY_ESCAPE])
                {
                    valid=false;
                }
                if(mouse[MOUSEBUTTON::RIGHT])
                {
                    al_get_mouse_state(&cursorState);
                    camera->moveMouse(cursorState.x, cursorState.y);
                }
                invalidate();
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            {
                valid=false;
                return;
            }
            case ALLEGRO_EVENT_KEY_DOWN:
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_A:
                {
                    key[ALLEGRO_KEY_A]=true;
                    break;
                }
                case ALLEGRO_KEY_B:
                {
                    key[ALLEGRO_KEY_B]=true;
                    break;
                }
                case ALLEGRO_KEY_C:
                {
                    key[ALLEGRO_KEY_C]=true;
                    break;
                }
                case ALLEGRO_KEY_D:
                {
                    key[ALLEGRO_KEY_D]=true;
                    break;
                }
                case ALLEGRO_KEY_E:
                {
                    key[ALLEGRO_KEY_E]=true;
                    break;
                }
                case ALLEGRO_KEY_F:
                {
                    key[ALLEGRO_KEY_F]=true;
                    break;
                }
                case ALLEGRO_KEY_G:
                {
                    key[ALLEGRO_KEY_G]=true;
                    break;
                }
                case ALLEGRO_KEY_H:
                {
                    key[ALLEGRO_KEY_H]=true;
                    break;
                }
                case ALLEGRO_KEY_I:
                {
                    key[ALLEGRO_KEY_I]=true;
                    break;
                }
                case ALLEGRO_KEY_J:
                {
                    key[ALLEGRO_KEY_J]=true;
                    break;
                }
                case ALLEGRO_KEY_K:
                {
                    key[ALLEGRO_KEY_K]=true;
                    break;
                }
                case ALLEGRO_KEY_L:
                {
                    key[ALLEGRO_KEY_L]=true;
                    break;
                }
                case ALLEGRO_KEY_M:
                {
                    key[ALLEGRO_KEY_M]=true;
                    break;
                }
                case ALLEGRO_KEY_N:
                {
                    key[ALLEGRO_KEY_N]=true;
                    break;
                }
                case ALLEGRO_KEY_O:
                {
                    key[ALLEGRO_KEY_O]=true;
                    break;
                }
                case ALLEGRO_KEY_P:
                {
                    key[ALLEGRO_KEY_P]=true;
                    break;
                }
                case ALLEGRO_KEY_Q:
                {
                    key[ALLEGRO_KEY_Q]=true;
                    break;
                }
                case ALLEGRO_KEY_R:
                {
                    key[ALLEGRO_KEY_R]=true;
                    break;
                }
                case ALLEGRO_KEY_S:
                {
                    key[ALLEGRO_KEY_S]=true;
                    break;
                }
                case ALLEGRO_KEY_T:
                {
                    key[ALLEGRO_KEY_T]=true;
                    break;
                }
                case ALLEGRO_KEY_U:
                {
                    key[ALLEGRO_KEY_U]=true;
                    break;
                }
                case ALLEGRO_KEY_V:
                {
                    key[ALLEGRO_KEY_V]=true;
                    break;
                }
                case ALLEGRO_KEY_W:
                {
                    key[ALLEGRO_KEY_W]=true;
                    break;
                }
                case ALLEGRO_KEY_X:
                {
                    key[ALLEGRO_KEY_X]=true;
                    break;
                }
                case ALLEGRO_KEY_Y:
                {
                    key[ALLEGRO_KEY_Y]=true;
                    break;
                }
                case ALLEGRO_KEY_Z:
                {
                    key[ALLEGRO_KEY_Z]=true;
                    break;
                }
                case ALLEGRO_KEY_0:
                {
                    key[ALLEGRO_KEY_0]=true;
                    break;
                }
                case ALLEGRO_KEY_1:
                {
                    key[ALLEGRO_KEY_1]=true;
                    break;
                }
                case ALLEGRO_KEY_2:
                {
                    key[ALLEGRO_KEY_2]=true;
                    break;
                }
                case ALLEGRO_KEY_3:
                {
                    key[ALLEGRO_KEY_3]=true;
                    break;
                }
                case ALLEGRO_KEY_4:
                {
                    key[ALLEGRO_KEY_4]=true;
                    break;
                }
                case ALLEGRO_KEY_5:
                {
                    key[ALLEGRO_KEY_5]=true;
                    break;
                }
                case ALLEGRO_KEY_6:
                {
                    key[ALLEGRO_KEY_6]=true;
                    break;
                }
                case ALLEGRO_KEY_7:
                {
                    key[ALLEGRO_KEY_7]=true;
                    break;
                }
                case ALLEGRO_KEY_8:
                {
                    key[ALLEGRO_KEY_8]=true;
                    break;
                }
                case ALLEGRO_KEY_9:
                {
                    key[ALLEGRO_KEY_9]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_0:
                {
                    key[ALLEGRO_KEY_PAD_0]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_1:
                {
                    key[ALLEGRO_KEY_PAD_1]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_2:
                {
                    key[ALLEGRO_KEY_PAD_2]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_3:
                {
                    key[ALLEGRO_KEY_PAD_3]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_4:
                {
                    key[ALLEGRO_KEY_PAD_4]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_5:
                {
                    key[ALLEGRO_KEY_PAD_5]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_6:
                {
                    key[ALLEGRO_KEY_PAD_6]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_7:
                {
                    key[ALLEGRO_KEY_PAD_7]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_8:
                {
                    key[ALLEGRO_KEY_PAD_8]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_9:
                {
                    key[ALLEGRO_KEY_PAD_9]=true;
                    break;
                }
                case ALLEGRO_KEY_F1:
                {
                    key[ALLEGRO_KEY_F1]=true;
                    break;
                }
                case ALLEGRO_KEY_F2:
                {
                    key[ALLEGRO_KEY_F2]=true;
                    break;
                }
                case ALLEGRO_KEY_F3:
                {
                    key[ALLEGRO_KEY_F3]=true;
                    break;
                }
                case ALLEGRO_KEY_F4:
                {
                    key[ALLEGRO_KEY_F4]=true;
                    break;
                }
                case ALLEGRO_KEY_F5:
                {
                    key[ALLEGRO_KEY_F5]=true;
                    break;
                }
                case ALLEGRO_KEY_F6:
                {
                    key[ALLEGRO_KEY_F6]=true;
                    break;
                }
                case ALLEGRO_KEY_F7:
                {
                    key[ALLEGRO_KEY_F7]=true;
                    break;
                }
                case ALLEGRO_KEY_F8:
                {
                    key[ALLEGRO_KEY_F8]=true;
                    break;
                }
                case ALLEGRO_KEY_F9:
                {
                    key[ALLEGRO_KEY_F9]=true;
                    break;
                }
                case ALLEGRO_KEY_F10:
                {
                    key[ALLEGRO_KEY_F10]=true;
                    break;
                }
                case ALLEGRO_KEY_F11:
                {
                    key[ALLEGRO_KEY_F11]=true;
                    break;
                }
                case ALLEGRO_KEY_F12:
                {
                    key[ALLEGRO_KEY_F12]=true;
                    break;
                }
                case ALLEGRO_KEY_ESCAPE:
                {
                    key[ALLEGRO_KEY_ESCAPE]=true;
                    break;
                }
                case ALLEGRO_KEY_TILDE:
                {
                    key[ALLEGRO_KEY_TILDE]=true;
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    key[ALLEGRO_KEY_MINUS]=true;
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    key[ALLEGRO_KEY_EQUALS]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSPACE:
                {
                    key[ALLEGRO_KEY_BACKSPACE]=true;
                    chatlog->deleteChar();
                    break;
                }
                case ALLEGRO_KEY_TAB:
                {
                    key[ALLEGRO_KEY_TAB]=true;
                    break;
                }
                case ALLEGRO_KEY_OPENBRACE:
                {
                    key[ALLEGRO_KEY_OPENBRACE]=true;
                    break;
                }
                case ALLEGRO_KEY_CLOSEBRACE:
                {
                    key[ALLEGRO_KEY_CLOSEBRACE]=true;
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    key[ALLEGRO_KEY_ENTER]=true;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON:
                {
                    key[ALLEGRO_KEY_SEMICOLON]=true;
                    break;
                }
                case ALLEGRO_KEY_QUOTE:
                {
                    key[ALLEGRO_KEY_QUOTE]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH:
                {
                    key[ALLEGRO_KEY_BACKSLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH2:
                {
                    key[ALLEGRO_KEY_BACKSLASH2]=true;
                    break;
                }
                case ALLEGRO_KEY_COMMA:
                {
                    key[ALLEGRO_KEY_COMMA]=true;
                    break;
                }
                case ALLEGRO_KEY_FULLSTOP:
                {
                    key[ALLEGRO_KEY_FULLSTOP]=true;
                    break;
                }
                case ALLEGRO_KEY_SLASH:
                {
                    key[ALLEGRO_KEY_SLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_SPACE:
                {
                    key[ALLEGRO_KEY_SPACE]=true;
                    break;
                }
                case ALLEGRO_KEY_INSERT:
                {
                    key[ALLEGRO_KEY_INSERT]=true;
                    break;
                }
                case ALLEGRO_KEY_DELETE:
                {
                    key[ALLEGRO_KEY_DELETE]=true;
                    break;
                }
                case ALLEGRO_KEY_HOME:
                {
                    key[ALLEGRO_KEY_HOME]=true;
                    break;
                }
                case ALLEGRO_KEY_END:
                {
                    key[ALLEGRO_KEY_END]=true;
                    break;
                }
                case ALLEGRO_KEY_PGUP:
                {
                    key[ALLEGRO_KEY_PGUP]=true;
                    chatlog->pageUp();
                    break;
                }
                case ALLEGRO_KEY_PGDN:
                {
                    key[ALLEGRO_KEY_PGDN]=true;
                    chatlog->pageDown();
                    break;
                }
                case ALLEGRO_KEY_LEFT:
                {
                    key[ALLEGRO_KEY_LEFT]=true;
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    key[ALLEGRO_KEY_RIGHT]=true;
                    break;
                }
                case ALLEGRO_KEY_UP:
                {
                    key[ALLEGRO_KEY_UP]=true;
                    if(chatlog->visible)
                    {
                        chatlog->retreat();
                    }
                    break;
                }
                case ALLEGRO_KEY_DOWN:
                {
                    key[ALLEGRO_KEY_DOWN]=true;
                    if(chatlog->visible)
                    {
                        chatlog->advance();
                    }
                    break;
                }
                case ALLEGRO_KEY_PAD_SLASH:
                {
                    key[ALLEGRO_KEY_PAD_SLASH]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_ASTERISK:
                {
                    key[ALLEGRO_KEY_PAD_ASTERISK]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_MINUS:
                {
                    key[ALLEGRO_KEY_PAD_MINUS]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_PLUS:
                {
                    key[ALLEGRO_KEY_PAD_PLUS]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_DELETE:
                {
                    key[ALLEGRO_KEY_PAD_DELETE]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_ENTER:
                {
                    key[ALLEGRO_KEY_PAD_ENTER]=true;
                    break;
                }
                case ALLEGRO_KEY_PRINTSCREEN:
                {
                    key[ALLEGRO_KEY_PRINTSCREEN]=true;
                    break;
                }
                case ALLEGRO_KEY_PAUSE:
                {
                    key[ALLEGRO_KEY_PAUSE]=true;
                    break;
                }
                case ALLEGRO_KEY_ABNT_C1:
                {
                    key[ALLEGRO_KEY_ABNT_C1]=true;
                    break;
                }
                case ALLEGRO_KEY_YEN:
                {
                    key[ALLEGRO_KEY_YEN]=true;
                    break;
                }
                case ALLEGRO_KEY_KANA:
                {
                    key[ALLEGRO_KEY_KANA]=true;
                    break;
                }
                case ALLEGRO_KEY_CONVERT:
                {
                    key[ALLEGRO_KEY_CONVERT]=true;
                    break;
                }
                case ALLEGRO_KEY_NOCONVERT:
                {
                    key[ALLEGRO_KEY_NOCONVERT]=true;
                    break;
                }
                case ALLEGRO_KEY_AT:
                {
                    key[ALLEGRO_KEY_AT]=true;
                    break;
                }
                case ALLEGRO_KEY_CIRCUMFLEX:
                {
                    key[ALLEGRO_KEY_CIRCUMFLEX]=true;
                    break;
                }
                case ALLEGRO_KEY_COLON2:
                {
                    key[ALLEGRO_KEY_COLON2]=true;
                    break;
                }
                case ALLEGRO_KEY_KANJI:
                {
                    key[ALLEGRO_KEY_KANJI]=true;
                    break;
                }
                case ALLEGRO_KEY_LSHIFT:
                {
                    key[ALLEGRO_KEY_LSHIFT]=true;
                    break;
                }
                case ALLEGRO_KEY_RSHIFT:
                {
                    key[ALLEGRO_KEY_RSHIFT]=true;
                    break;
                }
                case ALLEGRO_KEY_LCTRL:
                {
                    key[ALLEGRO_KEY_LCTRL]=true;
                    break;
                }
                case ALLEGRO_KEY_RCTRL:
                {
                    key[ALLEGRO_KEY_RCTRL]=true;
                    break;
                }
                case ALLEGRO_KEY_ALT:
                {
                    key[ALLEGRO_KEY_ALT]=true;
                    break;
                }
                case ALLEGRO_KEY_ALTGR:
                {
                    key[ALLEGRO_KEY_ALTGR]=true;
                    break;
                }
                case ALLEGRO_KEY_LWIN:
                {
                    key[ALLEGRO_KEY_LWIN]=true;
                    break;
                }
                case ALLEGRO_KEY_RWIN:
                {
                    key[ALLEGRO_KEY_RWIN]=true;
                    break;
                }
                case ALLEGRO_KEY_MENU:
                {
                    key[ALLEGRO_KEY_MENU]=true;
                    break;
                }
                case ALLEGRO_KEY_SCROLLLOCK:
                {
                    key[ALLEGRO_KEY_SCROLLLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_NUMLOCK:
                {
                    key[ALLEGRO_KEY_NUMLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_CAPSLOCK:
                {
                    key[ALLEGRO_KEY_CAPSLOCK]=true;
                    break;
                }
                case ALLEGRO_KEY_PAD_EQUALS:
                {
                    key[ALLEGRO_KEY_PAD_EQUALS]=true;
                    break;
                }
                case ALLEGRO_KEY_BACKQUOTE:
                {
                    key[ALLEGRO_KEY_BACKQUOTE]=true;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON2:
                {
                    key[ALLEGRO_KEY_SEMICOLON2]=true;
                    break;
                }
                case ALLEGRO_KEY_COMMAND:
                {
                    key[ALLEGRO_KEY_COMMAND]=true;
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_UP:
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_A:
                {
                    key[ALLEGRO_KEY_A]=false;
                    break;
                }
                case ALLEGRO_KEY_B:
                {
                    key[ALLEGRO_KEY_B]=false;
                    break;
                }
                case ALLEGRO_KEY_C:
                {
                    key[ALLEGRO_KEY_C]=false;
                    break;
                }
                case ALLEGRO_KEY_D:
                {
                    key[ALLEGRO_KEY_D]=false;
                    break;
                }
                case ALLEGRO_KEY_E:
                {
                    key[ALLEGRO_KEY_E]=false;
                    break;
                }
                case ALLEGRO_KEY_F:
                {
                    key[ALLEGRO_KEY_F]=false;
                    break;
                }
                case ALLEGRO_KEY_G:
                {
                    key[ALLEGRO_KEY_G]=false;
                    break;
                }
                case ALLEGRO_KEY_H:
                {
                    key[ALLEGRO_KEY_H]=false;
                    break;
                }
                case ALLEGRO_KEY_I:
                {
                    key[ALLEGRO_KEY_I]=false;
                    break;
                }
                case ALLEGRO_KEY_J:
                {
                    key[ALLEGRO_KEY_J]=false;
                    break;
                }
                case ALLEGRO_KEY_K:
                {
                    key[ALLEGRO_KEY_K]=false;
                    break;
                }
                case ALLEGRO_KEY_L:
                {
                    key[ALLEGRO_KEY_L]=false;
                    break;
                }
                case ALLEGRO_KEY_M:
                {
                    key[ALLEGRO_KEY_M]=false;
                    break;
                }
                case ALLEGRO_KEY_N:
                {
                    key[ALLEGRO_KEY_N]=false;
                    break;
                }
                case ALLEGRO_KEY_O:
                {
                    key[ALLEGRO_KEY_O]=false;
                    break;
                }
                case ALLEGRO_KEY_P:
                {
                    key[ALLEGRO_KEY_P]=false;
                    break;
                }
                case ALLEGRO_KEY_Q:
                {
                    key[ALLEGRO_KEY_Q]=false;
                    break;
                }
                case ALLEGRO_KEY_R:
                {
                    key[ALLEGRO_KEY_R]=false;
                    break;
                }
                case ALLEGRO_KEY_S:
                {
                    key[ALLEGRO_KEY_S]=false;
                    break;
                }
                case ALLEGRO_KEY_T:
                {
                    key[ALLEGRO_KEY_T]=false;
                    break;
                }
                case ALLEGRO_KEY_U:
                {
                    key[ALLEGRO_KEY_U]=false;
                    break;
                }
                case ALLEGRO_KEY_V:
                {
                    key[ALLEGRO_KEY_V]=false;
                    break;
                }
                case ALLEGRO_KEY_W:
                {
                    key[ALLEGRO_KEY_W]=false;
                    break;
                }
                case ALLEGRO_KEY_X:
                {
                    key[ALLEGRO_KEY_X]=false;
                    break;
                }
                case ALLEGRO_KEY_Y:
                {
                    key[ALLEGRO_KEY_Y]=false;
                    break;
                }
                case ALLEGRO_KEY_Z:
                {
                    key[ALLEGRO_KEY_Z]=false;
                    break;
                }
                case ALLEGRO_KEY_0:
                {
                    key[ALLEGRO_KEY_0]=false;
                    break;
                }
                case ALLEGRO_KEY_1:
                {
                    key[ALLEGRO_KEY_1]=false;
                    break;
                }
                case ALLEGRO_KEY_2:
                {
                    key[ALLEGRO_KEY_2]=false;
                    break;
                }
                case ALLEGRO_KEY_3:
                {
                    key[ALLEGRO_KEY_3]=false;
                    break;
                }
                case ALLEGRO_KEY_4:
                {
                    key[ALLEGRO_KEY_4]=false;
                    break;
                }
                case ALLEGRO_KEY_5:
                {
                    key[ALLEGRO_KEY_5]=false;
                    break;
                }
                case ALLEGRO_KEY_6:
                {
                    key[ALLEGRO_KEY_6]=false;
                    break;
                }
                case ALLEGRO_KEY_7:
                {
                    key[ALLEGRO_KEY_7]=false;
                    break;
                }
                case ALLEGRO_KEY_8:
                {
                    key[ALLEGRO_KEY_8]=false;
                    break;
                }
                case ALLEGRO_KEY_9:
                {
                    key[ALLEGRO_KEY_9]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_0:
                {
                    key[ALLEGRO_KEY_PAD_0]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_1:
                {
                    key[ALLEGRO_KEY_PAD_1]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_2:
                {
                    key[ALLEGRO_KEY_PAD_2]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_3:
                {
                    key[ALLEGRO_KEY_PAD_3]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_4:
                {
                    key[ALLEGRO_KEY_PAD_4]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_5:
                {
                    key[ALLEGRO_KEY_PAD_5]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_6:
                {
                    key[ALLEGRO_KEY_PAD_6]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_7:
                {
                    key[ALLEGRO_KEY_PAD_7]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_8:
                {
                    key[ALLEGRO_KEY_PAD_8]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_9:
                {
                    key[ALLEGRO_KEY_PAD_9]=false;
                    break;
                }
                case ALLEGRO_KEY_F1:
                {
                    key[ALLEGRO_KEY_F1]=false;
                    break;
                }
                case ALLEGRO_KEY_F2:
                {
                    key[ALLEGRO_KEY_F2]=false;
                    break;
                }
                case ALLEGRO_KEY_F3:
                {
                    key[ALLEGRO_KEY_F3]=false;
                    break;
                }
                case ALLEGRO_KEY_F4:
                {
                    key[ALLEGRO_KEY_F4]=false;
                    break;
                }
                case ALLEGRO_KEY_F5:
                {
                    key[ALLEGRO_KEY_F5]=false;
                    break;
                }
                case ALLEGRO_KEY_F6:
                {
                    key[ALLEGRO_KEY_F6]=false;
                    break;
                }
                case ALLEGRO_KEY_F7:
                {
                    key[ALLEGRO_KEY_F7]=false;
                    break;
                }
                case ALLEGRO_KEY_F8:
                {
                    key[ALLEGRO_KEY_F8]=false;
                    break;
                }
                case ALLEGRO_KEY_F9:
                {
                    key[ALLEGRO_KEY_F9]=false;
                    break;
                }
                case ALLEGRO_KEY_F10:
                {
                    key[ALLEGRO_KEY_F10]=false;
                    break;
                }
                case ALLEGRO_KEY_F11:
                {
                    key[ALLEGRO_KEY_F11]=false;
                    break;
                }
                case ALLEGRO_KEY_F12:
                {
                    key[ALLEGRO_KEY_F12]=false;
                    break;
                }
                case ALLEGRO_KEY_ESCAPE:
                {
                    key[ALLEGRO_KEY_ESCAPE]=false;
                    break;
                }
                case ALLEGRO_KEY_TILDE:
                {
                    key[ALLEGRO_KEY_TILDE]=false;
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    key[ALLEGRO_KEY_MINUS]=false;
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    key[ALLEGRO_KEY_EQUALS]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSPACE:
                {
                    key[ALLEGRO_KEY_BACKSPACE]=false;
                    break;
                }
                case ALLEGRO_KEY_TAB:
                {
                    key[ALLEGRO_KEY_TAB]=false;
                    break;
                }
                case ALLEGRO_KEY_OPENBRACE:
                {
                    key[ALLEGRO_KEY_OPENBRACE]=false;
                    break;
                }
                case ALLEGRO_KEY_CLOSEBRACE:
                {
                    key[ALLEGRO_KEY_CLOSEBRACE]=false;
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    key[ALLEGRO_KEY_ENTER]=false;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON:
                {
                    key[ALLEGRO_KEY_SEMICOLON]=false;
                    break;
                }
                case ALLEGRO_KEY_QUOTE:
                {
                    key[ALLEGRO_KEY_QUOTE]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH:
                {
                    key[ALLEGRO_KEY_BACKSLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKSLASH2:
                {
                    key[ALLEGRO_KEY_BACKSLASH2]=false;
                    break;
                }
                case ALLEGRO_KEY_COMMA:
                {
                    key[ALLEGRO_KEY_COMMA]=false;
                    break;
                }
                case ALLEGRO_KEY_FULLSTOP:
                {
                    key[ALLEGRO_KEY_FULLSTOP]=false;
                    break;
                }
                case ALLEGRO_KEY_SLASH:
                {
                    key[ALLEGRO_KEY_SLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_SPACE:
                {
                    key[ALLEGRO_KEY_SPACE]=false;
                    break;
                }
                case ALLEGRO_KEY_INSERT:
                {
                    key[ALLEGRO_KEY_INSERT]=false;
                    break;
                }
                case ALLEGRO_KEY_DELETE:
                {
                    key[ALLEGRO_KEY_DELETE]=false;
                    break;
                }
                case ALLEGRO_KEY_HOME:
                {
                    key[ALLEGRO_KEY_HOME]=false;
                    break;
                }
                case ALLEGRO_KEY_END:
                {
                    key[ALLEGRO_KEY_END]=false;
                    break;
                }
                case ALLEGRO_KEY_PGUP:
                {
                    key[ALLEGRO_KEY_PGUP]=false;
                    break;
                }
                case ALLEGRO_KEY_PGDN:
                {
                    key[ALLEGRO_KEY_PGDN]=false;
                    break;
                }
                case ALLEGRO_KEY_LEFT:
                {
                    key[ALLEGRO_KEY_LEFT]=false;
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    key[ALLEGRO_KEY_RIGHT]=false;
                    break;
                }
                case ALLEGRO_KEY_UP:
                {
                    key[ALLEGRO_KEY_UP]=false;
                    break;
                }
                case ALLEGRO_KEY_DOWN:
                {
                    key[ALLEGRO_KEY_DOWN]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_SLASH:
                {
                    key[ALLEGRO_KEY_PAD_SLASH]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_ASTERISK:
                {
                    key[ALLEGRO_KEY_PAD_ASTERISK]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_MINUS:
                {
                    key[ALLEGRO_KEY_PAD_MINUS]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_PLUS:
                {
                    key[ALLEGRO_KEY_PAD_PLUS]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_DELETE:
                {
                    key[ALLEGRO_KEY_PAD_DELETE]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_ENTER:
                {
                    key[ALLEGRO_KEY_PAD_ENTER]=false;
                    break;
                }
                case ALLEGRO_KEY_PRINTSCREEN:
                {
                    key[ALLEGRO_KEY_PRINTSCREEN]=false;
                    break;
                }
                case ALLEGRO_KEY_PAUSE:
                {
                    key[ALLEGRO_KEY_PAUSE]=false;
                    break;
                }
                case ALLEGRO_KEY_ABNT_C1:
                {
                    key[ALLEGRO_KEY_ABNT_C1]=false;
                    break;
                }
                case ALLEGRO_KEY_YEN:
                {
                    key[ALLEGRO_KEY_YEN]=false;
                    break;
                }
                case ALLEGRO_KEY_KANA:
                {
                    key[ALLEGRO_KEY_KANA]=false;
                    break;
                }
                case ALLEGRO_KEY_CONVERT:
                {
                    key[ALLEGRO_KEY_CONVERT]=false;
                    break;
                }
                case ALLEGRO_KEY_NOCONVERT:
                {
                    key[ALLEGRO_KEY_NOCONVERT]=false;
                    break;
                }
                case ALLEGRO_KEY_AT:
                {
                    key[ALLEGRO_KEY_AT]=false;
                    break;
                }
                case ALLEGRO_KEY_CIRCUMFLEX:
                {
                    key[ALLEGRO_KEY_CIRCUMFLEX]=false;
                    break;
                }
                case ALLEGRO_KEY_COLON2:
                {
                    key[ALLEGRO_KEY_COLON2]=false;
                    break;
                }
                case ALLEGRO_KEY_KANJI:
                {
                    key[ALLEGRO_KEY_KANJI]=false;
                    break;
                }
                case ALLEGRO_KEY_LSHIFT:
                {
                    key[ALLEGRO_KEY_LSHIFT]=false;
                    break;
                }
                case ALLEGRO_KEY_RSHIFT:
                {
                    key[ALLEGRO_KEY_RSHIFT]=false;
                    break;
                }
                case ALLEGRO_KEY_LCTRL:
                {
                    key[ALLEGRO_KEY_LCTRL]=false;
                    break;
                }
                case ALLEGRO_KEY_RCTRL:
                {
                    key[ALLEGRO_KEY_RCTRL]=false;
                    break;
                }
                case ALLEGRO_KEY_ALT:
                {
                    key[ALLEGRO_KEY_ALT]=false;
                    break;
                }
                case ALLEGRO_KEY_ALTGR:
                {
                    key[ALLEGRO_KEY_ALTGR]=false;
                    break;
                }
                case ALLEGRO_KEY_LWIN:
                {
                    key[ALLEGRO_KEY_LWIN]=false;
                    break;
                }
                case ALLEGRO_KEY_RWIN:
                {
                    key[ALLEGRO_KEY_RWIN]=false;
                    break;
                }
                case ALLEGRO_KEY_MENU:
                {
                    key[ALLEGRO_KEY_MENU]=false;
                    break;
                }
                case ALLEGRO_KEY_SCROLLLOCK:
                {
                    key[ALLEGRO_KEY_SCROLLLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_NUMLOCK:
                {
                    key[ALLEGRO_KEY_NUMLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_CAPSLOCK:
                {
                    key[ALLEGRO_KEY_CAPSLOCK]=false;
                    break;
                }
                case ALLEGRO_KEY_PAD_EQUALS:
                {
                    key[ALLEGRO_KEY_PAD_EQUALS]=false;
                    break;
                }
                case ALLEGRO_KEY_BACKQUOTE:
                {
                    key[ALLEGRO_KEY_BACKQUOTE]=false;
                    break;
                }
                case ALLEGRO_KEY_SEMICOLON2:
                {
                    key[ALLEGRO_KEY_SEMICOLON2]=false;
                    break;
                }
                case ALLEGRO_KEY_COMMAND:
                {
                    key[ALLEGRO_KEY_COMMAND]=false;
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_CHAR:
            {
                int unichar=ev.keyboard.unichar;
                if(unichar>=32)
                {
                    getChatlog()->insertChar(unichar);
                }
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_LEFT:
                {
                    if(chatlog->visible)
                    {
                        chatlog->posLeft();
                    }
                    break;
                }
                case ALLEGRO_KEY_RIGHT:
                {
                    if(chatlog->visible)
                    {
                        chatlog->posRight();
                    }
                    break;
                }
                case ALLEGRO_KEY_MINUS:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_CTRL)
                    {
                        chatlog->retreat();
                    }
                    break;
                }
                case ALLEGRO_KEY_EQUALS:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_CTRL)
                    {
                        chatlog->advance();
                    }
                    break;
                }
                case ALLEGRO_KEY_ENTER:
                {
                    if(ev.keyboard.modifiers&ALLEGRO_KEYMOD_SHIFT)
                    {
                        chatlog->visible=false;
                    }
                    else
                    {
                        if(getChatlog()->visible)
                        {
                            if(al_ustr_length(input))
                            {
                                getChatlog()->insert("Player "+intToStr(player->getTeamID()), al_cstr(input), AL_COL_WHITE, CMSG_USERNAME, 0);
                                al_ustr_truncate(input, 0);
                            }
                            else
                            {
                                chatlog->visible=false;
                            }
                        }
                        else
                        {
                            chatlog->visible=true;
                        }
                    }
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            {
                if(region.contains(ev.mouse.x, ev.mouse.y))
                {
                    switch(ev.mouse.button)
                    {
                    case 1:
                    {
                        //Left Click
                        mouse[MOUSEBUTTON::LEFT]=true;
                        onLeftClick();
                        break;
                    }
                    case 2:
                    {
                        mouse[MOUSEBUTTON::RIGHT]=true;
                        camera->setMouseX(ev.mouse.x);
                        camera->setMouseY(ev.mouse.y);
                        break;
                    }
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            {
                switch(ev.mouse.button)
                {
                case 1:
                {
                    mouse[MOUSEBUTTON::LEFT]=false;
                    onLeftUp();
                    break;
                }
                case 2:
                {
                    mouse[MOUSEBUTTON::RIGHT]=false;
                    break;
                }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:
            {
                for(auto &it : buttons)
                {
                    it->hover=(it->contains(ev.mouse.x, ev.mouse.y));
                }
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            {
                std::fill(key.begin(), key.end(), false);
                std::fill(mouse.begin(), mouse.end(), false);
                for(auto it=buttons.begin(); it!=buttons.end(); it++)
                {
                    (*it)->hover=false;
                }
                break;
            }
            }
        }
        break;
    }
#endif
*/
    default:
    {
        break;
    }
    }
}
