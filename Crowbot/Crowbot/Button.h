#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"
#include "Pixel.h"

class Button : public Drawable
{
private:
    int pressed;
    BUTTONTYPE button_type;
    Rect bounding_box;
    std::function<void()> onPress;
    std::string display_text;
    int renderx;
    int rendery;
    ALLEGRO_FONT *font;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *image;
    ALLEGRO_BITMAP *hovering;
    ALLEGRO_BITMAP *depressed;
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    bool hover;
    Button(int tlx_arg, int tly_arg, int brx_arg, int bry_arg, std::function<void()> onPress_arg, std::string display_text_arg, BUTTONTYPE button_type_arg, ALLEGRO_FONT *font_arg, ALLEGRO_COLOR color_arg, ALLEGRO_BITMAP *image_arg, ALLEGRO_BITMAP *hovering_arg, ALLEGRO_BITMAP *depressed_arg):
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
    virtual ~Button()
    {
        //
    }
    operator bool() const
    {
        return pressed;
    }
    BUTTONTYPE getType();
    void press();
    void release();
    bool contains(int x_arg, int y_arg);
};

#endif // BUTTON_H_INCLUDED
