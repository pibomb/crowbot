#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "basicresource.h"

class Entity : public Drawable
{
private:
	Pixel ent_vel;
	Pixel ent_pos;
	int ent_health;
	UINT ent_id;
public:
	explicit Entity(const UINT id, Pixel position, const int startHp);
	virtual void transformation() override;
	virtual void onDraw() override;
	virtual void postDraw() override;
	UINT getId() {return ent_id;};
	int getHp() {return ent_health;};
	const bool getLive() {return ent_health > 0;};
	void setRgn(Rect& nRgn) {rgn = nRgn;};
	Rect& getRgn() {return rgn;};
	void decHp(int amt) {ent_health -= amt;};
	void incHp(int amt) {ent_health += amt;};
	void move(Pixel amt) {ent_pos.add(amt);};
	void move(int x, int y) {ent_pos.add(x, y);};
	Pixel& getVel() {return ent_vel;};
	void setVel(Pixel vel) {ent_vel = vel;};
	void setVel(int x, int y) {ent_vel = Pixel(x, y);};
};

#endif // ENTITY_H_INCLUDED
