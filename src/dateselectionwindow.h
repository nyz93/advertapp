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
    virtual void handle() {
        int day = date.getDay();
        int month = date.getMonth();
        int year = date.getYear();
        bool completed = false;
        do {
            cancelled = false;
            drawTitle();
            cout << "(y)ear: " << year << endl;
            cout << "(m)onth: " << month << endl;
            cout << "(d)ay: " << day << endl;
            cout << "(f)inish selection" << endl;
            cout << "(c)ancel selection" << endl;
            string cmd = readCommand("[y,m,f,c] > ");
            if(cmd == "y") {
                string y = readCommand("year > ");
                stringstream conv(y);
                conv >> year;
            }
            else if(cmd == "m") {
                string m = readCommand("month > ");
                stringstream conv(m);
                conv >> month;
            }
            else if(cmd == "d") {
                string d = readCommand("day > ");
                stringstream conv(d);
                conv >> day;
            }
            else if(cmd == "f") {
                Date test = Date(year,month,day);
                if(!test.isValid()) {
                    MessageWindow msg("Not valid date!");
                    msg.handle();
                }else{
                    date = test;
                    completed = true;
                }
            }else if(cmd == "c") {
                completed = true;
                cancelled = true;
            }
        }while(!completed);
    }
    const Date& getDate() const {
        return date;
    }
};
#endif
