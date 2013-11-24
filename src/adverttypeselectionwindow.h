#ifndef _ADVERTTYPESELECTIONWINDOW_H_
#define _ADVERTTYPESELECTIONWINDOW_H_
#include "window.h"
#include "advert.h"
#include <iostream>
using namespace std;
class AdvertTypeSelectionWindow: Window {
    AdvertType type;
    public:
    AdvertTypeSelectionWindow():Window("Select advert type") {}
    AdvertType getType() const {
        return type;
    }
    virtual void handle() {
        bool complete = false;
        do {
            cout << "(i)mage advert" << endl;
            cout << "(t)ext advert" << endl;
            cout << "(t)ext (i)mage advert" << endl;
            string cmd = readCommand("[i,t,ti] > ");
            if(cmd == "i") {
                type = AdvertType::Image;
                complete = true;
            }else if(cmd == "t") {
                type = AdvertType::Text;
                complete = true;
            }else if(cmd == "ti") {
                type = AdvertType::TextImage;
                complete = true;
            }
        }while(!complete);
    }
};
#endif
