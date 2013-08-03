#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "basicresource.h"
#include "Animated.h"
#include "Physics.h"

class Frame;

class Entity : public PhysicalAnimated
{
protected:
    ENTITYTYPE entity_type;
	b2Resource *ent_body;
	int ent_health;
	unsigned int ent_id;
	AABB ent_bb;
	Frame *frame;
	virtual void transformation() override;
	virtual void onDraw() override;
	virtual void postDraw() override;
public:
	explicit Entity(ENTITYTYPE entity_type_arg, const unsigned int& id, const int& startHp, Frame *frame_arg);
	virtual ~Entity();
	unsigned int getId() {return ent_id;};
	int getHp() const {return ent_health;};
	void setHp(int amt) {ent_health+=amt;};
	bool isAlive() const {return ent_health > 0;};
	void setAABB(AABB& ent_bb_arg) {ent_bb = ent_bb_arg;};
	AABB getAABB() const {return ent_bb;};
	b2Vec2 getPosition();
	float getMass();
	float getX();
	float getY();
	void move(float x, float y);
	void move(b2Vec2 amt);
    virtual void beginDestroy();
    virtual bool isDeletable();
    virtual void destroy()=0;
};

#endif // ENTITY_H_INCLUDED
