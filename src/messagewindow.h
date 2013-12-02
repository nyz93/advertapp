#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H
#include <string>
#include <iostream>
#include "window.h"
using namespace std;
class MessageWindow : public Window {
    std::string message;
    public:
    MessageWindow(const std::string& message):Window("Message!"),message(message) {}
    virtual void handle();
};
#endif
