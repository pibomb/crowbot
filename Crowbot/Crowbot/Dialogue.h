#ifndef DIALOGUE_H_INCLUDED
#define DIALOGUE_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"

class Page : public Drawable
{
private:
    FONTTYPE font_id;
    int fontSize;
    float x_offset;
    float y_offset;
    std::vector<std::string> lines;
    void evaluate(Rect bounding_box, std::string& input);
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    Page(FONTTYPE font_id_arg, int fontSize_arg, float x_offset_arg, float y_offset_arg, Rect bounding_box, std::string& input);
};

class Dialogue : public Drawable
{
private:
    ALLEGRO_BITMAP *left;
    ALLEGRO_BITMAP *right;
    ALLEGRO_BITMAP *name_background;
    ALLEGRO_BITMAP *background;
    ALLEGRO_EVENT_QUEUE *event_queue;
    Rect bounding_box;
    std::vector<Page> pages;
    std::vector<std::string> owners;
    std::function<void()> onExit;
    std::function<void()> onShutdown;
    int currentPage;
    FONTTYPE fontID;
    int fontSize;
    float x_offset;
    float y_offset;
    void evaluate(std::string text);
    RETURNTYPE retreatText();
    RETURNTYPE advanceText();
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    Dialogue(Rect bounding_box_arg, std::function<void()> onExit_arg, std::function<void()> onShutdown_arg, ALLEGRO_BITMAP *left_arg, ALLEGRO_BITMAP *right_arg, ALLEGRO_BITMAP *name_background_arg, ALLEGRO_BITMAP *background_arg, ALLEGRO_EVENT_QUEUE *event_queue_arg, FONTTYPE fontID_arg, int fontSize_arg, float x_offset_arg, float y_offset_arg, std::string text_arg);
    RETURNTYPE update();
    RETURNTYPE run();
    void stop();
};

#endif // DIALOGUE_H_INCLUDED
