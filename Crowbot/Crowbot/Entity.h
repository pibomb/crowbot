#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "basicresource.h"
#include "Animated.h"
#include "Physics.h"

class Frame;

class Entity : public Animated
{
protected:
    ENTITYTYPE entity_type;
	Vec2 ent_vel;
	Vec2 ent_pos;
	int ent_health;
	unsigned int ent_id;
	AABB ent_bb;
	Frame *frame;
	virtual void transformation() override;
	virtual void onDraw() override;
	virtual void postDraw() override;
public:
	explicit Entity(ENTITYTYPE entity_type_arg, const unsigned int& id, const Vec2& position, const int& startHp, Frame *frame_arg);
	virtual ~Entity();
	unsigned int getId() {return ent_id;};
	int getHp() const {return ent_health;};
	const bool getLive() {return ent_health > 0;};
	void setRgn(AABB& ent_bb_arg) {ent_bb = ent_bb_arg;};
	AABB getRgn() const {return ent_bb;};
	void decHp(int amt) {ent_health -= amt;};
	void incHp(int amt) {ent_health += amt;};
	void move(Vec2 amt) {ent_pos.add(amt);};
	void move(float x, float y) {ent_pos.add(x, y);};
	Vec2 getVel() const {return ent_vel;};
	void setVel(Vec2 vel) {ent_vel = vel;};
	void setVel(float x, float y) {ent_vel = Vec2(x, y);};
};

#endif // ENTITY_H_INCLUDED
