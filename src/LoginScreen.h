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
    LoginScreen():Screen("Login") {}
    const string& getUsername() const {
        return name;
    }
    const string& getPassword() const {
        return pass;
    }
    bool isGuest() const {
        return guest;
    }
    virtual void show() {
        bool complete = false;
        do {
            drawTitle();
            stringstream cmdline;
            cout << "(u)ser: " << name << endl;
            cout << "(p)assword: " << string(pass.length(),'*') << endl;
            //cout << endl << "Write 'u' to edit the username, 'p' to edit the password." << endl;
            cmdline << "[u,p,";
            if(pass != "" && name != "") {
                cout << "(l)ogin" << endl;
                cmdline << "l] > ";
            }else{
                cout << "login as (g)uest" << endl;
                cmdline << "g] > ";
            }
            string cmd = readCommand(cmdline.str());
            if(cmd == "u") {
                string name = readCommand("User > ");
                this->name = name;
            }else if(cmd == "p") {
                string pass = readCommand("Pass > ");
                this->pass = pass;
            }else if(pass == "" && name == "" && cmd == "g") {
                complete = true;
                guest = true;
            }else if(pass != "" && name != "" && cmd == "l") {
                complete = true;
            }
        }while(!complete);
    }
};
#endif
