#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED

#include "basicresource.h"
#include "Pixel.h"

class Vec2 : public Pixel
{
public:
    Vec2():
        Pixel(0, 0)
    {
        //
    }
    Vec2(const float& x_arg, const float& y_arg):
        Pixel(x_arg, y_arg)
    {
        //
    }
    float magnitude() const
    {
        return sqrt(getX()*getX()+getY()*getY());
    }
    float magnitudeSquared() const
    {
        return getX()*getX()+getY()*getY();
    }
    float dot(const Vec2& other) const
    {
        return getX()*other.getX()+getY()*other.getY();
    }
    float cross(const Vec2& other) const
    {
        return getX()*other.getY()-getY()*other.getX();
    }
    float angle(const Vec2& other) const
    {
        return cross(other)/magnitude()/other.magnitude();
    }
    float dist(const Vec2& p1, const Vec2& p2, bool isSegment=true) const
    {
        if(isSegment)
        {
            if(((*this)-p2)*(p2-p1)>0)
            {
                return (p2-(*this)).magnitude();
            }
            if(((*this)-p1)*(p1-p2)>0)
            {
                return (p1-(*this)).magnitude();
            }
        }
        return abs(((p2-p1)^((*this)-p1))/(p2-p1).magnitude());
    }
    Vec2 operator! () const
    {
        return Vec2(-getX(), -getY());
    }
    Vec2 operator+ (const Vec2& other) const
    {
        return Vec2(getX()+other.getX(), getY()+other.getY());
    }
    void operator+= (const Vec2& other)
    {
        add(other);
    }
    Vec2 operator- (const Vec2& other) const
    {
        return Vec2(getX()-other.getX(), getY()-other.getY());
    }
    void operator-= (const Vec2& other)
    {
        setAll(getX()-other.getX(), getY()-other.getY());
    }
    Vec2 operator* (float scalar) const
    {
        return Vec2(getX()*scalar, getY()*scalar);
    }
    void operator*= (float scalar)
    {
        setAll(getX()*scalar, getY()*scalar);
    }
    Vec2 operator/ (float scalar) const
    {
        return Vec2(getX()/scalar, getY()/scalar);
    }
    void operator/= (float scalar)
    {
        setAll(getX()/scalar, getY()/scalar);
    }
    float operator* (const Vec2& other) const
    {
        return dot(other);
    }
    float operator^ (const Vec2& other) const
    {
        return cross(other);
    }
    operator float() const
    {
        return magnitude();
    }
    operator Pixel() const
    {
        return Pixel(getX(), getY());
    }
};

class AABB : public Vec2
{
private:
    Vec2 tl, br;
public:
    AABB():
        tl(0, 0),
        br(0, 0)
    {
        //
    }
    AABB(const Vec2& tl_arg, const Vec2& br_arg):
        tl(tl_arg),
        br(br_arg)
    {
        //
    }
    AABB(const float& tlx_arg, const float& tly_arg, const float& brx_arg, const float& bry_arg):
        tl(tlx_arg, tly_arg),
        br(brx_arg, bry_arg)
    {
        //
    }
    Vec2 getTL() const
    {
        return tl;
    }
    void setTL(const Vec2& tl_arg)
    {
        tl.setAll(tl_arg.getX(), tl_arg.getY());
    }
    Vec2 getBR() const
    {
        return br;
    }
    void setBR(Vec2 br_arg)
    {
        br.setAll(br_arg.getX(), br_arg.getY());
    }
    Vec2 getTR() const
    {
        return Vec2(getBR().getX(), getTL().getY());
    }
    Vec2 getBL() const
    {
        return Vec2(getTL().getX(), getBR().getY());
    }
    float getWidth()
    {
        return getBR().getX()-getTL().getX();
    }
    float getHeight()
    {
        return getBR().getY()-getTL().getY();
    }
    void setAll(const float& tlx_arg, const float& tly_arg, const float& brx_arg, const float& bry_arg)
    {
        tl.setAll(tlx_arg, tly_arg);
        br.setAll(brx_arg, bry_arg);
    }
    void translate(Vec2 translate_arg)
    {
        tl+=translate_arg;
        br+=translate_arg;
    }
    bool intersect(const AABB& other) const
    {
        return getBR().getX()>other.getTL().getX() && other.getBR().getX()>getTL().getX();
    }
};

class Circle : public Vec2
{
private:
    Vec2 center;
    float radius;
public:
    Circle():
        center(0, 0),
        radius(0.0)
    {
        //
    }
    Circle(const float& centerx_arg, const float& centery_arg, const float& radius_arg):
        center(centerx_arg, centery_arg),
        radius(radius_arg)
    {
        //
    }
    Circle(const Vec2& center_arg, const float& radius_arg):
        center(center_arg),
        radius(radius_arg)
    {
        //
    }
    Vec2 getCenter() const
    {
        return center;
    }
    void setCenter(const Vec2& center_arg)
    {
        center.setAll(center_arg.getX(), center_arg.getY());
    }
    float getRadius() const
    {
        return radius;
    }
    bool intersect(const Circle& other) const
    {
        return (getRadius()+other.getRadius())*(getRadius()+other.getRadius())>(getCenter()-other.getCenter()).magnitudeSquared();
    }
};

#endif // PHYSICS_H_INCLUDED
