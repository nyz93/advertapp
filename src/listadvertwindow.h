#ifndef LISTADVERTWINDOW_H
#define LISTADVERTWINDOW_H
#include "window.h"
#include "advert.h"
#include <vector>
using namespace std;
class ListAdvertWindow : public Window {
    vector<const Advert*> adverts;
    public:
    ListAdvertWindow(const vector<const Advert*>& adverts);
    virtual void handle();
};
#endif
