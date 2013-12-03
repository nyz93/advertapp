#ifndef REVIEWADVERTWINDOW_H_INCLUDED
#define REVIEWADVERTWINDOW_H_INCLUDED

#include "AdvertScreen.h"

class ReviewAdvertScreen : public AdvertScreen
{
public:
	ReviewAdvertScreen(Advert & a);
    virtual void show();
};

#endif // REVIEWADVERTWINDOW_H_INCLUDED
