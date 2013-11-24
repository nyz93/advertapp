#ifndef REVIEWADVERTWINDOW_H_INCLUDED
#define REVIEWADVERTWINDOW_H_INCLUDED

#include "advertwindow.h"

class ReviewAdvertWindow : public AdvertWindow
{
private:

public:
	ReviewAdvertWindow(Advert & a) : AdvertWindow("Review advert", a) {}
};

#endif // REVIEWADVERTWINDOW_H_INCLUDED
