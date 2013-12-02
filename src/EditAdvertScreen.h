#ifndef EDITADVERTWINDOW_H_INCLUDED
#define EDITADVERTWINDOW_H_INCLUDED

#include "AdvertScreen.h"

class EditAdvertScreen : public AdvertScreen
{
private:

public:
	EditAdvertScreen(Advert a) : AdvertScreen("Edit advertisment", a) {}
}

#endif // EDITADVERTWINDOW_H_INCLUDED
