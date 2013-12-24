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

#include "MainMenu.h"
#include "AdvertApp.h"

MainMenu::MainMenu(AdvertApp* app):Screen("Main menu"),app(app){}

void MainMenu::show() {
    bool quit = false;
    do {
        stringstream cmdstring;
        //cmdstring << "[";
        const User* currentUser = app->getCurrentUser(); 
        drawTitle();
        
        cout << "Logged in as: " << currentUser->getName() << endl;
        UserLevel level = currentUser ->getLevel();
        if(level == UserLevel::Guest) {
            cout << "(r)egister" << endl;
            cout << "(l)ist offers" << endl;
            cmdstring  << ",r,l";
        } else {
            cout << "add (a)dvert" << endl;
            cout << "(e)dit advert" << endl;
            cout << "(d)elete advert" << endl;
            cout << "(l)ist adverts" << endl;
            cmdstring << ",a,e,d,l";
            if(level == UserLevel::Reviewer || level == UserLevel::Admin) {
                cout << "(l)ist (a)ll adverts" << endl;
                cout << "(r)eview advert" << endl;
                cout << "add (n)ewspaper" << endl;
                cout << "(e)dit (n)ewspaper" << endl;
                cout << "(d)elete (n)ewspaper" << endl;
                cmdstring  << ",r,n,en";
            }
            cout << "(l)ist (n)ewspaper" << endl;
            cmdstring  << ",ln";
            if(level == UserLevel::Admin) {
                cout << "(a)dd (u)ser" << endl;
                cout << "(e)dit (u)ser" << endl;
                cout << "(d)elete (u)ser" << endl;
            cmdstring  << ",au,eu,du";
            }
        }
        cout << "(q)uit" << endl;
        cmdstring  << ",q] > ";
        string prompt = cmdstring.str();
        prompt[0] = '[';
        string cmd = readCommand(prompt);
        if(cmd == "q") {
            quit = true;
        }else{
            if(level == UserLevel::Guest) {
                if(cmd == "r") {
                    app->registerUser();
                }else if(cmd == "l") {
                    app->listNewspapers();
                }
            }else{
                if(cmd == "a") {
                    app->addAdvert();
                }else if(cmd == "e") {
                    app->editAdvert();
                }else if(cmd == "d") {
                    app->deleteAdvert();
                }else if(cmd == "l") {
                    app->listAdvert();
                }else if(cmd == "ln") {
                    app->listNewspapers();
                }
                if(level == UserLevel::Reviewer || level == UserLevel::Admin) {
                    if(cmd == "r") {
                        app->reviewAdvert();
                    }else if(cmd == "n") {
                        app->addNewspaper();
                    }else if(cmd == "en") {
                        app->editNewspaper();
                    }else if(cmd == "dn") {
                        app->deleteNewspaper();
                    }else if(cmd == "la") {
                        app->listAllAdvert();
                    }
                }
                if(level == UserLevel::Admin) {
                    if(cmd == "au") {
                        app->addUser();
                    }else if(cmd == "eu") {
                        app->editUser();
                    }else if(cmd == "du") {
                        app->deleteUser();
                    }
                }
            }
        }
    }while(!quit);
}
