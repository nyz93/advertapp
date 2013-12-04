#ifndef REVIEWADVERTWINDOW_H_INCLUDED
#define REVIEWADVERTWINDOW_H_INCLUDED

#include "AdvertScreen.h"

class ReviewAdvertScreen : public AdvertScreen
{
    const Advert* old;
public:
	ReviewAdvertScreen(const Advert* old);
    virtual void show();
};

#endif // REVIEWADVERTWINDOW_H_INCLUDED
