#include "resource.h"

Button::Button(int tlx_arg, int tly_arg, int brx_arg, int bry_arg, std::function<void()> onPress_arg, std::string display_text_arg, BUTTONTYPE button_type_arg, ALLEGRO_FONT *font_arg, ALLEGRO_COLOR color_arg, ALLEGRO_BITMAP *image_arg, ALLEGRO_BITMAP *hovering_arg, ALLEGRO_BITMAP *depressed_arg):
    Drawable(Rect(tlx_arg, tly_arg, brx_arg, bry_arg)),
    pressed(0),
    button_type(button_type_arg),
    bounding_box(tlx_arg, tly_arg, brx_arg, bry_arg),
    onPress(onPress_arg),
    display_text(display_text_arg),
    font(font_arg),
    color(color_arg),
    image(image_arg),
    hovering(hovering_arg),
    depressed(depressed_arg),
    hover(false)
{
    int bbx, bby, bbw, bbh;
    al_get_text_dimensions(font, display_text.c_str(), &bbx, &bby, &bbw, &bbh);
    renderx=bounding_box.getWidth()/2-bbw/2;
    rendery=bounding_box.getHeight()/2-bbh/2;
}

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
