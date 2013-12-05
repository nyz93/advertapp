#include "ReviewAdvertScreen.h"

ReviewAdvertScreen::ReviewAdvertScreen(const Advert* old) : Screen("Review advert"),old(old) {}

void ReviewAdvertScreen::show() {
    bool completed = false;
    result = old->getStatus();
    do {
        cancelled = false;
        drawTitle();
        cout << "name: " << old->getName() << endl;
        cout << "type: ";
        switch(old->getType()) {
            case AdvertType::Text:
                cout << "text" << endl; break;
                cout << "text:" << old->getText() << endl;
            case AdvertType::TextImage:
                cout << "text-image" << endl; break;
                cout << "text: " << old->getText() << endl;
                cout << "image: " << old->getImage() << endl; 
            case AdvertType::Image:
                cout << "image" << endl; break;
                cout << "image: " << old->getImage() << endl; 
        }
        cout << "(s)tatus: ";
        switch(result) {
            case AdvertStatus::Waiting:
                cout << "waiting" << endl; break;
            case AdvertStatus::Accepted:
                cout << "accepted" << endl; break;
            case AdvertStatus::Rejected:
                cout << "rejected" << endl; break;
        }
        cout << "(c)ancel" << endl << "(f)inish" << endl;
        string cmd = readCommand("[s,c,f] > ");
        if(cmd == "s") {
            AdvertStatusSelectionScreen ssw;
            ssw.show();
            result = ssw.getStatus();
        }else if(cmd == "f") {
            completed = true;
        }else if(cmd == "c") {
            cancelled = true;
            completed = true;
        }
    }while(!completed);
}
