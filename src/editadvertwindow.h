#ifndef EDITADVERTWINDOW_H_INCLUDED
#define EDITADVERTWINDOW_H_INCLUDED

#include "advertwindow.h"

class EditAdvertWindow : public AdvertWindow
{
private:

public:
	EditAdvertWindow(Advert a) : AdvertWindow("Edit advertisment", a) {}
}

#endif // EDITADVERTWINDOW_H_INCLUDED