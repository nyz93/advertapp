#ifndef REVIEWADVERTWINDOW_H_INCLUDED
#define REVIEWADVERTWINDOW_H_INCLUDED

#include "AdvertScreen.h"

class ReviewAdvertScreen : public AdvertScreen
{
private:

public:
	ReviewAdvertScreen(Advert & a) : AdvertScreen("Review advert", a) {}
};

#endif // REVIEWADVERTWINDOW_H_INCLUDED