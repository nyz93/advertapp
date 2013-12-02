#ifndef LISTADVERTWINDOW_H
#define LISTADVERTWINDOW_H
#include "Screen.h"
#include "Advert.h"
#include <vector>
using namespace std;
class ListAdvertScreen :Screen {
    vector<const Advert*> adverts;
    public:
    ListAdvertScreen(const vector<const Advert*>& adverts):Screen("Adverts"), adverts(adverts){
    }
    virtual void show() {
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
