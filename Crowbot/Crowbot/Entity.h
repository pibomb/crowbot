#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "basicresource.h"

class Entity : public Drawable
{
private:
	Pixel ent_vel;
	Pixel ent_pos;
	UINT ent_health;
	UINT ent_id;
public:
	explicit Entity(const UINT& id, Pixel& position, const UINT& startHp);
	virtual void transformation();
	virtual void onDraw();
	virtual void postDraw();
	UINT getId() {return ent_id;};
	UINT getHp() {return ent_health;};
	const bool getLive() {return ent_health > 0;};
	void setRgn(Rect& nRgn) {rgn = nRgn;};
	Rect& getRgn() {return rgn;};
	void decHp(UINT amt) {ent_health -= amt;};
	void incHp(UINT amt) {ent_health += amt;};
	void move(Pixel amt) {ent_pos.setX(ent_pos.getX() + amt.getX()); ent_pos.setY(ent_pos.getY() + amt.getY());};
	void move(int x, int y) {ent_pos.setX(ent_pos.getX() + x); ent_pos.setY(ent_pos.getY() + y);};
	Pixel& getVel() {return ent_vel;};
	void setVel(Pixel vel) {ent_vel = vel;};
	void setVel(int x, int y) {ent_vel = Pixel(x, y);};
};

#endif // ENTITY_H_INCLUDED
