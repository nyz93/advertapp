#ifndef DATESELECTIONWINDOW_H
#define DATESELECTIONWINDOW_H
#include "cancellablewindow.h"
#include "date.h"
#include "messagewindow.h"
#include <iostream>
#include <sstream>
using namespace std;
class DateSelectionWindow : public CancellableWindow {
    Date date;
    public:
    DateSelectionWindow(const Date& date): date(date) {}
    virtual void handle();
    const Date& getDate() const;
};
#endif
