#ifndef _ADVERTAPP_H_
#define _ADVERTAPP_H_
#include <string>
#include <vector>
#include "advert.h"
#include "newspaper.h"
#include "loginwindow.h"
//#include "mainmenu.h"
#include "messagewindow.h"
#include "user.h"
using namespace std;
class AdvertApp {
    User* currentUser;
    vector<User> users;
    vector<Newspaper> newspapers;
    vector<Advert> adverts;
    bool running;
    //MainMenu mainMenu;
    public:
    AdvertApp() {
        //TODO: load users, ads, newspapers
        User t("user","pass",UserLevel::Admin);
        users.push_back(t);
    }
    const User* getCurrentUser() const {
        return currentUser;
    }
    void addAdvert() {
    }
    void listAdvert() {
    }
    void reviewAdvert() {
    }
    void addUser() {
    }
    void editUser() {
    }
    void login() {
        bool loggedIn = false;
        do {
            LoginWindow l;
            l.handle();
            string name = l.getUsername();
            string pass = l.getPassword();
            for(auto user = users.begin(); user != users.end(); user++) {
                if(user->getName() == name && user->isPassword(pass)) {
                    currentUser = &*user;
                    loggedIn = true;
                }
            }
            if(!loggedIn) {
                MessageWindow wnd("Login error, invalid username or password!");
                wnd.handle();
            }
        }while(!loggedIn);
    }
    void start() {
        login();
        cout <<"YAY" << endl;
        while(running) {
            //mainMenu.handle();
        }
    }
    void close() {
        //TODO:save stuff
    }
};
#endif
