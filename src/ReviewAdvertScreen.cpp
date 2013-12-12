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
                cout << "text" << endl;
                cout << "text:" << old->getText() << endl; break;
            case AdvertType::TextImage:
                cout << "text-image" << endl;
                cout << "text: " << old->getText() << endl;
                cout << "image: " << old->getImage() << endl; break;
            case AdvertType::Image:
                cout << "image" << endl;
                cout << "image: " << old->getImage() << endl; break;
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
