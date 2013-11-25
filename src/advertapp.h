#ifndef _ADVERTAPP_H_
#define _ADVERTAPP_H_
#include <string>
#include <vector>
#include "advert.h"
#include "newspaper.h"
#include "loginwindow.h"
#include "addadvertwindow.h"
#include "mainmenu.h"
#include "messagewindow.h"
#include "user.h"
#include "listadvertwindow.h"
using namespace std;
class AdvertApp {
    User* currentUser;
    vector<User> users;
    vector<Newspaper> newspapers;
    vector<Advert> adverts;
    MainMenu mainMenu;
    public:
    AdvertApp():mainMenu(this) {
        //TODO: load users, ads, newspapers
        User t("user","pass",UserLevel::Admin);
        users.push_back(t);
        currentUser=&users[0];
        Newspaper np("Daily News");
        np.setPriceFor(AdvertType::Image,100);
        np.setPriceFor(AdvertType::Text,200);
        np.setPriceFor(AdvertType::TextImage,350);
        newspapers.push_back(np);
    }
    const User* getCurrentUser() const {
        return currentUser;
    }
    void addAdvert() {
        AddAdvertWindow aw(newspapers,currentUser);
        aw.handle();
        if(!aw.isCancelled()) {
            Advert ad = aw.getAdvert();
            adverts.push_back(ad);
        }
    }
    void listAdvert() {
        vector<const Advert*> toList;
        for(auto ad: adverts) {
            if(currentUser == ad.getCreator()) {
                toList.push_back(&ad);
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
    }
};
#endif
