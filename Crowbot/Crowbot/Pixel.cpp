#include "resource.h"

float Pixel::getX() const
{
    return x;
}

void Pixel::setX(float x_arg)
{
    x=x_arg;
}

float Pixel::getY() const
{
    return y;
}

void Pixel::setY(float y_arg)
{
    y=y_arg;
}

void Pixel::getAll(float& x_out, float& y_out)
{
    x_out=x;
    y_out=y;
}

void Pixel::setAll(float x_arg, float y_arg)
{
    x=x_arg;
    y=y_arg;
}

void Pixel::add(const Pixel& px_arg)
{
    setAll(getX()+px_arg.getX(), getY()+px_arg.getY());
}

void Pixel::add(float x_arg, float y_arg)
{
    setAll(getX()+x_arg, getY()+y_arg);
}

float Pixel::getDist()
{
    return sqrt(getX()*getX()+getY()*getY());
}

Pixel Pixel::transformBy(const ALLEGRO_TRANSFORM *trans) const
{
    float fx=getX(), fy=getY();
    al_transform_coordinates(trans, &fx, &fy);
    return Pixel(fx, fy);
}

Pixel Pixel::operator+ (const Pixel& px_arg)
{
    return Pixel(getX()+px_arg.getX(), getY()+px_arg.getY());
}

void Pixel::operator+= (const Pixel& px_arg)
{
    add(px_arg);
}

#ifndef NDEBUG
void Pixel::print()
{
    printf("%f %f\n", x, y);
}
#endif

Pixel Rect::getTL()
{
    return tl;
}

void Rect::getTL(float& tlx_out, float& tly_out)
{
    tlx_out=tl.getX();
    tly_out=tl.getY();
}

void Rect::setTL(Pixel tl_arg)
{
    tl=tl_arg;
}

void Rect::setTL(float tlx_arg, float tly_arg)
{
    tl.setX(tlx_arg);
    tl.setY(tly_arg);
}

Pixel Rect::getBR()
{
    return br;
}

void Rect::getBR(float& brx_out, float& bry_out)
{
    brx_out=br.getX();
    bry_out=br.getY();
}

void Rect::setBR(Pixel br_arg)
{
    br=br_arg;
}

void Rect::setBR(float brx_arg, float bry_arg)
{
    br.setX(brx_arg);
    br.setY(bry_arg);
}

Pixel Rect::getTR()
{
    return Pixel(getBR().getX(), getTL().getY());
}

Pixel Rect::getBL()
{
    return Pixel(getTL().getX(), getBR().getY());
}

void Rect::shift(Pixel tl_arg)
{
    setAll(tl_arg.getX(), tl_arg.getY(), getWidth()+tl_arg.getX(), getHeight()+tl_arg.getY());
}

float Rect::getWidth()
{
    return br.getX()-tl.getX();
}

float Rect::getHeight()
{
    return br.getY()-tl.getY();
}

void Rect::getAll(float& tlx_out, float& tly_out, float& brx_out, float& bry_out)
{
    tl.getAll(tlx_out, tly_out);
    br.getAll(brx_out, bry_out);
}

void Rect::setAll(float tlx_arg, float tly_arg, float brx_arg, float bry_arg)
{
    tl.setAll(tlx_arg, tly_arg);
    br.setAll(brx_arg, bry_arg);
}

void Rect::translate(float x_arg, float y_arg)
{
    tl.setX(tl.getX()+x_arg);
    tl.setY(tl.getY()+y_arg);
    br.setX(br.getX()+x_arg);
    br.setY(br.getY()+y_arg);
}

void Rect::render(int r_arg, int g_arg, int b_arg)
{
    al_draw_filled_rectangle(tl.getX(), tl.getY(), br.getX(), br.getY(), al_map_rgb(r_arg, g_arg, b_arg));
}

void Rect::render(ALLEGRO_COLOR color_arg)
{
    al_draw_filled_rectangle(getTL().getX(), getTL().getY(), getBR().getX(), getBR().getY(), color_arg);
}

void Rect::tlrender(int r_arg, int g_arg, int b_arg, float translucent_arg)
{
    if(r_arg || g_arg || b_arg)
    {
        //al_draw_tinted_scaled_bitmap(idToImage[IMG_RECTANGLE].get(), al_map_rgba_f(r_arg/255.0, g_arg/255.0, b_arg/255.0, translucent_arg), 1, 0, 2, 1, tl.getX(), tl.getY(), br.getX(), br.getY(), 0);
    }
    else
    {
        //al_draw_tinted_scaled_bitmap(idToImage[IMG_RECTANGLE].get(), al_map_rgba_f(1, 1, 1, translucent_arg), 0, 0, 1, 1, tl.getX(), tl.getY(), br.getX(), br.getY(), 0);
    }
}

void Rect::drawBoundingBox(ALLEGRO_COLOR color_arg, int stroke_arg)
{
    al_draw_line(getTL().getX(), getTL().getY(), getBR().getX(), getTL().getY(), color_arg, stroke_arg);
    al_draw_line(getTL().getX(), getBR().getY(), getBR().getX(), getBR().getY(), color_arg, stroke_arg);
    al_draw_line(getTL().getX(), getTL().getY(), getTL().getX(), getBR().getY(), color_arg, stroke_arg);
    al_draw_line(getBR().getX(), getTL().getY(), getBR().getX(), getBR().getY(), color_arg, stroke_arg);
}

bool Rect::contains(Pixel px_arg)
{
    return px_arg.getX()>tl.getX() && px_arg.getX()<br.getX() && px_arg.getY()>tl.getY() && px_arg.getY()<br.getY();
}

bool Rect::contains(float x_arg, float y_arg)
{
    return x_arg>tl.getX() && x_arg<br.getX() && y_arg>tl.getY() && y_arg<br.getY();
}

#ifndef NDEBUG
void Rect::print()
{
    printf("%f %f %f %f\n", tl.getX(), tl.getY(), br.getX(), br.getY());
}
#endif

bool Rect::operator< (const Rect& other)const
{
    return (tl.getX()<other.tl.getX()) || (tl.getX()==other.tl.getX() && (tl.getY()<other.tl.getY() || (tl.getY()==other.tl.getY() && (br.getX()<other.br.getX() || (br.getX()==other.br.getX() && (br.getY()<other.br.getY()))))));
}

bool Rect::operator> (const Rect& other)const
{
    return (br.getX()>other.br.getX()) || (br.getX()==other.br.getX() && (br.getY()>other.br.getY() || (br.getY()==other.br.getY() && (tl.getX()>other.tl.getX() || (tl.getX()==other.tl.getX() && (tl.getY()>other.tl.getY()))))));
}

bool Rect::operator^ (const Rect& other)const
{
    return tl.getX()>other.tl.getX() && tl.getY()>other.tl.getY() && br.getX()<other.br.getX() && br.getY()<other.br.getY();
}

Rect Rect::operator| (const Rect& other)const // Bounding Box
{
    Rect smaller=*this<other?*this:other;
    Rect larger=*this>other?*this:other;
    return Rect(smaller.tl, larger.br);
}

Rect Rect::operator& (const Rect& other)const // Intersection
{
    if(*this^other)
    {
        return *this;
    }
    if(other^*this)
    {
        return other;
    }
    Rect smaller=*this<other?*this:other;
    Rect larger=*this>other?*this:other;
    return Rect(larger.tl, smaller.br);
}
