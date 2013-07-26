#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

#include "basicresource.h"

class Pixel
{
private:
    float x, y;
public:
    float getX()const;
    void setX(float x_arg);
    float getY()const;
    void setY(float y_arg);
    void getAll(float& x_out, float& y_out);
    void setAll(float x_arg, float y_arg);
    void add(Pixel px_arg);
    void add(float x_arg, float y_arg);
    Pixel transformBy(const ALLEGRO_TRANSFORM*trans)const{
        float fx=x,fy=y;
        al_transform_coordinates(trans,&fx,&fy);
        return Pixel(x, y);
    }
#ifndef NDEBUG
    void print();
#endif
    /*
    operator hexpt() const
    {
        return hexpt((float)x, (float)y);
    }
    */
    Pixel()
    {
        //
    }
    Pixel(float x_arg, float y_arg)
    {
        x=x_arg;
        y=y_arg;
    }
};

class Rect
{
private:
    Pixel tl, br;
public:
    Pixel getTL();
    void getTL(float& tlx_out, float& tly_out);
    void setTL(Pixel tl_arg);
    void setTL(float tlx_arg, float tly_arg);
    Pixel getBR();
    void getBR(float& brx_out, float& bry_out);
    void setBR(Pixel br_arg);
    void setBR(float brx_arg, float bry_arg);
    Pixel getTR();
    Pixel getBL();
    void shift(Pixel tl_arg);
    float getWidth();
    float getHeight();
    void getAll(float& tlx_out, float& tly_out, float& brx_out, float& bry_out);
    void setAll(float tlx_arg, float tly_arg, float brx_arg, float bry_arg);
    void translate(float x_arg, float y_arg);
    void render(int r_arg, int g_arg, int b_arg);
    void render(ALLEGRO_COLOR color_arg);
    void tlrender(int r_arg, int g_arg, int b_arg, float translucent_arg);
    void drawBoundingBox(ALLEGRO_COLOR color_arg, int stroke_arg);
    bool contains(Pixel px_arg);
    bool contains(float x_arg, float y_arg);
    Rect transformBy(const ALLEGRO_TRANSFORM*trans)const{
        return Rect(tl.transformBy(trans),br.transformBy(trans));
    }
#ifndef NDEBUG
    void print();
#endif
    bool operator< (const Rect& other)const;
    bool operator> (const Rect& other)const;
    bool operator^ (const Rect& other)const;
    Rect operator& (const Rect& other)const;
    Rect operator| (const Rect& other)const;
    operator bool()
    {
        return tl.getX()<br.getX() && tl.getY()<br.getY();
    }
    /*
    operator int()
    {
        return (br.getX()-tl.getX())*(br.getY()-tl.getY());
    }
    */
    Rect()
    {
        //
    }
    Rect(float tlx_arg, float tly_arg, float brx_arg, float bry_arg)
    {
        tl.setAll(tlx_arg, tly_arg);
        br.setAll(brx_arg, bry_arg);
    }
    Rect(Pixel tl_arg, Pixel br_arg)
    {
        tl=tl_arg;
        br=br_arg;
    }
};

#endif // PIXEL_H_INCLUDED
