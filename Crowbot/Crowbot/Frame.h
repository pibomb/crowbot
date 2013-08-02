#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include "basicresource.h"
#include "Pixel.h"
#include "Drawable.h"
#include "Camera.h"
#include "Counter.h"
#include "Button.h"
#include "GlobalVariables.h"

class Observer;

class Frame : public Drawable
{
private:
    FRAMETYPE id;
    int mapID;
    int frames_per_second;
    bool valid;
#ifdef ENET_ENABLED
    bool enet;
    bool peer_valid;
    ENETSTATE enet_state;
#endif
    Rect region;
    ALLEGRO_USTR *input;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_MOUSE_STATE cursorState;
#ifdef ENET_ENABLED
    ENetAddress address;
    ENetHost *host;
    ENetEvent enet_event;
    ENetPeer *peer;
#endif
    Camera *camera;
    Button *activeButton;
    std::list<Button*> buttons;
    std::vector<bool> key;
    std::map<MOUSEBUTTON, bool> mouse;
    std::list<std::pair<std::function<bool(FRAMETYPE)>, std::function<void()>>> onRestart;
    std::list<Observer*> observers;
    std::map<Observer*, std::list<Observer*>::iterator> observerIters;
    void onLeftUp();
    void onLeftClick();
    void transformation() override;
    void onDraw() override;
    void postDraw() override;
public:
    FRAMETYPE getID();
    void setID(FRAMETYPE id_arg);
    void update();
    Camera* getCamera();
    void setCamera(Camera *camera_arg);
    int getX(int x_arg);
    int getY(int y_arg);
    Rect getRegion();
    void addButton(Button *button_arg);
    void addOnRestart(std::function<bool(FRAMETYPE)> ifThis, std::function<void()> thenThis);
    void addObserver(Observer *observer_arg);
    void removeObserver(Observer *observer_arg);
#ifdef ENET_ENABLED
    bool startLANConnection();
    void endLANConnection();
    bool validatePeer(ENetPacket *packet);
    void sendInfo(std::string message, bool validate=false);
    void recvInfo(ENetPacket *packet);
    bool isConnectedOverLAN();
#endif
    void delayTime(float delay_arg);
    void start(FRAMETYPE id_arg);
    void end();
    void destroy();
    void restart(Rect region_arg=Rect(0, 0, disp_data.width, disp_data.height), int mapid_arg=1, FRAMETYPE id_arg=FRAMETYPE::INVALID);
    operator bool() const
    {
        return valid;
    }
    Frame(Rect region_arg=Rect(0, 0, disp_data.width, disp_data.height), int mapid_arg=1):
        mapID(mapid_arg),
        frames_per_second(60),
        valid(true),
#ifdef ENET_ENABLED
        enet(false),
        peer_valid(false),
        enet_state(ENETSTATE::IS_INVALID),
#endif
        region(region_arg),
        input(al_ustr_new("")),
        event_queue(nullptr),
        timer(nullptr),
#ifdef ENET_ENABLED
        host(nullptr),
        peer(nullptr),
#endif
        camera(new Camera(0, 0, region.getWidth(), region.getHeight(), 0, 0)),
        activeButton(nullptr)
    {
        camera->push(this);
    }
    virtual ~Frame()
    {
        //
    }
};

#endif // FRAME_H_INCLUDED
