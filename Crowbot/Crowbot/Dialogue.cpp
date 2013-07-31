#include "resource.h"

void Page::evaluate(Rect bounding_box, std::string& input)
{
    //hack, try to use something else
    if(input[input.length()-1]!=' ')
    {
        input+=' ';
    }
    for(int i=0; y_offset+(i+2)*fontSize*1.14<bounding_box.getHeight(); i++)
    {
        if(input.empty())
        {
            break;
        }
        unsigned int oldindex=1, index=0;
        while(index!=oldindex && input.find(" ", index+1)!=std::string::npos && al_get_text_width(resource.getFont(font_id, fontSize), input.substr(0, input.find(' ', index+1)).c_str())+x_offset*2<bounding_box.getWidth())
        {
            oldindex=index;
            index=input.find(' ', index+1);
        }
        unsigned int minLine=input.find("\n");
        if(index<minLine && al_get_text_width(resource.getFont(font_id, fontSize), input.substr(0, minLine).c_str())+x_offset*2>=bounding_box.getWidth())
        {
            lines.push_back(input.substr(0, index));
            if(index==std::string::npos)
            {
                input.clear();
            }
            else
            {
                input.erase(0, index+1);
            }
        }
        else
        {
            lines.push_back(input.substr(0, minLine));
            if(minLine==std::string::npos)
            {
                input.clear();
            }
            else
            {
                input.erase(0, minLine+1);
            }
            break;
        }
    }
}

void Page::transformation()
{
    preset();
}

void Page::onDraw()
{
    for(int i=0; i<(int)lines.size(); i++)
    {
        al_draw_text(resource.getFont(font_id, fontSize), AL_COL_WHITE, x_offset, y_offset+(i+1)*fontSize*1.14, 0, lines[i].c_str());
    }
}

void Page::postDraw()
{
    //
}

void Dialogue::evaluate(std::string text)
{
    std::string currentOwner;
    while(text.length())
    {
        if(text[0]=='[')
        {
            owners.push_back(text.substr(2, text.find(']')-2));
            text.erase(0, text.find(']')+2);
            currentOwner=owners[owners.size()-1];
        }
        else
        {
            owners.push_back(currentOwner);
        }
        pages.push_back(Page(fontID, fontSize, x_offset, y_offset, bounding_box, text));
    }
    if((int)pages.size()>currentPage)
    {
        pages[currentPage].push(this);
    }
}

RETURNTYPE Dialogue::retreatText()
{
    if(currentPage>0)
    {
        pages[currentPage--].pull();
        pages[currentPage].push(this);
        return RETURNTYPE::NORMAL;
    }
    return RETURNTYPE::COMPLETE;
}

RETURNTYPE Dialogue::advanceText()
{
    pages[currentPage++].pull();
    if((int)pages.size()>currentPage)
    {
        pages[currentPage].push(this);
        return RETURNTYPE::NORMAL;
    }
    return RETURNTYPE::COMPLETE;
}

void Dialogue::transformation()
{
    preset().preTranslate(bounding_box.getTL());
}

void Dialogue::onDraw()
{
    al_clear_to_color(AL_COL_BLACK);
    al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background), 0, 0, bounding_box.getWidth(), bounding_box.getHeight(), 0);
    al_draw_bitmap(left, 0, -al_get_bitmap_height(left), 0);
    al_draw_bitmap(right, bounding_box.getWidth()-al_get_bitmap_width(right), -al_get_bitmap_height(right), ALLEGRO_FLIP_HORIZONTAL);
    if(!owners[currentPage].empty())
    {
        al_draw_bitmap(name_background, x_offset+25, y_offset-10, 0);
        al_draw_text(resource.getFont(fontID, fontSize), AL_COL_WHITE, x_offset+25, y_offset-10, 0, owners[currentPage].c_str());
    }
}

void Dialogue::postDraw()
{
    al_flip_display();
}

RETURNTYPE Dialogue::update()
{
    for(ALLEGRO_EVENT ev; al_get_next_event(event_queue, &ev);)
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
            return RETURNTYPE::SHUTDOWN;
        }
        case ALLEGRO_EVENT_KEY_CHAR:
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
            {
                return RETURNTYPE::SHUTDOWN;
            }
            case ALLEGRO_KEY_ENTER:
            {
                return RETURNTYPE::NORMAL;
            }
            case ALLEGRO_KEY_LEFT:
            {
                retreatText();
                break;
            }
            case ALLEGRO_KEY_RIGHT:
            {
                if(advanceText()==RETURNTYPE::COMPLETE)
                {
                    return RETURNTYPE::NORMAL;
                }
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
        {
            if(advanceText()==RETURNTYPE::COMPLETE)
            {
                return RETURNTYPE::NORMAL;
            }
            break;
        }
        default:
        {
            break;
        }
        }
    }
    invalidate();
    render();
    return RETURNTYPE::COMPLETE;
}

RETURNTYPE Dialogue::run()
{
    al_flush_event_queue(event_queue);
    al_set_target_bitmap(al_get_backbuffer(display));
    while(1)
    {
        RETURNTYPE ret_flag=update();
        switch(ret_flag)
        {
        case RETURNTYPE::NORMAL:
        {
            stop();
            onExit();
            return RETURNTYPE::NORMAL;
        }
        case RETURNTYPE::SHUTDOWN:
        {
            stop();
            onShutdown();
            return RETURNTYPE::SHUTDOWN;
        }
        default:
        {
            break;
        }
        }
        render();
        al_flip_display();
    }
    return RETURNTYPE::COMPLETE;
}

void Dialogue::stop()
{
    al_flush_event_queue(event_queue);
}
