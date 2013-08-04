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
        PhysicalDrawable *physA=static_cast<PhysicalDrawable*>(objectA), *physB=static_cast<PhysicalDrawable*>(objectB);
        if(fixtureA->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureA->GetUserData()))(physA, physB, COLLISIONTYPE::BEGIN);
        }
        if(fixtureB->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureB->GetUserData()))(physB, physA, COLLISIONTYPE::BEGIN);
        }
        physA->collisions++;
        physA->beginCollision(physB);
        physB->collisions++;
        physB->beginCollision(physA);
    }
}

void ContactListener::EndContact(b2Contact* contact)
{
    b2Fixture *fixtureA=contact->GetFixtureA(), *fixtureB=contact->GetFixtureB();
    void *objectA=fixtureA->GetBody()->GetUserData(), *objectB=fixtureB->GetBody()->GetUserData();
    if(objectA && objectB)
    {
        PhysicalDrawable *physA=static_cast<PhysicalDrawable*>(objectA), *physB=static_cast<PhysicalDrawable*>(objectB);
        if(fixtureA->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureA->GetUserData()))(physA, physB, COLLISIONTYPE::END);
        }
        if(fixtureB->GetUserData())
        {
            ((void(*)(PhysicalDrawable*, PhysicalDrawable*, COLLISIONTYPE))(fixtureB->GetUserData()))(physB, physA, COLLISIONTYPE::END);
        }
        physA->collisions--;
        physA->endCollision(physB);
        physB->collisions--;
        physB->endCollision(physA);
    }
}
