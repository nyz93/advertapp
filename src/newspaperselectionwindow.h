#ifndef _NEWSPAPERSELECTIONWINDOW_H_
#define _NEWSPAPERSELECTIONWINDOW_H_
#include <vector>
#include <string>
#include <sstream>
#include "window.h"
#include "newspaper.h"
using namespace std;
class NewspaperSelectionWindow {
    vector<Newspaper*> newspapers;
    vector<Newspaper*> selection;
    bool cancelled;
    public:
    NewspaperSelectionWindow(const vector<Newspaper*> newspapers):newspapers(newspapers) {
    }
    virtual void handle() {
        bool completed = false;
        stringstream cmdline;
        do {
            for(int i = 0; i < newspapers.size(); i++) {
                cout << "(" << i+1 << ") " << newspapers[i]->getName()<< endl;
                cmdline << "," << i+1;
            }
            cout << "(c)ancel selection" << endl;
            cout << "(f)inish selection" << endl;
            cmdline <<",c,f] > ";
            string prompt = cmdline.str();
            prompt[0] = '[';
            string cmd = readCommand(prompt);
            if(cmd == "c") {
                completed = true;
                cancelled = true;
            }else if(cmd == "f") {
                completed = true;
            }else{
                stringstream conv(cmd);
                int s;
                conv >>s;
                if(s > 0 && s < newspapers.size()+1) {
                    selection.push_back(newspapers[s-1]);
                }
            }
        }while(!completed);
    }
    const vector<Newspaper*>& getSelection() const {
        return selection;
    }
    bool isCancelled() const {
        return cancelled;
    }
};
#endif
