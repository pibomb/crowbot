#ifndef RESOURCESYSTEM_H_INCLUDED
#define RESOURCESYSTEM_H_INCLUDED

#include "basicresource.h"

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

// Resource System
class ResourceSystem
{
private:
    std::map<FONTTYPE, Font> internalFonts;
    std::map<AUDIOTYPE, Sample> internalAudio;
    std::map<IMAGETYPE, ALLEGRO_BITMAP*> internalImages;
    std::map<PROJECTILETYPE, AnimatedConstructorData> internalProjectileAnimatedConstructorData;
public:
    void registerFont(FONTTYPE id, std::string directory);
    ALLEGRO_FONT* getFont(FONTTYPE font_id, int fontSize_id=14);
    void destroyFonts();
    Sample& getAudio(AUDIOTYPE audio_id);
    void stopAllAudio();
    void destroyAudio();
    void registerImage(IMAGETYPE image_id, std::string directory);
    ALLEGRO_BITMAP* getImage(IMAGETYPE image_id);
    AnimatedConstructorData getData(PROJECTILETYPE projectile_type_id);
    void initialize();
    void cleanup();
};

#endif // RESOURCESYSTEM_H_INCLUDED
