#ifndef ADVERTAPP_H
#define ADVERTAPP_H
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
    vector<Newspaper*> newspapers;
    vector<Advert*> adverts;
    MainMenu mainMenu;
public:
    AdvertApp();
    const User* getCurrentUser() const;
    void addAdvert();
    void listAdvert();
    void reviewAdvert();
    void addUser();
    void editUser();
    void listNewspapers();
    void addNewspaper();
    void editNewspaper();
    void registerUser();
    void login();
    void start();
    void close();
    ~AdvertApp();
};
#endif
