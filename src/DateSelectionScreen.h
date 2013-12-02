#ifndef DATESELECTIONWINDOW_H
#define DATESELECTIONWINDOW_H
#include "CancellableWindow.h"
#include "Date.h"
#include "MessageScren.h"
#include <iostream>
#include <sstream>
using namespace std;
class DateSelectionScreen : public CancellableScreen {
    Date date;
    public:
    DateSelectionWindow(const Date& date): date(date) {}
    virtual void show();
    const Date& getDate() const;
};
#endif
