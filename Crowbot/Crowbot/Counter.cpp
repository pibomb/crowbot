#include "resource.h"

void Counter::transformation()
{
    preset();
}

void Counter::onDraw()
{
    int bbx, bby, bbw, bbh;
    al_get_text_dimensions(resource.getFont(FONT_DEFAULT_GAME, FONT_SIZE_DEFAULT_GAME), getVal().c_str(), &bbx, &bby, &bbw, &bbh);
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(resource.getFont(FONT_DEFAULT_GAME, FONT_SIZE_DEFAULT_GAME), al_map_rgb(0, 0, 0), al_get_bitmap_width(background)/2-bbw/2, al_get_bitmap_height(background)/2-bbh/2, 0, getVal().c_str());
}

void Counter::postDraw()
{
    //
}
