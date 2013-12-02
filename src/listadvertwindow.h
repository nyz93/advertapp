#ifndef LISTADVERTWINDOW_H
#define LISTADVERTWINDOW_H
#include "window.h"
#include "advert.h"
#include <vector>
using namespace std;
class ListAdvertWindow :Window {
    vector<const Advert*> adverts;
    public:
    ListAdvertWindow(const vector<const Advert*>& adverts):Window("Adverts"), adverts(adverts){
    }
    virtual void handle() {
        bool completed = false;
        do{
            drawTitle();
            for(auto ad: adverts) {
                cout << ad->getName() << endl;
            }
            cout << "(b)ack" << endl;
            string cmd = readCommand("[b] > ");
            if(cmd == "b") {
                completed = true;
            }
        }while(!completed);
    }
};
#endif
