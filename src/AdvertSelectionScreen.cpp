#include "AdvertSelectionScreen.h"

AdvertSelectionScreen::AdvertSelectionScreen(const std::vector<Advert*>& ads,bool showUser):CancellableScreen("Select advert"), adverts(ads), showUser(showUser) {}

AdvertSelectionScreen::~AdvertSelectionScreen() {}

void AdvertSelectionScreen::show() {
    bool completed = false;
    while(!completed) {
        drawTitle();
        cancelled = false;
        stringstream ss;
        for(unsigned i = 0; i < adverts.size(); i++) {
            cout << "(" << i+1 << ") " << adverts[i]->getName();
            if(showUser) {
                cout << " " << adverts[i]->getCreator()->getName();
            }
            cout << endl;
        }
        cout << endl;
        cout << "(c)ancel" << endl;
        ss << "[1-" << adverts.size()-1 << ",c] > ";
        string cmdline = ss.str();
        string cmd = readCommand(cmdline);
        if(cmd == "c") {
            cancelled = true;
            completed = true;
        } else {
            int id = 0;
            stringstream conv;
            conv << cmd;
            conv >> id;
            if(id > 0 && id < (int)adverts.size()+1) {
                ad = adverts[id-1];
                completed = true;
            }
        }
    }
}
