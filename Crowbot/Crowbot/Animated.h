#ifndef ANIMATED_H_INCLUDED
#define ANIMATED_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"

struct AnimationData
{
    int start;
    int count;
    int time;
    AnimationData():
        start(0),
        count(0),
        time(-1)
    {
        //
    }
    AnimationData(int start_arg, int count_arg, time_t time_arg):
        start(start_arg),
        count(count_arg),
        time(time_arg)
    {
        //
    }
};

struct AnimatedConstructorData
{
    ALLEGRO_BITMAP *spritesheet;
    int ss_width;
    int ss_height;
    int ss_frames;
    int current_sequence;
    std::map<int, AnimationData> sequence;
    AnimatedConstructorData():
        spritesheet(nullptr),
        ss_width(0),
        ss_height(0),
        ss_frames(0),
        current_sequence(0),
        sequence(std::map<int, AnimationData>())
    {
        //
    }
    AnimatedConstructorData(const AnimatedConstructorData& acd_arg):
        spritesheet(acd_arg.spritesheet),
        ss_width(acd_arg.ss_width),
        ss_height(acd_arg.ss_height),
        ss_frames(acd_arg.ss_frames),
        current_sequence(acd_arg.current_sequence),
        sequence(acd_arg.sequence)
    {
        //
    }
    AnimatedConstructorData(ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, int current_sequence_arg):
        spritesheet(spritesheet_arg),
        ss_width(ss_width_arg),
        ss_height(ss_height_arg),
        ss_frames(ss_frames_arg),
        current_sequence(current_sequence_arg),
        sequence(std::map<int, AnimationData>())
    {
        //
    }
    AnimatedConstructorData(ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, std::map<int, AnimationData> sequence_arg, int current_sequence_arg):
        spritesheet(spritesheet_arg),
        ss_width(ss_width_arg),
        ss_height(ss_height_arg),
        ss_frames(ss_frames_arg),
        current_sequence(current_sequence_arg),
        sequence(sequence_arg)
    {
        //
    }
};

class Animated : public Drawable
{
private:
    AnimatedConstructorData acd;
    std::chrono::steady_clock::time_point current_time;
    int current_count;
    Rect get_current_region(int frame_arg);
public:
    Animated(ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, std::map<int, AnimationData> sequence_arg, int current_sequence_arg):
        Drawable(Rect(-10000, -10000, 10000, 10000)),
        acd(AnimatedConstructorData(spritesheet_arg, ss_width_arg, ss_height_arg, ss_frames_arg, sequence_arg, current_sequence_arg)),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    Animated(Rect rgn_arg, ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, std::map<int, AnimationData> sequence_arg, int current_sequence_arg):
        Drawable(rgn_arg),
        acd(AnimatedConstructorData(spritesheet_arg, ss_width_arg, ss_height_arg, ss_frames_arg, sequence_arg, current_sequence_arg)),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    Animated(AnimatedConstructorData acd_arg):
        Drawable(Rect(-10000, -10000, 10000, 10000)),
        acd(acd_arg),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    Animated(Rect rgn_arg, AnimatedConstructorData acd_arg):
        Drawable(rgn_arg),
        acd(acd_arg),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    void draw_current_frame(float sx, float sy, int flags);
    virtual int getCurrentSequence();
    virtual void setCurrentSequence(int current_sequence_arg);
    virtual void onDraw() override;
};

class PhysicalAnimated : public PhysicalDrawable
{
private:
    AnimatedConstructorData acd;
    std::chrono::steady_clock::time_point current_time;
    int current_count;
    Rect get_current_region(int frame_arg);
public:
    PhysicalAnimated(ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, std::map<int, AnimationData> sequence_arg, int current_sequence_arg):
        PhysicalDrawable(Rect(-10000, -10000, 10000, 10000)),
        acd(AnimatedConstructorData(spritesheet_arg, ss_width_arg, ss_height_arg, ss_frames_arg, sequence_arg, current_sequence_arg)),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    PhysicalAnimated(Rect rgn_arg, ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, std::map<int, AnimationData> sequence_arg, int current_sequence_arg):
        PhysicalDrawable(rgn_arg),
        acd(AnimatedConstructorData(spritesheet_arg, ss_width_arg, ss_height_arg, ss_frames_arg, sequence_arg, current_sequence_arg)),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    PhysicalAnimated(AnimatedConstructorData acd_arg):
        PhysicalDrawable(Rect(-10000, -10000, 10000, 10000)),
        acd(acd_arg),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    PhysicalAnimated(Rect rgn_arg, AnimatedConstructorData acd_arg):
        PhysicalDrawable(rgn_arg),
        acd(acd_arg),
        current_time(std::chrono::steady_clock::now()),
        current_count(0)
    {
        //
    }
    void draw_current_frame(float sx, float sy, int flags);
    virtual int getCurrentSequence();
    virtual void setCurrentSequence(int current_sequence_arg);
    virtual void onDraw() override;
};

#endif // ANIMATED_H_INCLUDED
