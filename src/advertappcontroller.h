#ifndef _ADVERTAPPCONTROLLER_H_
#define _ADVERTAPPCONTROLLER_H_
#include <iostream>
#include <string>
class AdvertAppController {
    public:
    AdvertAppController(AdvertApp* app):advertApp(app),running(false) {
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
            loggedIn = l.isSuccesful();
        }while(!loggedIn);
    }
    void start() {
        login();
        while(running) {
            mainMenu.handle();
        }
    }
    void close() {
        advertApp->close();
    }
};
#endif

