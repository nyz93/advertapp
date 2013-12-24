/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2013 Zoltán Nyikos
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "AddUserScreen.h"
using namespace std;
AddUserScreen::AddUserScreen(const vector<User*>& users): Screen("Add user"),users(users) {
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

AddUserScreen::~AddUserScreen() {}
