#ifndef EDITADVERTWINDOW_H_INCLUDED
#define EDITADVERTWINDOW_H_INCLUDED

#include "CancellableAction.h"
#include "NewspaperSelectionScreen.h"
#include "DateSelectionScreen.h"
#include "Screen.h"
#include "AdvertTypeSelectionScreen.h"
#include <sstream>

class EditAdvertScreen : public CancellableAction<Advert*>, public Screen
{
private:
    vector<Newspaper*> newspapers;
    const Advert* old;
public:
	EditAdvertScreen(const vector<Newspaper*>& newspapers,const Advert* a);
    virtual void show();
};

#endif // EDITADVERTWINDOW_H_INCLUDED
