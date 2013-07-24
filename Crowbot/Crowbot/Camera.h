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
    void transformation();
    void onDraw();
    void postDraw();
public:
    std::shared_ptr<Layer> background;
    std::shared_ptr<Layer> foreground;
    std::shared_ptr<Layer> menus;
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
    void capture(ALLEGRO_BITMAP *underlyingMap);
    Camera():
        x(0),
        y(0),
        width(0),
        height(0),
        lastMouseX(0),
        lastMouseY(0)
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
        background(std::make_shared<Layer>()),
        foreground(std::make_shared<Layer>()),
        menus(std::make_shared<Layer>())
    {
        background->push(this);
        foreground->push(this);
        menus->push(this);
    }
    virtual ~Camera()
    {
        //
    }
};

#endif // CAMERA_H_INCLUDED
