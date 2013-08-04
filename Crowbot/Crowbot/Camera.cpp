#include "resource.h"

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

void Camera::moveMouse(int newX, int newY)
{
    x+=newX-lastMouseX;
    y+=newY-lastMouseY;
    lastMouseX=newX;
    lastMouseY=newY;
}

void Camera::setCustomTranslate(std::function<void(Camera*)> customTranslate_arg)
{
    translateFunction=customTranslate_arg;
}

void Camera::setNormalTranslate()
{
    translateFunction=[](Camera* camera_arg){camera_arg->postset().postTranslate(camera_arg->getX(), camera_arg->getY());};
}

void Camera::transformation()
{
    translateFunction(this);
}

void Camera::onDraw()
{
    //al_clear_to_color(AL_COL_BLACK);
}

void Camera::postDraw()
{
    //
}
