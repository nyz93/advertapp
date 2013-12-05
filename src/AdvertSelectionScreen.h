#ifndef SELECTADVERTSCREEN_H
#define SELECTADVERTSCREEN_H
#include <vector>
#include <sstream>
#include "Advert.h"
#include "Screen.h"
#include "CancellableAction.h"
class AdvertSelectionScreen: public Screen, public CancellableAction<Advert*>
{
    std::vector<Advert*> adverts;
    bool showUser;
public:
    AdvertSelectionScreen (const std::vector<Advert*>& ads, bool showUser);
    virtual ~AdvertSelectionScreen();
    virtual void show();
};
#endif
