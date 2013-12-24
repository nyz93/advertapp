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

#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <vector>
#include "User.h"
#include "Reviewer.h"
#include "Admin.h"
#include "RegisteredUser.h"
#include "Newspaper.h"
#include "Advert.h"
#include "MessageScreen.h"
/*
 * File structure:
 * data in lines (separated by \n)
 * 3 different types: user, advert, newspaper
 * user:
 *      u|<username>|<password>|<user level>
 * */
class Database {
    private:
        std::string file;
        std::vector<User*>* users;
        std::vector<Advert*>* adverts;
        std::vector<Newspaper*>* newspapers;
        void readUser(const string& line);
        void readAdvert(const string& line);
        void readNewspaper(const string& line);
        Date readDate(const string& date);
        void save();
    public:
        Database(const std::string& filename);
        ~Database();
        vector<User*>* getUsers();
        vector<Advert*>* getAdverts();
        vector<Newspaper*>* getNewspapers();
        void replaceUser(User* old, User* newUser);
        void deleteUser(User* user);
        void replaceAdvert(Advert* old, Advert* newAd);
        void deleteAdvert(Advert* ad);
        void replaceNewspaper(Newspaper* old, Newspaper* newN);
        void deleteNewspaper(Newspaper* np);
};
#endif
