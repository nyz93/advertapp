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
        bool complete = false;
        do {
            drawTitle();
            cout << "User: " << name << endl;
            cout << "Password: " << string(pass.length(),'*') << endl;
            cout << endl << "Write 'u' to edit the username, 'p' to edit the password." << endl;
            if(pass != "" && name != "") {
                cout << "Write 'l' to login." << endl;
            }
            string cmd = readCommand();
            if(cmd == "u") {
                string name = readCommand("User > ");
                this->name = name;
            }else if(cmd == "p") {
                string pass = readCommand("Pass > ");
                this->pass = pass;
            }else if(pass != "" && name != "" && cmd == "l") {
                complete = true;
            }
        }while(!complete);
    }
};
#endif
