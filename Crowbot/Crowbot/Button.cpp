#include "resource.h"

BUTTONTYPE Button::getType()
{
    return button_type;
}

void Button::press()
{
    pressed++;
}

void Button::release()
{
    pressed--;
    if(hover)
    {
        onPress();
    }
}

bool Button::contains(int x_arg, int y_arg)
{
    return bounding_box.contains(x_arg, y_arg);
}

void Button::transformation()
{
    postset().postTranslate(bounding_box.getTL());
}

void Button::onDraw()
{
    if(hover)
    {
        if(pressed)
        {
            al_draw_scaled_bitmap(depressed, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, bounding_box.getWidth(), bounding_box.getHeight(), 0);
        }
        else
        {
            al_draw_scaled_bitmap(hovering, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, bounding_box.getWidth(), bounding_box.getHeight(), 0);
        }
    }
    else
    {
        al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, bounding_box.getWidth(), bounding_box.getHeight(), 0);
    }
    al_draw_text(font, color, renderx, rendery, 0, display_text.c_str());
}

void Button::postDraw()
{
    //
}
