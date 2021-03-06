#include "resource.h"

#include "fonts/arial_font.h"
#include "fonts/FFF_Tusj/FFF_Tusj_font.h"
#include "fonts/FREEDOM/FREEDOM_font.h"
#include "fonts/Montserrat/Montserrat_font.h"
#include "fonts/Montserrat/Montserrat_B_font.h"
#include "fonts/Amble/Amble_font.h"
#include "fonts/Amble/Amble_B_font.h"
#include "fonts/Amble/Amble_I_font.h"
#include "fonts/Amble/Amble_BI_font.h"
#include "fonts/Orbitron/Orbitron_font.h"
#include "fonts/Orbitron/Orbitron_LT_font.h"
#include "fonts/Orbitron/Orbitron_B_font.h"

#include "images/rectangle_spritesheet.h"
#include "images/default_button_spritesheet.h"
#include "images/default_button_h_spritesheet.h"
#include "images/default_button_d_spritesheet.h"
#include "images/hp_bar_spritesheet.h"
#include "images/player_spritesheet.h"
#include "images/batbot_spritesheet.h"
#include "images/bullet_spritesheet.h"
#include "images/missile_spritesheet.h"

// Font

ALLEGRO_FONT* Font::getFont(int fontSize_arg)
{
    auto it=fonts.find(fontSize_arg);
    if(it==fonts.end())
    {
        ALLEGRO_FILE *memfile=memfileFunc();
        auto newFont=al_load_ttf_font_f(memfile, NULL, fontSize_arg, 0);
        al_draw_text(newFont, al_map_rgba(0, 0, 0, 0), 0, 0, 0, "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
        fonts[fontSize_arg]=newFont;
        return newFont;
    }
    return it->second;
}

void Font::setMemfileFunc(std::function<ALLEGRO_FILE*()> memfileFunc_arg)
{
    memfileFunc=memfileFunc_arg;
}

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

// b2Resource

b2Resource::~b2Resource()
{
    if(getBody())
    {
        sysGC.watchb2Body(getBody());
    }
}

std::list<b2Resource*>::iterator b2Resource::getThisPosition()
{
    return this_position;
}

void b2Resource::setThisPosition(std::list<b2Resource*>::iterator this_position_arg)
{
    this_position=this_position_arg;
}

b2Body* b2Resource::getBody()
{
    return body;
}

b2ChainShape* b2Resource::getChain()
{
    return static_cast<b2ChainShape*>(getBody()->GetFixtureList()->GetShape());
}

void b2Resource::addGroundSensor(void *userData_arg, uint16 categoryBits, uint16 maskBits)
{
    b2PolygonShape shape;
    b2AABB aabb=body->GetFixtureList()->GetAABB(0);
    shape.SetAsBox((aabb.upperBound.x-aabb.lowerBound.x)/2-0.05, (aabb.upperBound.y-aabb.lowerBound.y)/2, b2Vec2(0, -0.02), 0);
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&shape;
    fixtureDef.filter.categoryBits=categoryBits;
    fixtureDef.filter.maskBits=maskBits;
    fixtureDef.density=0;
    fixtureDef.friction=0;
    fixtureDef.isSensor=true;
    fixtureDef.userData=userData_arg;
    body->CreateFixture(&fixtureDef);
}

void b2Resource::registerChainShape(void *userData_arg, b2Vec2 bodyDef_position_arg, uint16 categoryBits, uint16 maskBits, std::vector<b2Vec2> chainPoints)
{
    b2BodyDef bodyDef;
    bodyDef.position=bodyDef_position_arg;
    body=world.CreateBody(&bodyDef);
    b2ChainShape shape;
    shape.CreateChain(&chainPoints[0], chainPoints.size());
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&shape;
    fixtureDef.filter.categoryBits=categoryBits;
    fixtureDef.filter.maskBits=maskBits;
    body->CreateFixture(&fixtureDef);
    body->SetUserData(userData_arg);
}

void b2Resource::registerStaticBox(void *userData_arg, b2Vec2 bodyDef_position_arg, float length_arg, float width_arg, float density_arg)
{
    b2BodyDef bodyDef;
    bodyDef.position=bodyDef_position_arg;
    body=world.CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(length_arg/2, width_arg/2);
    body->CreateFixture(&shape, density_arg);
    body->SetUserData(userData_arg);
}

void b2Resource::registerDynamicBox(void *userData_arg, b2Vec2 bodyDef_position_arg, uint16 categoryBits, uint16 maskBits, float length_arg, float width_arg, float density_arg, float friction_arg)
{
    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
    bodyDef.position=bodyDef_position_arg;
    body=world.CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(length_arg/2, width_arg/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&shape;
    fixtureDef.filter.categoryBits=categoryBits;
    fixtureDef.filter.maskBits=maskBits;
    fixtureDef.density=density_arg;
    fixtureDef.friction=friction_arg;
    body->CreateFixture(&fixtureDef);
    body->SetUserData(userData_arg);
}

void b2Resource::ApplyLinearImpulseAtCenter(b2Vec2 impulse_arg)
{
    getBody()->ApplyLinearImpulse(impulse_arg, getBody()->GetWorldCenter());
}

// ResourceSystem

void ResourceSystem::initializeFont(FONTTYPE fontName_arg, std::function<ALLEGRO_FILE*()> memfileFunc_arg)
{
    internalFonts[fontName_arg].setMemfileFunc(memfileFunc_arg);
}

ALLEGRO_FONT* ResourceSystem::getFont(FONTTYPE fontName_arg, int fontSize_arg)
{
    auto it=internalFonts.find(fontName_arg);
    if(it!=internalFonts.end())
    {
        return it->second.getFont(fontSize_arg);
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

b2Resource* ResourceSystem::createb2Resource()
{
    std::list<b2Resource*>::iterator it=b2ResourceList.insert(b2ResourceList.begin(), new b2Resource());
    (*it)->setThisPosition(it);
    return *it;
}

void ResourceSystem::destroyb2Resource(b2Resource* b2Resource_arg)
{
    b2ResourceList.erase(b2Resource_arg->getThisPosition());
    delete b2Resource_arg;
}

ALLEGRO_BITMAP* ResourceSystem::getImage(IMAGETYPE image_id)
{
    return internalImages[image_id];
}

void ResourceSystem::destroyImages()
{
    for(auto &it : internalImages)
    {
        al_destroy_bitmap(it.second);
    }
    internalImages.clear();
}

AnimatedConstructorData ResourceSystem::getData(ENTITYTYPE entity_type_id)
{
    return internalEntityAnimatedConstructorData[entity_type_id];
}

AnimatedConstructorData ResourceSystem::getData(PROJECTILETYPE projectile_type_id)
{
    return internalProjectileAnimatedConstructorData[projectile_type_id];
}

void ResourceSystem::initialize()
{
    // Fonts
    registerFont(FONTTYPE::ARIAL, arial_font);
    registerFont(FONTTYPE::FFF_TUSJ, FFF_Tusj_font);
    registerFont(FONTTYPE::FREEDOM, FREEDOM_font);
    registerFont(FONTTYPE::MONTSERRAT, Montserrat_font);
    registerFont(FONTTYPE::MONTSERRAT_B, Montserrat_B_font);
    registerFont(FONTTYPE::AMBLE, Amble_font);
    registerFont(FONTTYPE::AMBLE_B, Amble_B_font);
    registerFont(FONTTYPE::AMBLE_I, Amble_I_font);
    registerFont(FONTTYPE::AMBLE_BI, Amble_BI_font);
    registerFont(FONTTYPE::ORBITRON, Orbitron_font);
    registerFont(FONTTYPE::ORBITRON_LT, Orbitron_LT_font);
    registerFont(FONTTYPE::ORBITRON_B, Orbitron_B_font);
    // Images
    registerImage(IMAGETYPE::RECTANGLE, rectangle_spritesheet);
    registerImage(IMAGETYPE::DEFAULT_BUTTON, default_button_spritesheet);
    registerImage(IMAGETYPE::DEFAULT_BUTTON_H, default_button_h_spritesheet);
    registerImage(IMAGETYPE::DEFAULT_BUTTON_D, default_button_d_spritesheet);
    registerImage(IMAGETYPE::HP_BAR, hp_bar_spritesheet);
    registerImage(IMAGETYPE::SPRITESHEET_ENTITY_CROWBOT, player_spritesheet);
    registerImage(IMAGETYPE::SPRITESHEET_ENTITY_BATBOT, batbot_spritesheet);
    registerImage(IMAGETYPE::SPRITESHEET_PROJECTILE_BULLET, bullet_spritesheet);
    registerImage(IMAGETYPE::SPRITESHEET_PROJECTILE_MISSILE, missile_spritesheet);
    // Entity Animation Data
    /// Crowbot
    internalData(Entity)[ENTITYTYPE::CROWBOT]=AnimatedConstructorData
    (
        // Spritesheet
        getImage(IMAGETYPE::SPRITESHEET_ENTITY_CROWBOT),
        // Width
        120,
        // Height
        160,
        // Frames
        30,
        // Sequence (optional)
        // Current Sequence
        1
    );
    internalData(Entity)[ENTITYTYPE::CROWBOT].sequence
        [0]=AnimationData(0, 2, 150);
    internalData(Entity)[ENTITYTYPE::CROWBOT].sequence
        [1]=AnimationData(6, 6, 150);
    internalData(Entity)[ENTITYTYPE::CROWBOT].sequence
        [2]=AnimationData(12, 3, 150);
    internalData(Entity)[ENTITYTYPE::CROWBOT].sequence
        [3]=AnimationData(18, 3, 150);
    internalData(Entity)[ENTITYTYPE::CROWBOT].sequence
        [4]=AnimationData(24, 2, 150);
    /// Batbot
    internalData(Entity)[ENTITYTYPE::BATBOT]=AnimatedConstructorData
    (
        // Spritesheet
        getImage(IMAGETYPE::SPRITESHEET_ENTITY_BATBOT),
        // Width
        100,
        // Height
        34,
        // Frames
        1,
        // Sequence (optional)
        // Current Sequence
        0
    );
    internalData(Entity)[ENTITYTYPE::BATBOT].sequence
        [0]=AnimationData(0, 1, -1);
    // Projectile Animation Data
    /// Bullet
    internalData(Projectile)[PROJECTILETYPE::BULLET]=AnimatedConstructorData
    (
        // Spritesheet
        getImage(IMAGETYPE::SPRITESHEET_PROJECTILE_BULLET),
        // Width
        16,
        // Height
        6,
        // Frames
        1,
        // Sequence (optional)
        // Current Sequence
        0
    );
    internalData(Projectile)[PROJECTILETYPE::BULLET].sequence
        [0]=AnimationData(0, 1, -1);
    /// Missile
    internalData(Projectile)[PROJECTILETYPE::MISSILE]=AnimatedConstructorData
    (
        // Spritesheet
        getImage(IMAGETYPE::SPRITESHEET_PROJECTILE_MISSILE),
        // Width
        16,
        // Height
        6,
        // Frames
        1,
        // Sequence (optional)
        // Current Sequence
        0
    );
    internalData(Projectile)[PROJECTILETYPE::MISSILE].sequence
        [0]=AnimationData(0, 1, -1);
}

void ResourceSystem::cleanup()
{
    destroyFonts();
    destroyAudio();
    destroyImages();
}
