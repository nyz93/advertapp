#include "EditUserScreen.h"
using namespace std;
EditUserScreen::EditUserScreen(const vector<User*>& users, const User* user):
    Screen("Edit user"),old(user),users(users) {
}

EditUserScreen::~EditUserScreen() {}

void EditUserScreen::show() {
    bool completed = false;
    string name = old->getName(), pass = old->getPassword();
    UserLevel level = old->getLevel();
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
        string cmdline = "[n,p,c] > ";
        if(name != "" && pass != "" && level != UserLevel::Guest) {
            cout << "(a)dd user" << endl;
            cmdline = "[n,p,a,c] > ";
        }
        cout << "(c)ancel" << endl;
        string cmd = readCommand(cmdline);
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
            for(auto user : users) {
                if(user->getName() == name) {
                    completed = false;
                    MessageScreen ms("Name is already registered!");
                    ms.show();
                }
            }
        }else if(cmd == "c") {
            cancelled = true;
            completed = true;
        }
    }while(!completed);
}
