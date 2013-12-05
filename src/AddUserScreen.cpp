#include "AddUserScreen.h"
using namespace std;
AddUserScreen::AddUserScreen(): Screen("Add user") {
}

void AddUserScreen::show() {
    bool completed = false;
    string name, pass;
    UserLevel level = UserLevel::Guest;
    do {
        cancelled = false;
        drawTitle();
        cout << "(n)ame: "  << name << endl;
        cout << "(p)ass: " << string(pass.length(),'*') << endl;
        cout << "(l)evel: ";
        switch(level) {
            case UserLevel::Reviewer: cout << "Reviewer" << endl; break;
            case UserLevel::Admin: cout << "Admin" << endl; break;
            case UserLevel::RegisteredUser: cout << "Registered user" << endl; break;
            case UserLevel::Guest: break;
        }
        cout << endl;
        if(name != "" && pass != "" && level != UserLevel::Guest) {
            cout << "(a)dd user" << endl;
        }
        cout << "(c)ancel" << endl;
        string cmd = readCommand("[n,p,a,c] > ");
        if(cmd == "n") {
            name = readCommand("name > ");
        }else if(cmd == "p") {
            pass = readCommand("pass > ");
        }else if(cmd == "l") {
            UserLevelSelectionScreen ls;
            ls.show();
            level = ls.getResult();
        }else if(cmd == "a" && name != "" && pass != "" && level != UserLevel::Guest) {
            switch(level) {
            case UserLevel::Reviewer: result = new Reviewer(name,pass); break;
            case UserLevel::Admin: result = new Admin(name,pass); break;
            case UserLevel::RegisteredUser: result = new RegisteredUser(name,pass); break;
            case UserLevel::Guest: break;
            }
            completed = true;
        }else if(cmd == "c") {
            cancelled = true;
            completed = true;
        }
    }while(!completed);
}

AddUserScreen::~AddUserScreen() {}
