#ifndef ADVERTWINDOW_H_
#define ADVERTWINDOW_H_

#include "window.h"
#include "advert.h"

class AdvertWindow : public virtual Window
{
protected:
	Advert ad;
	AdvertWindow(const std::string & t, Advert a) : Window(t), ad(a) {}
	AdvertWindow(const std::string & t) : Window(t) {}
	AdvertWindow() : Window() {}
public:
	Advert getAdvert() { return ad; }

	virtual ~AdvertWindow() {}
};

#endif // ADVERTWINDOW_H_
