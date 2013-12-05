#ifndef ADDNEWSPAPERSCREEN_H
#define ADDNEWSPAPERSCREEN_H
#include <sstream>
#include "CancellableAction.h"
#include "Newspaper.h"
#include "Screen.h"
class AddNewspaperScreen: public Screen, public CancellableAction<Newspaper*> {
    public:
        AddNewspaperScreen();
        virtual void show();
        virtual ~AddNewspaperScreen();
};
#endif
