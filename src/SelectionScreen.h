#ifndef SELECTIONSCREEN_H
#define SELECTIONSCREEN_H
#include <string>
#include <sstream>
#include <vector>
#include "CancellableAction.h"
#include "Screen.h"
template <class T>
class SelectionScreen: public Screen, public CancellableAction<T> {
    public:
    typedef std::string (*Converter)(T);
    private:
    std::vector<T> options;
    Converter conv;
    public:
    SelectionScreen(const std::vector<T>& options, Converter conv): options(options), conv(conv) {}
    virtual ~SelectionScreen() {}
    virtual void show() {
        bool completed = false;
        do {
            drawTitle();
            CancellableAction<T>::cancelled = false;
            std::stringstream ss;
            for(unsigned i = 0; i < options.size(); i++) {
                std::cout << "(" << i+1 << ") " << conv(options[i]) << std::endl;
            }
            std::cout << std::endl;
            std::cout << "(c)ancel" << std::endl;
            if(options.size() == 1) {
                ss << "[1,c] > ";
            }else{
                ss << "[1-" << options.size()-1 << ",c] > ";
            }
            std::string cmdline = ss.str();
            std::string cmd = readCommand(cmdline);
            if(cmd == "c") {
                CancellableAction<T>::cancelled = true;
                completed = true;
            } else {
                int id = 0;
                std::stringstream conv;
                conv << cmd;
                conv >> id;
                if(id > 0 && id < (int)options.size()+1) {
                    CancellableAction<T>::result = options[id-1];
                    completed = true;
                }
            }
        }while(!completed);
    }
};
#endif
