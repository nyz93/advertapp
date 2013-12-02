#ifndef ADVERTWINDOW_H_
#define ADVERTWINDOW_H_

#include "Screen.h"
#include "Advert.h"

class AdvertScreen : public virtual Screen
{
protected:
	Advert ad;
	AdvertScreen(const std::string & t, Advert a) : Screen(t), ad(a) {}
	AdvertScreen(const std::string & t) : Screen(t) {}
	AdvertScreen() : Screen() {}
public:
	Advert getAdvert() { return ad; }

	virtual ~AdvertScreen() {}
};

#endif // ADVERTWINDOW_H_
