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
#include "Database.h"
using namespace std;
class AdvertApp {

    User* currentUser;
    vector<User*>* users;
    vector<Newspaper*>* newspapers;
    vector<Advert*>* adverts;
    Database db;
    MainMenu mainMenu;
    static AdvertApp* instance;
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
    static AdvertApp* getInstance();
    void close();
    ~AdvertApp();
};

#endif

