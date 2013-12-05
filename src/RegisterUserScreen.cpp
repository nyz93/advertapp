#include "RegisterUserScreen.h"
using namespace std;
RegisterUserScreen::RegisterUserScreen(const vector<User*>& users) : users(users) {}

RegisterUserScreen::~RegisterUserScreen() {}

void RegisterUserScreen::show() {
    bool completed = false;
    string name,pass; 
    do {
        cancelled = false;
        drawTitle();
        cout << "(n)ame: "  << name << endl;
        cout << "(p)ass: " << string(pass.length(),'*') << endl;
        cout << endl;
        string cmdline = "[n,p,c] > ";
        if(name != "" && pass != "") {
            cout << "(r)egister" << endl;
            cmdline = "[n,p,r,c] > ";
        }
        cout << "(c)ancel" << endl;
        string cmd = readCommand(cmdline);
        if(cmd == "n") {
            name = readCommand("name > ");
        }else if(cmd == "p") {
            pass = readCommand("pass > ");
        }else if(cmd == "a" && name != "" && pass != "") {
            completed = true;
            for(auto user : users) {
                if(user->getName() == name) {
                    completed = false;
                    MessageScreen ms("Name is already registered!");
                    ms.show();
                }
            }
            if(completed) {
                result = new RegisteredUser(name,pass); break;
            }
        }else if(cmd == "c") {
            cancelled = true;
            completed = true;
        }
    }while(!completed);
}
