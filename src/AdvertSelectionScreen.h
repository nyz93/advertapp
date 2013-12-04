#ifndef SELECTADVERTSCREEN_H
#define SELECTADVERTSCREEN_H
#include <vector>
#include <sstream>
#include "CancellableScreen.h"
#include "AdvertScreen.h"
class AdvertSelectionScreen: public CancellableScreen, public AdvertScreen
{
    std::vector<Advert*> adverts;
    Advert* selection;
    bool showUser;
public:
    AdvertSelectionScreen (const std::vector<Advert*>& ads, bool showUser);
    virtual ~AdvertSelectionScreen();
    virtual void show();
    Advert* getSelection() const;
};
#endif
