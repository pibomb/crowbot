#include "resource.h"

Rect Animated::get_current_region(int frame_arg)
{
    int x=(frame_arg%(al_get_bitmap_width(acd.spritesheet)/acd.ss_width))*acd.ss_width, y=(frame_arg/(al_get_bitmap_width(acd.spritesheet)/acd.ss_width))*acd.ss_height;
    return Rect(x, y, x+acd.ss_width, y+acd.ss_height);
}

void Animated::draw_current_frame(float sx, float sy, int flags)
{
    if(std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now()-current_time).count()*1000>=acd.sequence[acd.current_sequence].time)
    {
        current_time=std::chrono::steady_clock::now();
        current_count=(current_count+1)%acd.sequence[acd.current_sequence].count;
    }
    Rect region=get_current_region(acd.sequence[acd.current_sequence].start+current_count);
    al_draw_bitmap_region(acd.spritesheet, region.getTL().getX(), region.getTL().getY(), region.getWidth(), region.getHeight(), sx, sy, flags);
}

int Animated::getCurrentSequence()
{
    return acd.current_sequence;
}

void Animated::setCurrentSequence(int current_sequence_arg)
{
    acd.current_sequence=current_sequence_arg;
    current_time=std::chrono::steady_clock::now();
    current_count=0;
}

void Animated::onDraw()
{
    draw_current_frame(0, 0, 0);
}

Rect PhysicalAnimated::get_current_region(int frame_arg)
{
    int x=(frame_arg%(al_get_bitmap_width(acd.spritesheet)/acd.ss_width))*acd.ss_width, y=(frame_arg/(al_get_bitmap_width(acd.spritesheet)/acd.ss_width))*acd.ss_height;
    return Rect(x, y, x+acd.ss_width, y+acd.ss_height);
}

void PhysicalAnimated::draw_current_frame(float sx, float sy, int flags)
{
    if(std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now()-current_time).count()*1000>=acd.sequence[acd.current_sequence].time)
    {
        current_time=std::chrono::steady_clock::now();
        current_count=(current_count+1)%acd.sequence[acd.current_sequence].count;
    }
    Rect region=get_current_region(acd.sequence[acd.current_sequence].start+current_count);
    al_draw_bitmap_region(acd.spritesheet, region.getTL().getX(), region.getTL().getY(), region.getWidth(), region.getHeight(), sx, sy, flags);
}

int PhysicalAnimated::getCurrentSequence()
{
    return acd.current_sequence;
}

void PhysicalAnimated::setCurrentSequence(int current_sequence_arg)
{
    acd.current_sequence=current_sequence_arg;
    current_time=std::chrono::steady_clock::now();
    current_count=0;
}

void PhysicalAnimated::onDraw()
{
    draw_current_frame(0, 0, 0);
}
