#include "resource.h"

// Font

void Font::destroy()
{
    for(auto &it : fonts)
    {
        if(it.second)
        {
            al_destroy_font(it.second);
        }
    }
    fonts.clear();
}

void Font::setDir(std::string directory_arg)
{
    directory=directory_arg;
}

ALLEGRO_FONT* Font::getFont(int id)
{
    if(!fonts[id])
    {
        fonts[id]=al_load_font(directory.c_str(), id, 0);
        al_draw_text(fonts[id], al_map_rgba(0, 0, 0, 0), 0, 0, 0, "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    }
    return fonts[id];
}

// Sample

void Sample::load(std::string filename)
{
    sample=al_load_sample(("audio/"+filename).c_str());
}

void Sample::play(ALLEGRO_PLAYMODE playmode)
{
    al_play_sample(sample, 1.0, 0.0, 1.0, playmode, &sampleID);
}

void Sample::stop()
{
    al_stop_sample(&sampleID);
}

void Sample::destroy()
{
    if(sample)
    {
        al_destroy_sample(sample);
    }
}

// ResourceSystem

void ResourceSystem::registerFont(FONTTYPE id, std::string directory)
{
    internalFonts[id].setDir(directory);
}

ALLEGRO_FONT* ResourceSystem::getFont(FONTTYPE font_id_arg, int size_arg)
{
    auto it=internalFonts.find(font_id_arg);
    if(it!=internalFonts.end())
    {
        return it->second.getFont(size_arg);
    }
    return nullptr;
}

void ResourceSystem::destroyFonts()
{
    for(auto &it : internalFonts)
    {
        it.second.destroy();
    }
    internalFonts.clear();
}

Sample& ResourceSystem::getAudio(AUDIOTYPE audio_id)
{
    return internalAudio[audio_id];
}

void ResourceSystem::stopAllAudio()
{
    al_stop_samples();
}

void ResourceSystem::destroyAudio()
{
    for(auto &it : internalAudio)
    {
        it.second.destroy();
    }
}

void ResourceSystem::registerImage(IMAGETYPE image_id, std::string directory)
{
    internalImages[image_id]=al_load_bitmap(directory.c_str());
}

ALLEGRO_BITMAP* ResourceSystem::getImage(IMAGETYPE image_id)
{
    return internalImages[image_id];
}

void ResourceSystem::initialize()
{
    // Fonts
    registerFont(FONTTYPE::ARIAL, "fonts/arial.ttf");
    registerFont(FONTTYPE::FFF_TUSJ, "fonts/FFF_Tusj/FFF_Tusj.ttf");
    registerFont(FONTTYPE::FREEDOM, "fonts/FREEDOM/FREEDOM.otf");
    registerFont(FONTTYPE::MONTESERRAT, "fonts/Monteserrat/Montserrat-Regular.ttf");
    registerFont(FONTTYPE::MONTESERRAT_B, "fonts/Monteserrat/Montserrat-Bold.ttf");
    registerFont(FONTTYPE::AMBLE, "fonts/Amble/Amble-Regular.ttf");
    registerFont(FONTTYPE::AMBLE_B, "fonts/Amble/Amble-Bold.ttf");
    registerFont(FONTTYPE::AMBLE_I, "fonts/Amble/Amble-Italic.ttf");
    registerFont(FONTTYPE::AMBLE_BI, "fonts/Amble/Amble-BoldItalic.ttf");
    registerFont(FONTTYPE::ORBITRON, "fonts/Orbitron/Orbitron Black.otf");
    registerFont(FONTTYPE::ORBITRON_LT, "fonts/Orbitron/Orbitron Light.otf");
    registerFont(FONTTYPE::ORBITRON_B, "fonts/Orbitron/Orbitron Bold.otf");
    // Images
    registerImage(IMAGETYPE::RECTANGLE, "images/rectangle.png");
    registerImage(IMAGETYPE::DEFAULT_BUTTON, "images/btn_background.png");
    registerImage(IMAGETYPE::DEFAULT_BUTTON_H, "images/btn_background_h.png");
    registerImage(IMAGETYPE::DEFAULT_BUTTON_D, "images/btn_background_d.png");
    registerImage(IMAGETYPE::INVALID, "images/robot.png");
}

void ResourceSystem::cleanup()
{
    destroyFonts();
    destroyAudio();
}
