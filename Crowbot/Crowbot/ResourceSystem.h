#ifndef RESOURCESYSTEM_H_INCLUDED
#define RESOURCESYSTEM_H_INCLUDED

#include "basicresource.h"
#include "GlobalVariables.h"

struct AnimatedConstructorData;

class Font
{
private:
    std::string directory;
    std::map<int, ALLEGRO_FONT*> fonts;
public:
    Font():
        directory("fonts/arial.ttf")
    {
        //
    }
    Font(std::string directory_arg):
        directory(directory_arg)
    {
        //
    }
    ~Font()
    {
        //
    }
    void destroy();
    void setDir(std::string directory_arg);
    ALLEGRO_FONT* getFont(int id);
};

class Sample
{
private:
    ALLEGRO_SAMPLE* sample;
    ALLEGRO_SAMPLE_ID sampleID;
public:
    Sample():
        sample(nullptr)
    {
        //
    }
    void load(std::string filename);
    void play(ALLEGRO_PLAYMODE playmode);
    void stop();
    void destroy();
};

class b2Resource
{
private:
    b2Body *body;
    std::list<b2Resource*>::iterator this_position;
public:
    b2Resource():
        body(nullptr)
    {
        //
    }
    virtual ~b2Resource();
    std::list<b2Resource*>::iterator getThisPosition();
    void setThisPosition(std::list<b2Resource*>::iterator this_position_arg);
    b2Body* getBody();
    b2ChainShape* getChain();
    void* addb2Vec2ToArray()
    {
        return nullptr;
    }
    template<class... Args>
    std::pair<b2Vec2, void*>* addb2Vec2ToArray(float x_arg, float y_arg, Args... args)
    {
        b2Vec2 chainPoint(x_arg, y_arg);
        if(sizeof...(args)==0)
        {
            return new std::pair<b2Vec2, void*>(chainPoint, nullptr);
        }
        return new std::pair<b2Vec2, void*>(chainPoint, static_cast<void*>(addb2Vec2ToArray(args...)));
    }
    template<class... Args>
    void registerChainShape(void *userData_arg, b2Vec2 bodyDef_position_arg, Args... args)
    {
        const int elements=sizeof...(args)/2;
        b2Vec2 chainPoints[elements];
        std::pair<b2Vec2, void*> *hold, *chainPoint=addb2Vec2ToArray(args...);
        chainPoints[0]=chainPoint->first;
        hold=chainPoint;
        for(int i=1; chainPoint->second; i++)
        {
            chainPoint=static_cast<std::pair<b2Vec2, void*>*>(chainPoint->second);
            delete hold;
            chainPoints[i]=chainPoint->first;
            hold=chainPoint;
        }
        delete hold;
        b2BodyDef bodyDef;
        bodyDef.position=bodyDef_position_arg;
        body=world.CreateBody(&bodyDef);
        b2ChainShape shape;
        shape.CreateChain(chainPoints, elements);
        b2FixtureDef fixtureDef;
        fixtureDef.shape=&shape;
        body->CreateFixture(&fixtureDef);
        body->SetUserData(userData_arg);
    }
    void addGroundSensor(void *userData_arg);
    void registerChainShape(void *userData_arg, b2Vec2 bodyDef_position_arg, std::vector<b2Vec2> chainPoints);
    void registerStaticBox(void *userData_arg, b2Vec2 bodyDef_position_arg, float length_arg, float width_arg, float density_arg);
    void registerDynamicBox(void *userData_arg, b2Vec2 bodyDef_position_arg, float length_arg, float width_arg, float density_arg, float friction_arg);
    void ApplyLinearImpulseAtCenter(b2Vec2 impulse_arg);
};

// Resource System
class ResourceSystem
{
private:
    std::map<FONTTYPE, Font> internalFonts;
    std::map<AUDIOTYPE, Sample> internalAudio;
    std::map<IMAGETYPE, ALLEGRO_BITMAP*> internalImages;
    std::map<ENTITYTYPE, AnimatedConstructorData> internalEntityAnimatedConstructorData;
    std::map<PROJECTILETYPE, AnimatedConstructorData> internalProjectileAnimatedConstructorData;
    std::list<b2Resource*> b2ResourceList;
public:
    void registerFont(FONTTYPE id, std::string directory);
    ALLEGRO_FONT* getFont(FONTTYPE font_id, int fontSize_id=14);
    void destroyFonts();
    Sample& getAudio(AUDIOTYPE audio_id);
    void stopAllAudio();
    void destroyAudio();
    b2Resource* createb2Resource();
    void destroyb2Resource(b2Resource *b2Resource_arg);
    ALLEGRO_BITMAP* getImage(IMAGETYPE image_id);
    void destroyImages();
    AnimatedConstructorData getData(ENTITYTYPE entity_type_id);
    AnimatedConstructorData getData(PROJECTILETYPE projectile_type_id);
    void initialize();
    void cleanup();
};

#endif // RESOURCESYSTEM_H_INCLUDED
