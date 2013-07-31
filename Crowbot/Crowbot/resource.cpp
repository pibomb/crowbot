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

void b2Resource::registerChainShape(void *userData_arg, b2Vec2 bodyDef_position_arg, std::vector<b2Vec2> chainPoints)
{
    b2BodyDef bodyDef;
    bodyDef.position=bodyDef_position_arg;
    body=world.CreateBody(&bodyDef);
    b2ChainShape shape;
    shape.CreateChain(&chainPoints[0], chainPoints.size());
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&shape;
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

void b2Resource::registerDynamicBox(void *userData_arg, b2Vec2 bodyDef_position_arg, float length_arg, float width_arg, float density_arg, float friction_arg)
{
    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
    bodyDef.position=bodyDef_position_arg;
    body=world.CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(length_arg/2, width_arg/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&shape;
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

void ResourceSystem::registerImage(IMAGETYPE image_id, std::string directory)
{
    internalImages[image_id]=al_load_bitmap(directory.c_str());
}

ALLEGRO_BITMAP* ResourceSystem::getImage(IMAGETYPE image_id)
{
    return internalImages[image_id];
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
    registerImage(IMAGETYPE::INVALID, "images/robot.png");
    registerImage(IMAGETYPE::RECTANGLE, "images/rectangle.png");
    registerImage(IMAGETYPE::DEFAULT_BUTTON, "images/btn_background.png");
    registerImage(IMAGETYPE::DEFAULT_BUTTON_H, "images/btn_background_h.png");
    registerImage(IMAGETYPE::DEFAULT_BUTTON_D, "images/btn_background_d.png");
    registerImage(IMAGETYPE::SPRITESHEET_ENTITY_CROWBOT, "images/player.png");
    registerImage(IMAGETYPE::SPRITESHEET_PROJECTILE_BULLET, "images/slime_soldier_final.png");
    // Entity Animation Data
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
    // Projectile Animation Data
    internalData(Projectile)[PROJECTILETYPE::BULLET]=AnimatedConstructorData
    (
        // Spritesheet
        getImage(IMAGETYPE::SPRITESHEET_PROJECTILE_BULLET),
        // Width
        100,
        // Height
        80,
        // Frames
        15,
        // Sequence (optional)
        // Current Sequence
        0
    );
    internalData(Projectile)[PROJECTILETYPE::BULLET].sequence
        [0]=AnimationData(4, 11, 150);
}

void ResourceSystem::cleanup()
{
    destroyFonts();
    destroyAudio();
}
