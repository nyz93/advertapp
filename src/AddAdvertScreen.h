#ifndef ADDADVERTWINDOW_H
#define ADDADVERTWINDOW_H
#include "Advert.h"
#include "AdvertScreen.h"
#include "CancellableScreen.h"
#include "MessageScreen.h"
#include "NewspaperSelectionScreen.h"
#include "AdvertTypeSelectionScreen.h"
#include "DateSelectionScreen.h"
class AddAdvertScreen:public AdvertWindow, public CancellableWindow {
    vector<Newspaper*> newspapers;
    const User* currentUser;
    public:
    AddAdvertScreen(const vector<Newspaper*>& newspapers, const User* currentUser);
    virtual void show();
};
#endif
