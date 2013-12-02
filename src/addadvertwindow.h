#ifndef ADDADVERTWINDOW_H
#define ADDADVERTWINDOW_H
#include "advert.h"
#include "advertwindow.h"
#include "cancellablewindow.h"
#include "messagewindow.h"
#include "newspaperselectionwindow.h"
#include "adverttypeselectionwindow.h"
#include "dateselectionwindow.h"
class AddAdvertWindow:public AdvertWindow, public CancellableWindow {
    vector<Newspaper*> newspapers;
    const User* currentUser;
    public:
    AddAdvertWindow(const vector<Newspaper*>& newspapers, const User* currentUser);
    virtual void handle();
};
#endif
