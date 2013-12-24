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
