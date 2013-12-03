#ifndef DATESELECTIONWINDOW_H
#define DATESELECTIONWINDOW_H
#include "CancellableScreen.h"
#include "Date.h"
#include "MessageScreen.h"
#include <iostream>
#include <sstream>
using namespace std;
class DateSelectionScreen : public CancellableScreen {
    Date date;
    public:
    DateSelectionScreen(const Date& date): CancellableScreen("Select date"), date(date) {}
    virtual void show();
    const Date& getDate() const;
};
#endif
