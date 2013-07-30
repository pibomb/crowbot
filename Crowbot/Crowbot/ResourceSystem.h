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
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape polyShape;
    std::list<b2Resource*>::iterator this_position;
public:
    b2Resource():
        body(nullptr)
    {
        //
    }
    ~b2Resource();
    std::list<b2Resource*>::iterator getThisPosition();
    void setThisPosition(std::list<b2Resource*>::iterator this_position_arg);
    b2Body* getBody();
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
    void registerImage(IMAGETYPE image_id, std::string directory);
    ALLEGRO_BITMAP* getImage(IMAGETYPE image_id);
    AnimatedConstructorData getData(ENTITYTYPE entity_type_id);
    AnimatedConstructorData getData(PROJECTILETYPE projectile_type_id);
    void initialize();
    void cleanup();
};

#endif // RESOURCESYSTEM_H_INCLUDED
