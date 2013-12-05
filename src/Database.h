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
};
#endif
