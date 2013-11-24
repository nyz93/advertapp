#ifndef _MESSAGEWINDOW_H_
#define _MESSAGEWINDOW_H_
#include <string>
#include "window.h"
class MessageWindow : public Window {
    std::string message;
    public:
    MessageWindow(const std::string& message):Window("Message!"),message(message) {}
    virtual void handle() {
        while(true) {
            drawTitle();
            std::cout << message << endl;
            std::cout << endl << "Write 'q' to close." << endl;
            std::string cmd = readCommand();
            if(cmd == "q") {
                break;
            }
        }
    }
};
#endif
