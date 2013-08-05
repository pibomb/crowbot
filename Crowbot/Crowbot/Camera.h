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
    std::function<Pixel()> translateFunction;
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    Layer *background;
    Layer *midground;
    Layer *foreground;
    Camera();
    Camera(int x_arg, int y_arg, int width_arg, int height_arg, int mouseX_arg, int mouseY_arg);
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
    Rect getRegion();
    void moveMouse(int newX, int newY);
    void setCustomTranslate(std::function<Pixel()> customTranslate_arg);
    void setNormalTranslate();
};

#endif // CAMERA_H_INCLUDED
