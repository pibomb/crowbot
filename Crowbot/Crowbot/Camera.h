#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "basicresource.h"
#include "Pixel.h"
#include "Drawable.h"
#include "Layer.h"

class Camera : public Drawable
{
private:
    int x, y;
    int width, height;
    int lastMouseX, lastMouseY;
    std::function<void(Camera*)> translateFunction;
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    Layer *background;
    Layer *midground;
    Layer *foreground;
    Camera():
        x(0),
        y(0),
        width(0),
        height(0),
        lastMouseX(0),
        lastMouseY(0),
        translateFunction([](Camera*){}),
        background(nullptr),
        midground(nullptr),
        foreground(nullptr)
    {
        //
    }
    Camera(int x_arg, int y_arg, int width_arg, int height_arg, int mouseX_arg, int mouseY_arg):
        x(x_arg),
        y(y_arg),
        width(width_arg),
        height(height_arg),
        lastMouseX(mouseX_arg),
        lastMouseY(mouseY_arg),
        translateFunction([](Camera* camera_arg){camera_arg->preset().preTranslate(camera_arg->getX(), camera_arg->getY());}),
        background(new Layer),
        midground(new Layer),
        foreground(new Layer)
    {
        background->push(this);
        midground->push(this);
        foreground->push(this);
    }
    virtual ~Camera()
    {
        if(background)
        {
            delete background;
        }
        if(midground)
        {
            delete midground;
        }
        if(foreground)
        {
            delete foreground;
        }
    }
    int getX();
    void setX(int x_arg);
    int getY();
    void setY(int y_arg);
    int getWidth();
    void setWidth(int width_arg);
    int getHeight();
    void setHeight(int height_arg);
    void setSize(int width_arg, int height_arg);
    int getMouseX();
    void setMouseX(int mouseX_arg);
    int getMouseY();
    void setMouseY(int mouseY_arg);
    int getAbsX(int curX);
    int getAbsY(int curY);
    void moveMouse(int newX, int newY);
    void setCustomTranslate(std::function<void(Camera*)> customTranslate_arg);
    void setNormalTranslate();
};

#endif // CAMERA_H_INCLUDED
