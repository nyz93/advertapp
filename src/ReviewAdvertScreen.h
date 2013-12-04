#ifndef REVIEWADVERTWINDOW_H_INCLUDED
#define REVIEWADVERTWINDOW_H_INCLUDED

#include "Advert.h"
#include "CancellableScreen.h"
#include "AdvertStatusSelectionScreen.h"

class ReviewAdvertScreen : public CancellableScreen
{
    const Advert* old;
    AdvertStatus result;
public:
	ReviewAdvertScreen(const Advert* old);
    virtual void show();
    AdvertStatus getResult() {
        return result;
    }
};

#endif // REVIEWADVERTWINDOW_H_INCLUDED
