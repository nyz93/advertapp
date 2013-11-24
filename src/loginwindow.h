#ifndef _LOGINWINDOW_H_
#define _LOGINWINDOW_H_
#include <string>
#include <iostream>
#include "window.h"
using namespace std;
class LoginWindow : public Window {
    string name;
    string pass;
    public:
    LoginWindow():Window("Login") {}
    const string& getUsername() const {
        return name;
    }
    const string& getPassword() const {
        return pass;
    }
    virtual void handle() {
        bool passSet = false;
        bool nameSet = false;
        do {
            drawTitle();
            cout << "User: " << name << endl;
            cout << "Password: " << pass << endl;
            cout << endl << "Write 'u' to edit the username, 'p' to edit the password." << endl;
            string cmd = readCommand();
            if(cmd == "u") {
                string name = readCommand("User > ");
                this->name = name;
                nameSet = (name != "");
            }else if(cmd == "p") {
                string pass = readCommand("Pass > ");
                this->pass = pass;
                passSet = (pass != "");
            }
        }while(!passSet || !nameSet);
    }
};
#endif
