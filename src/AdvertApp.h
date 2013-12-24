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
#include "EditAdvertScreen.h"
#include "ReviewAdvertScreen.h"
#include "SelectionScreen.h"
#include "EditUserScreen.h"
#include "RegisterUserScreen.h"
#include "Database.h"
#include "Guest.h"
#include "AddUserScreen.h"
#include "ListScreen.h"
#include "AddNewspaperScreen.h"
#include "EditNewspaperScreen.h"
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
    void listAllAdvert();
    void editAdvert();
    void deleteAdvert();
    void reviewAdvert();
    void addUser();
    void editUser();
    void deleteUser();
    void listNewspapers();
    void addNewspaper();
    void editNewspaper();
    void deleteNewspaper();
    void registerUser();
    void login();
    void start();
    void close();
    ~AdvertApp();
};

#endif

