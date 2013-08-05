#include "resource.h"

Camera::Camera():
    Drawable(),
    x(0),
    y(0),
    width(0),
    height(0),
    lastMouseX(0),
    lastMouseY(0),
    translateFunction([]() -> Pixel
                      {
                          return Pixel(0, 0);
                      }
                      ),
    background(nullptr),
    midground(nullptr),
    foreground(nullptr)
{
    //
}

Camera::Camera(int x_arg, int y_arg, int width_arg, int height_arg, int mouseX_arg, int mouseY_arg):
    Drawable(Rect(0, 0, width_arg, height_arg)),
    x(x_arg),
    y(y_arg),
    width(width_arg),
    height(height_arg),
    lastMouseX(mouseX_arg),
    lastMouseY(mouseY_arg),
    translateFunction([this]() -> Pixel
                        {
                            return Pixel(getX(), getY());
                        }),
    background(new Layer),
    midground(new Layer),
    foreground(new Layer)
{
    background->push(this);
    midground->push(this);
    foreground->push(this);
}

int Camera::getX()
{
    return x;
}

void Camera::setX(int x_arg)
{
    x=x_arg;
}

int Camera::getY()
{
    return y;
}

void Camera::setY(int y_arg)
{
    y=y_arg;
}

int Camera::getWidth()
{
    return width;
}

void Camera::setWidth(int width_arg)
{
    width=width_arg;
}

int Camera::getHeight()
{
    return height;
}

void Camera::setHeight(int height_arg)
{
    height=height_arg;
}

void Camera::setSize(int width_arg, int height_arg)
{
    setWidth(width_arg);
    setHeight(height_arg);
}

int Camera::getMouseX()
{
    return lastMouseX;
}

void Camera::setMouseX(int mouseX_arg)
{
    lastMouseX=mouseX_arg;
}

int Camera::getMouseY()
{
    return lastMouseY;
}

void Camera::setMouseY(int mouseY_arg)
{
    lastMouseY=mouseY_arg;
}

int Camera::getAbsX(int curX)
{
    return curX-x;
}

int Camera::getAbsY(int curY)
{
    return curY-y;
}

Rect Camera::getRegion()
{
    Pixel newtl=translateFunction();
    return Rect(newtl.getX(), newtl.getY(), newtl.getX()+getWidth(), newtl.getY()+getHeight());
}

void Camera::moveMouse(int newX, int newY)
{
    x+=newX-lastMouseX;
    y+=newY-lastMouseY;
    lastMouseX=newX;
    lastMouseY=newY;
}

void Camera::setCustomTranslate(std::function<Pixel()> customTranslate_arg)
{
    translateFunction=customTranslate_arg;
}

void Camera::setNormalTranslate()
{
    translateFunction=[this]() -> Pixel
                        {
                            return Pixel(getX(), getY());
                        };
}

void Camera::transformation()
{
    Pixel px=translateFunction();
    postset().postTranslate(-px.getX(), -px.getY());
}

void Camera::onDraw()
{
    //al_clear_to_color(AL_COL_BLACK);
}

void Camera::postDraw()
{
    //
}
