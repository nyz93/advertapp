#ifndef DATESELECTIONWINDOW_H
#define DATESELECTIONWINDOW_H
#include "CancellableAction.h"
#include "Date.h"
#include "Screen.h"
#include "MessageScreen.h"
#include <iostream>
#include <sstream>
using namespace std;
class DateSelectionScreen : public Screen, public CancellableAction<Date> {
    public:
    DateSelectionScreen(const Date& date);
    virtual void show();
};
#endif
