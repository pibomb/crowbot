#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include "basicresource.h"

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
public:
    void registerFont(FONTTYPE id, std::string directory);
    ALLEGRO_FONT* getFont(FONTTYPE font_id, int fontSize_id=14);
    void destroyFonts();
    Sample& getAudio(AUDIOTYPE audio_id);
    void stopAllAudio();
    void destroyAudio();
    void registerImage(IMAGETYPE image_id, std::string directory);
    ALLEGRO_BITMAP* getImage(IMAGETYPE image_id);
    void initialize();
    void cleanup();
};

#include "Animated.h"
#include "Button.h"
#include "Camera.h"
#include "Compiler.h"
#include "Counter.h"
#include "Drawable.h"
#include "Entity.h"
#include "Frame.h"
#include "GlobalVariables.h"
#include "Layer.h"
#include "Lexxer.h"
#include "Parser.h"
#include "Pixel.h"
#include "Robot.h"
#include "SystemFunctions.h"

#endif // RESOURCE_H_INCLUDED
