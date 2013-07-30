#include "resource.h"

void Box::transformation()
{
    preset();//.preTranslate(bounding_box.getTL());
}

void Box::onDraw()
{
    //printf("%f %f\n", box_body->getBody()->GetWorldCenter().x, box_body->getBody()->GetWorldCenter().y);
    bounding_box.render(AL_COL_RED);
    //Rect(0, 0, bounding_box.getWidth(), bounding_box.getHeight()).render(AL_COL_RED);
}

void Box::postDraw()
{
    //
}

DRAWABLETYPE Box::getDrawableType()
{
    return DRAWABLETYPE::BOX;
}

void Box::beginCollision(PhysicalDrawable *other)
{
    //
}

void Box::endCollision(PhysicalDrawable *other)
{
    //
}

void ContactListener::BeginContact(b2Contact* contact)
{
    void *objectA=contact->GetFixtureA()->GetBody()->GetUserData(), *objectB=contact->GetFixtureB()->GetBody()->GetUserData();
    if(objectA)
    {
        static_cast<PhysicalDrawable*>(objectA)->beginCollision(static_cast<PhysicalDrawable*>(objectB));
    }
    if(objectB)
    {
        static_cast<PhysicalDrawable*>(objectB)->beginCollision(static_cast<PhysicalDrawable*>(objectA));
    }
}

void ContactListener::EndContact(b2Contact* contact)
{
    void *objectA=contact->GetFixtureA()->GetBody()->GetUserData(), *objectB=contact->GetFixtureB()->GetBody()->GetUserData();
    if(objectA)
    {
        static_cast<PhysicalDrawable*>(objectA)->endCollision(static_cast<PhysicalDrawable*>(objectB));
    }
    if(objectB)
    {
        static_cast<PhysicalDrawable*>(objectB)->endCollision(static_cast<PhysicalDrawable*>(objectA));
    }
}
