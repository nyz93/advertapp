#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <string>
#include <sstream>
#include <iostream>
#include "Screen.h"
using namespace std;
class LoginScreen : public Screen {
    string name;
    string pass;
    bool guest = false;
    public:
    LoginScreen();
    const string& getUsername() const;
    const string& getPassword() const;
    bool isGuest() const;
    virtual void show();
};
#endif
