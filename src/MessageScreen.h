#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H
#include <string>
#include <iostream>
#include "Screen.h"
using namespace std;
class MessageScreen : public Screen {
    string message;
    public:
    MessageScreen(const std::string& message):Screen("Message!"),message(message) {}
    virtual void show();
};
#endif
