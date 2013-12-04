#include "AdvertStatusSelectionScreen.h"
using namespace std;
AdvertStatusSelectionScreen::AdvertStatusSelectionScreen():Screen("Select status"){}

void AdvertStatusSelectionScreen::show() {
    bool completed = false;
    do {
        drawTitle();
        cout << "(w)aiting" << endl;
        cout << "(a)ccepted" << endl;
        cout << "(r)ejected" << endl;
        cout << endl;
        string cmd = readCommand("[w,a,r] > ");
        if(cmd == "w") {
            status = AdvertStatus::Waiting;
            completed = true;
        }else if(cmd == "a") {
            status = AdvertStatus::Accepted;
            completed = true;
        }else if(cmd == "r") {
            status = AdvertStatus::Rejected;
            completed = true;
        }
    }while(!completed);
}

AdvertStatus AdvertStatusSelectionScreen::getStatus() const {
    return status;
}
