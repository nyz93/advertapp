#include "UserLevelSelectionScreen.h"
using namespace std;
UserLevelSelectionScreen::UserLevelSelectionScreen(): Screen("Select user level") {}

UserLevelSelectionScreen::~UserLevelSelectionScreen() {}

void UserLevelSelectionScreen::show() {
    bool completed = false;
    do {
        drawTitle();
        cout << "(1) RegisteredUser" << endl;
        cout << "(2) Reviewer" << endl;
        cout << "(3) Admin" << endl;
        cout << endl;
        string cmdline = "[1-3] > ";
        string cmd = readCommand(cmdline);
        if(cmd == "1") {
            result = UserLevel::RegisteredUser;
            completed = true;
        }else if(cmd == "2") {
            result = UserLevel::Reviewer;
            completed = true;
        }else if(cmd == "3") {
            result = UserLevel::Admin;
            completed = true;
        }
    }while(!completed);
}
