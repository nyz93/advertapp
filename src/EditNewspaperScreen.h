#ifndef EDITNEWSPAPERSCREEN_H
#define EDITNEWSPAPERSCREEN_H
#include <sstream>
#include "Screen.h"
#include "Newspaper.h"
#include "CancellableAction.h"
class EditNewspaperScreen: public Screen, public CancellableAction<Newspaper*> {
    const Newspaper* old;
    public:
    EditNewspaperScreen(const Newspaper*);
    virtual void show();
    virtual ~EditNewspaperScreen();
};
#endif
