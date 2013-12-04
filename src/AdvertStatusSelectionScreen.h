#ifndef ADVERTSTATUSSELECTIONSCREEN_H
#define ADVERTSTATUSSELECTIONSCREEN_H
#include "Screen.h"
#include "AdvertEnum.h"
class AdvertStatusSelectionScreen:public Screen {
    AdvertStatus status;
    public:
        AdvertStatusSelectionScreen();
        virtual void show(); 
        AdvertStatus getStatus() const;
};
#endif
