#ifndef ADVERTTYPESELECTIONWINDOW_H
#define ADVERTTYPESELECTIONWINDOW_H
#include "Screen.h"
#include "Advert.h"
#include <iostream>
using namespace std;
class AdvertTypeSelectionScreen: public Screen {
    AdvertType type;
    public:
    AdvertTypeSelectionScreen():Screen("Select advert type") {}
    AdvertType getType() const;
    virtual void show();
};
#endif
