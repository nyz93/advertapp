#ifndef ADVERTAPP_H
#define ADVERTAPP_H
#include <string>
#include <vector>
#include "Advert.h"
#include "Newspaper.h"
#include "LoginScreen.h"
#include "AddAdvertScreen.h"
#include "MainMenu.h"
#include "MessageScreen.h"
#include "Reviewer.h"
#include "ListAdvertScreen.h"
using namespace std;
class AdvertApp {

    User* currentUser;
    vector<User> users;
    vector<Newspaper*> newspapers;
    vector<Advert*> adverts;
    MainMenu mainMenu;
    static AdvertApp* instance;
    AdvertApp():mainMenu(this) {
        //TODO: load users, ads, newspapers
        Reviewer t("user","pass");
        users.push_back(t);
        currentUser=&users[0];
        Newspaper* np = new Newspaper("Daily News");
        np->setPriceFor(AdvertType::Image,100);
        np->setPriceFor(AdvertType::Text,200);
        np->setPriceFor(AdvertType::TextImage,350);
        newspapers.push_back(np);
    }
    public:
    static AdvertApp* getInstance() {
        if(instance == nullptr) {
            instance = new AdvertApp();
        }
        return instance;
    }
    const User* getCurrentUser() const {
        return currentUser;
    }
    void addAdvert() {
        AddAdvertWindow aw(newspapers,currentUser);
        aw.handle();
        if(!aw.isCancelled()) {
            Advert* ad = new Advert(aw.getAdvert());
            adverts.push_back(ad);
        }
    }
    void listAdvert() {
        vector<const Advert*> toList;
        for(auto ad: adverts) {
            if(currentUser == ad->getCreator()) {
                toList.push_back(ad);
            }
        }
        ListAdvertWindow lw(toList);
        lw.handle();
    }
    void reviewAdvert() {
    }
    void addUser() {
    }
    void editUser() {
    }
    void listNewspapers() {
    }
    void addNewspaper() {
    }
    void editNewspaper() {
    }
    void registerUser() {
    }
    void login() {
        bool loggedIn = false;
        do {
            LoginWindow l;
            l.handle();
            if(!l.isGuest()) {
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
            }else{ //guest
                currentUser = nullptr;
                loggedIn = true;
            }
        }while(!loggedIn);
    }
    void start() {
        //login();
        mainMenu.handle();
        close();
    }
    void close() {
        //TODO:save stuff
    }
    ~AdvertApp() {
        for(auto npp : newspapers) {
            delete npp;
        }
        for(auto adp : adverts) {
            delete adp;
        }
    }
};

AdvertApp* AdvertApp::instance = nullptr;
#endif

