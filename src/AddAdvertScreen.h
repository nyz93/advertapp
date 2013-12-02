#ifndef ADDADVERTWINDOW_H
#define ADDADVERTWINDOW_H
#include "Advert.h"
#include "AdvertScreen.h"
#include "CancellableScreen.h"
#include "MessageScreen.h"
#include "NewspaperSelectionScreen.h"
#include "AdvertTypeSelectionScreen.h"
#include "DateSelectionScreen.h"
class AddAdvertWindow:public AdvertWindow, public CancellableWindow {
    vector<Newspaper*> newspapers;
    const User* currentUser;
    public:
    AddAdvertWindow(const vector<Newspaper*>& newspapers, const User* currentUser);
    virtual void handle();
};
#endif
