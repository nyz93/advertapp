#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <string>
#include <sstream>
#include <iostream>
#include "window.h"
using namespace std;
class LoginWindow : public Window {
    string name;
    string pass;
    bool guest = false;
    public:
    LoginWindow();
    const string& getUsername() const;
    const string& getPassword() const;
    bool isGuest() const;
    virtual void handle();
};
#endif
