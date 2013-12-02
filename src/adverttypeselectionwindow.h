#ifndef ADVERTTYPESELECTIONWINDOW_H
#define ADVERTTYPESELECTIONWINDOW_H
#include "window.h"
#include "advert.h"
#include <iostream>
using namespace std;
class AdvertTypeSelectionWindow: public Window {
    AdvertType type;
    public:
    AdvertTypeSelectionWindow():Window("Select advert type") {}
    AdvertType getType() const;
    virtual void handle();
};
#endif
