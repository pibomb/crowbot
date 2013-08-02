#include "resource.h"

b2Resource* Chain::getResource()
{
    return chn_body;
}

void Chain::transformation()
{
    preset();
}

void Chain::onDraw()
{
    if(collisions)
    {
        b2ChainShape *chn_chain=chn_body->getChain();
        b2EdgeShape chn_edge;
        for(int i=0; i<chn_chain->GetChildCount(); i++)
        {
            chn_chain->GetChildEdge(&chn_edge, i);
            al_draw_line(M_TO_PX(chn_edge.m_vertex1.x), -M_TO_PX(chn_edge.m_vertex1.y), M_TO_PX(chn_edge.m_vertex2.x), -M_TO_PX(chn_edge.m_vertex2.y), AL_COL_RED, 2);
        }
    }
    else
    {
        b2ChainShape *chn_chain=chn_body->getChain();
        b2EdgeShape chn_edge;
        for(int i=0; i<chn_chain->GetChildCount(); i++)
        {
            chn_chain->GetChildEdge(&chn_edge, i);
            al_draw_line(M_TO_PX(chn_edge.m_vertex1.x), -M_TO_PX(chn_edge.m_vertex1.y), M_TO_PX(chn_edge.m_vertex2.x), -M_TO_PX(chn_edge.m_vertex2.y), AL_COL_BLUE, 2);
        }
    }
}

void Chain::postDraw()
{
    //
}

DRAWABLETYPE Chain::getDrawableType()
{
    return DRAWABLETYPE::CHAIN;
}

void Chain::beginCollision(PhysicalDrawable *other)
{
    collisions++;
}

void Chain::endCollision(PhysicalDrawable *other)
{
    collisions--;
}

b2Resource* Box::getResource()
{
    return box_body;
}

void Box::transformation()
{
    preset();//.preTranslate(bounding_box.getTL());
}

void Box::onDraw()
{
    if(collisions)
    {
        bounding_box.render(AL_COL_RED);
    }
    else
    {
        bounding_box.render(AL_COL_BLUE);
    }
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
    collisions++;
}

void Box::endCollision(PhysicalDrawable *other)
{
    collisions--;
}

void ContactListener::BeginContact(b2Contact* contact)
{
    b2Fixture *fixtureA=contact->GetFixtureA(), *fixtureB=contact->GetFixtureB();
    void *objectA=fixtureA->GetBody()->GetUserData(), *objectB=fixtureB->GetBody()->GetUserData();
    if(objectA && objectB)
    {
        if(fixtureA->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureA->GetUserData()))(static_cast<PhysicalDrawable*>(objectA), static_cast<PhysicalDrawable*>(objectB), COLLISIONTYPE::BEGIN);
        }
        if(fixtureB->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureB->GetUserData()))(static_cast<PhysicalDrawable*>(objectB), static_cast<PhysicalDrawable*>(objectA), COLLISIONTYPE::BEGIN);
        }
        static_cast<PhysicalDrawable*>(objectA)->beginCollision(static_cast<PhysicalDrawable*>(objectB));
        static_cast<PhysicalDrawable*>(objectA)->collisions++;
        static_cast<PhysicalDrawable*>(objectB)->beginCollision(static_cast<PhysicalDrawable*>(objectA));
        static_cast<PhysicalDrawable*>(objectB)->collisions++;
    }
}

void ContactListener::EndContact(b2Contact* contact)
{
    b2Fixture *fixtureA=contact->GetFixtureA(), *fixtureB=contact->GetFixtureB();
    void *objectA=fixtureA->GetBody()->GetUserData(), *objectB=fixtureB->GetBody()->GetUserData();
    if(objectA && objectB)
    {
        if(fixtureA->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureA->GetUserData()))(static_cast<PhysicalDrawable*>(objectA), static_cast<PhysicalDrawable*>(objectB), COLLISIONTYPE::END);
        }
        if(fixtureB->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureB->GetUserData()))(static_cast<PhysicalDrawable*>(objectB), static_cast<PhysicalDrawable*>(objectA), COLLISIONTYPE::END);
        }
        static_cast<PhysicalDrawable*>(objectA)->endCollision(static_cast<PhysicalDrawable*>(objectB));
        static_cast<PhysicalDrawable*>(objectA)->collisions--;
        static_cast<PhysicalDrawable*>(objectB)->endCollision(static_cast<PhysicalDrawable*>(objectA));
        static_cast<PhysicalDrawable*>(objectB)->collisions--;
    }
}
