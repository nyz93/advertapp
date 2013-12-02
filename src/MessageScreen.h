#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H
#include <string>
#include <iostream>
#include "Screen.h"
using namespace std;
class MessageScreen : public Screen {
    std::string message;
    public:
    MessageScreen(const std::string& message):Screen("Message!"),message(message) {}
    virtual void show() {
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
