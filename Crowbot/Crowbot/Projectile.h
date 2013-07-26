#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"
#include "Pixel.h"

class Projectile : public Drawable
{
private:
	Pixel pro_vel;
	Pixel pro_pos;
	bool is_valid;
	void transformation() override;
	void onDraw() override;
	void postDraw() override;
public:
    Projectile():
        pro_vel(Pixel(0, 0)),
        pro_pos(Pixel(0, 0)),
        is_valid(false)
    {
        //
    }
    void set(Pixel px);
    void update();
};

#endif // PROJECTILE_H_INCLUDED
