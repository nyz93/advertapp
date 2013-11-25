#ifndef _ADDADVERTWINDOW_H_
#define _ADDADVERTWINDOW_H_
#include "advert.h"
#include "advertwindow.h"
#include "cancellablewindow.h"
#include "messagewindow.h"
#include "newspaperselectionwindow.h"
#include "adverttypeselectionwindow.h"
#include "dateselectionwindow.h"
class AddAdvertWindow:public AdvertWindow, public CancellableWindow {
    vector<Newspaper*> newspapers;
    const User* currentUser;
    public:
    AddAdvertWindow(const vector<Newspaper>& newspapers, const User* currentUser):AdvertWindow("Add advert"), currentUser(currentUser){
        for(auto np : newspapers) {
            this->newspapers.push_back(&np);
        }
    }
    virtual void handle() {
        drawTitle();
        bool complete = false;
        AdvertTypeSelectionWindow ts;
        ts.handle();
        string name;
        string image;
        string text;
        vector<Newspaper*> selection;
        Date validUntil;
        bool dateSet = false;
        do {
            Advert tmpad;
            bool canSend = false;
            stringstream cmdline;
            drawTitle();
            cout << "(n)ame: " << name << endl;
            cmdline << ",n";
            switch(ts.getType()) {
                case AdvertType::Image: {
                    cout << "(i)mage: " << image << endl;
                    cmdline << ",i";
                    if(image != "" && name != "" && selection.size() && dateSet) {
                        canSend = true;
                    }
                }break;
                case AdvertType::Text: {
                    cout << "(t)ext: " << text << endl;
                    cmdline << ",t";
                    if(text != "" && name != "" && selection.size() && dateSet) {
                        canSend = true;
                    }
                }break;
                case AdvertType::TextImage: {
                    cout << "(t)ext: " << text << endl;
                    cout << "(i)mage: " << image << endl;
                    cmdline << ",t,i";
                    if(text != "" && image != "" && name != "" && selection.size() && dateSet) {
                        canSend = true;
                    }
                }break;
            }
            cout << "(s)et expiration (d)ate" << endl;
            cmdline << ",sd";
            cout << "(s)elect (n)newspapers" << endl;
            cmdline << ",sn";
            if(canSend) {
                switch(ts.getType()) {
                    case AdvertType::Image: {
                        tmpad = Advert::imageAdvert(name,image,currentUser,validUntil,selection);
                    }break;
                    case AdvertType::Text: {
                        tmpad = Advert::textAdvert(name,text,currentUser,validUntil,selection);
                    }break;
                    case AdvertType::TextImage: {
                        tmpad = Advert::textImageAdvert(name,text,image,currentUser,validUntil,selection);
                    }break;
                }
                int price = tmpad.getPrice();
                cout << "current price: €" << price << endl;
                cout << "(s)send" << endl;
                cmdline << ",s";
            }
            cout << "(c)ancel" << endl;
            cmdline << ",c] > ";
            string prompt = cmdline.str();
            prompt[0]='[';
            cout << selection.size() << endl;
            string cmd = readCommand(prompt);
            if(cmd == "n") {
                name = readCommand("name > ");
            }else if(cmd == "sn") {
                NewspaperSelectionWindow sw(newspapers,selection);
                sw.handle();
                if(!sw.isCancelled()) {
                    selection = sw.getSelection();
                }
            }else if(cmd == "sd") {
                DateSelectionWindow dw(validUntil);
                dw.handle();
                if(!dw.isCancelled()) {
                    validUntil = dw.getDate();
                    dateSet = true;
                }
            }else if(cmd == "i") {
                image = readCommand("image > ");
            }else if(cmd == "t") {
                text = readCommand("text > ");
            }else if(cmd == "c") {
                cancelled = true;
                complete = true;
            }else if(cmd == "s" && canSend) {
                complete = true;
                ad = tmpad;
            }
        }while(!complete);
    }
};
#endif
