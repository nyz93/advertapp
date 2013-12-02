#ifndef LISTADVERTWINDOW_H
#define LISTADVERTWINDOW_H
#include "Screen.h"
#include "Advert.h"
#include <vector>
using namespace std;
class ListAdvertScreen : public Screen {
    vector<const Advert*> adverts;
    public:
    ListAdvertScreen(const vector<const Advert*>& adverts);
    virtual void show();
};
#endif
