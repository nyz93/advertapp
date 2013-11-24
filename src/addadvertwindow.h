#ifndef _ADDADVERTWINDOW_H_
#define _ADDADVERTWINDOW_H_
#include "advert.h"
#include "advertwindow.h"
#include "cancellablewindow.h"
#include "messagewindow.h"
#include "newspaperselectionwindow.h"
#include "adverttypeselectionwindow.h"
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
        do {
            stringstream cmdline;
            drawTitle();
            cout << "(n)ame: " << name << endl;
            cmdline << ",n";
            switch(ts.getType()) {
                case AdvertType::Image: {
                    cout << "(i)mage: " << image << endl;
                    cmdline << ",i";
                    if(image != "" && name != "" && selection.size()) {
                        cout << "(s)end" << endl;
                        cmdline << ",s";
                    }
                }break;
                case AdvertType::Text: {
                    cout << "(t)ext: " << text << endl;
                    cmdline << ",t";
                    if(text != "" && name != "" && selection.size()) {
                        cout << "(s)end" << endl;
                        cmdline << ",s";
                    }
                }break;
                case AdvertType::TextImage: {
                    cout << "(t)ext: " << text << endl;
                    cout << "(i)mage: " << image << endl;
                    cmdline << ",t,i";
                    if(text != "" && image != "" && name != "" && selection.size()) {
                        cout << "(s)end" << endl;
                        cmdline << ",s";
                    }
                }break;
            }
            cout << "(s)elect (n)newspapers" << endl;
            cmdline << ",sn";
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
            }else if(cmd == "i") {
                image = readCommand("image > ");
            }else if(cmd == "t") {
                text = readCommand("text > ");
            }else if(cmd == "c") {
                cancelled = true;
                complete = true;
            }else if(cmd == "s" && name != "" && selection.size() > 0) {
                switch(ts.getType()) {
                    case AdvertType::Image: {
                        if(image != "") {
                            complete = true;
                            ad = Advert::imageAdvert(name,image,currentUser,selection);
                        }
                    }break;
                    case AdvertType::Text: {
                        if(text != "") {
                            complete = true;
                            ad = Advert::textAdvert(name,text,currentUser,selection);
                        }
                    }break;
                    case AdvertType::TextImage: {
                        if(text != "" && image != "") {
                            ad = Advert::textImageAdvert(name,text,image,currentUser,selection);
                            complete = true;
                        }
                    }break;
                }
            }
        }while(!complete);
    }
};
#endif
