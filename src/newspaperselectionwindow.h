#ifndef _NEWSPAPERSELECTIONWINDOW_H_
#define _NEWSPAPERSELECTIONWINDOW_H_
#include <vector>
#include <string>
#include <sstream>
#include "window.h"
#include "newspaper.h"
using namespace std;
class NewspaperSelectionWindow: Window{
    vector<Newspaper*> newspapers;
    vector<Newspaper*> selection;
    bool cancelled;
    int find(Newspaper* np) {
        for(unsigned int i = 0; i < selection.size(); i++) {
            if(selection[i] == np) {
                return i;
            }
        }
        return -1;
    }
    public:
    NewspaperSelectionWindow(const vector<Newspaper*>& newspapers,
            const vector<Newspaper*>& selection):Window("Select newspapers"), newspapers(newspapers), selection(selection){
    }
    virtual void handle() {
        bool completed = false;
        cancelled = false;
        do {
            drawTitle();
            stringstream cmdline;
            for(int i = 0; i < newspapers.size(); i++) {
                cout << "(" << i+1 << ") ";
                if(find(newspapers[i]) != -1) {
                    cout <<"[*]";
                }else{
                    cout <<"[ ]";
                }
                cout << newspapers[i]->getName() << endl;
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
                int s = -1;
                conv >> s;
                if(s > 0 && s < newspapers.size()+1) {
                    auto current = newspapers[s-1];
                    bool found = false;
                    for(auto i = selection.begin(); i != selection.end(); i++) {
                        if(*i == current) {
                            selection.erase(i);
                            found = true;
                            break;
                        }
                    }
                    if(!found) {
                        selection.push_back(current);
                    }
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
