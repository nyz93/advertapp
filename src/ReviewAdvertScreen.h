#ifndef REVIEWADVERTWINDOW_H_INCLUDED
#define REVIEWADVERTWINDOW_H_INCLUDED

#include "Advert.h"
#include "CancellableAction.h"
#include "AdvertStatusSelectionScreen.h"

class ReviewAdvertScreen : public Screen, public CancellableAction<AdvertStatus>
{
    const Advert* old;
public:
	ReviewAdvertScreen(const Advert* old);
    virtual void show();
};

#endif // REVIEWADVERTWINDOW_H_INCLUDED
