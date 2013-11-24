#ifndef _ADDADVERTWINDOW_H_
#define _ADDADVERTWINDOW_H_
#include "advert.h"
#include "window.h"
#include "newspaperselectionwindow.h"
#include "adverttypeselectionwindow.h"
class AddAdvertWindow:Window {
    Advert ad;
    AddAdvertWindow():Window("Add advert"){}
    bool cancelled;
    public:
    Advert getAdvert() {
        return ad;
    }
    bool isCancelled() {
        return cancelled;
    }
    virtual void handle() {
        bool complete = false;
        AdvertTypeSelectionWindow ts;
        ts.handle();
        string name;
        string image;
        string text;
        stringstream cmdline;
        vector<Newspaper*> newspapers;
        do {
            drawTitle();
            cout << "(n)ame: " << name << endl;
            cmdline << ",n";
            switch(ts.getType()) {
                case AdvertType::Image: {
                    cout << "(i)mage: " << image << endl;
                    cmdline << ",i";
                    if(image != "" && name != "" ) {
                        cout << "(s)end" << endl;
                        cmdline << ",s";
                    }
                };break
                case AdvertType::Text: {
                    cout << "(t)ext: " << text << endl;
                    cmdline << ",t";
                    if(text != "" && name != "") {
                        cout << "(s)end" << endl;
                        cmdline << ",s";
                    }
                };break
                case AdvertType::TextImage: {
                    cout << "(t)ext: " << text << endl;
                    cout << "(i)mage: " << image << endl;
                    cmdline << ",t,i";
                    if(text != "" && image != "" && name != "") {
                        cout << "(s)end" << endl;
                        cmdline << ",s";
                    }
                };break
            }
            cout << "(s)elect (n)newspapers" << endl;
            cmdline << ",sn";
            cout << "(c)ancel" << endl;
            cmdline << ",c] > ";
            string prompt = cmdline.str();
            prompt[0]='[';
            string cmd = readCommand(prompt);
            if(cmd == "n") {
                name = readCommand("name > ");
            if(cmd == "sn") {
                NewspaperSelectionWindow sw
            }else if(cmd == "i") {
                image = readCommand("image > ");
            }else if(cmd == "t") {
                text = readCommand("text > ");
            }else if(cmd == "c") {
                cancelled = true;
                complete = true;
            }else if(cmd == "s" && name != "") {
                switch(ts.getType()) {
                    case AdvertType::Image: {
                        if(image != "") {
                            complete = true;
                            ad = Advert::imageAdvert(name,newspapers,image);
                        }
                    };break
                    case AdvertType::Text: {
                        if(text != "") {
                            complete = true;
                        }
                    };break
                    case AdvertType::TextImage: {
                        if(text != "" && image != "") {
                            complete = true;
                        }
                    };break
                }
            }
        }while(!complete);
    }
};
#endif
