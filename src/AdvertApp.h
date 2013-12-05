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
#include "ListAdvertScreen.h" //remove this
#include "EditAdvertScreen.h"
#include "ReviewAdvertScreen.h"
#include "SelectionScreen.h"
#include "EditUserScreen.h"
#include "Database.h"
#include "Guest.h"
#include "AddUserScreen.h"
#include "ListScreen.h"
#include "AddNewspaperScreen.h"
using namespace std;
class AdvertApp {

    User* currentUser;
    vector<User*>* users;
    vector<Newspaper*>* newspapers;
    vector<Advert*>* adverts;
    Database db;
    MainMenu mainMenu;
public:
    AdvertApp();
    const User* getCurrentUser() const;
    void addAdvert();
    void listAdvert();
    void editAdvert();
    void deleteAdvert();
    void reviewAdvert();
    void addUser();
    void editUser();
    void deleteUser();
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

