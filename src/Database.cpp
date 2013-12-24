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

#include <sstream>
#include "Database.h"
using namespace std;

Date Database::readDate(const string& date) {
    stringstream ss(date);
    stringstream conv;
    int year;
    int month;
    int day;
    string part;
    getline(ss,part,'-');
    conv << part;
    conv >> year;
    conv.clear();
    getline(ss,part,'-');
    conv << part;
    conv >> month;
    conv.clear();
    getline(ss,part,'-');
    conv << part;
    conv >> day;
    conv.clear();
    return Date(year,month,day);
}


// u|name|pass|type
// type: see in UserLevel
void Database::readUser(const string& line) {
    stringstream ss(line);
    string type,name,pass;
    char del;
    ss>>del;// type character
    ss>>del;// |
    getline(ss,name,'|');
    getline(ss,pass,'|');
    getline(ss,type,'|');
    User* user = nullptr;
    if(type == "Admin") {
        user = new Admin(name,pass);
    }else if(type == "Reviewer") {
        user = new Reviewer(name,pass);
    }else if(type == "RegisteredUser") {
        user = new RegisteredUser(name,pass);
    }
    if(user != nullptr) {
        users->push_back(user);
    }
}
// n|name|prices
// prices: space separated price of a certain advert type for a day
//         in the order of imagePrice,textPrice,textImagePrice
void Database::readNewspaper(const string& line) {
    stringstream ss(line);
    string name;
    char del;
    ss>>del;// type character
    ss>>del;// |
    getline(ss,name,'|');
    Newspaper* n = new Newspaper(name);
    string prices;
    getline(ss,prices,'|');
    stringstream conv(prices);
    int imagePrice;
    int textPrice;
    int textImagePrice;
    conv >> imagePrice;
    conv >> textPrice;
    conv >> textImagePrice;
    n->setPriceFor(AdvertType::Image,imagePrice);
    n->setPriceFor(AdvertType::Text,textPrice);
    n->setPriceFor(AdvertType::TextImage,textImagePrice);
    newspapers->push_back(n);
}

// a|name|creation|validUntil|status|user|newspapers|type|type_specific
// creation and validuntil is int yyyy-mm-dd form
// for type see AdvertType, for status see AdvertStatus
// user is an array id in the users vector
// newspapers is a space separated list of array ids in the newspapers vector
// type_specific:
//  image adverts: image
//  text adverts: text
//  textimage adverts: text|image
void Database::readAdvert(const string& line) {
    stringstream ss(line);
    stringstream conv;
    string name,type,status,create,valid,user,newslist;
    vector<Newspaper*> nps;
    User* userp;
    char del;
    ss>>del;
    ss>>del;
    getline(ss,name,'|');
    getline(ss,create,'|');
    Date creationDate = readDate(create);
    getline(ss,valid,'|');
    Date validUntil = readDate(valid);
    getline(ss,status,'|');
    AdvertStatus stat;
    if(status == "Accepted") {
        stat = AdvertStatus::Accepted;
    }else if(status == "Rejected") {
        stat = AdvertStatus::Rejected;
    }else{
        stat = AdvertStatus::Waiting; //not the best but hey
    }
    getline(ss,user,'|');
    conv << user;
    int userid;
    conv >> userid;
    userp = users->at(userid);
    conv.clear();
    getline(ss,newslist,'|');
    conv << newslist;
    while(!conv.eof()) {
        int npid;
        conv >> npid;
        nps.push_back(newspapers->at(npid));
    }
    getline(ss,type,'|');
    if(type == "Image") {
        string image;
        getline(ss,image,'|');
        Advert* ad = new Advert(Advert::imageAdvert(name,image,userp,validUntil,nps));
        ad->setStatus(stat);
        ad->setCreationDate(creationDate);
        adverts->push_back(ad);
    }else if(type == "Text") {
        string text;
        getline(ss,text,'|');
        Advert* ad = new Advert(Advert::textAdvert(name,text,userp,validUntil,nps));
        ad->setStatus(stat);
        ad->setCreationDate(creationDate);
        adverts->push_back(ad);
    }else if(type == "TextImage") {
        string text;
        getline(ss,text,'|');
        string image;
        getline(ss,image,'|');
        Advert* ad = new Advert(Advert::textImageAdvert(name,text,image,userp,validUntil,nps));
        ad->setStatus(stat);
        adverts->push_back(ad);
    }
}
Database::Database(const string& filename) {
    users = new std::vector<User*>();
    adverts = new std::vector<Advert*>();
    newspapers = new std::vector<Newspaper*>();
    file = filename;
    std::ifstream f(filename);
    if(!f.is_open()) {
        MessageScreen mw("Database file not found!");
        mw.show();
        exit(100);
    }
    while(!f.eof()) {
        std::string line;
        std::getline(f,line);
        if(line[0] == 'u') {
            readUser(line);
        }else if(line[0] == 'a') {
            readAdvert(line);
        }else if(line[0] == 'n') {
            readNewspaper(line);
        }
    }
}
void Database::save() {
    ofstream out(file);
    out << "#USERS" << endl;
    for(auto user:*users) {
        out << "u|" << user->getName() << "|" << user->getPassword() << "|";
        switch(user->getLevel()) {
            case UserLevel::RegisteredUser:
                out << "RegisteredUser" << endl; break;
            case UserLevel::Reviewer:
                out << "Reviewer" << endl; break;
            case UserLevel::Admin:
                out << "Admin" << endl; break;
            case UserLevel::Guest:
                //there is no reason to store that exactly one Guest user that might exist
                break;
        }
    }
    out << "#NEWSPAPERS" << endl;
    for(auto np: *newspapers) {
        out << "n|" << np->getName() << "|";
        out << np->getPriceFor(AdvertType::Image) << " ";
        out << np->getPriceFor(AdvertType::Text) << " ";
        out << np->getPriceFor(AdvertType::TextImage) << endl;
    }
    out << "#ADVERTS" << endl;
    for(auto advert: *adverts) {
        out << "a|" << advert->getName() << "|" << advert->getCreationDate() << "|"
            << advert->getExpirationDate() << "|";
        switch(advert->getStatus()) {
            case AdvertStatus::Rejected:
                out << "Rejected"; break;
            case AdvertStatus::Accepted:
                out << "Accepted"; break;
            case AdvertStatus::Waiting:
                out << "Waiting"; break;
        }
        out << "|";
        const User* user = advert->getCreator();
        for(unsigned i = 0; i < users->size(); i++) { //god save us if we can't find the user
            if(users->at(i) == user) {
                out << i << "|";
                break;
            }
        }
        const vector<Newspaper*> pub = advert->getNewspapers(); //same with the newspapers
        for(int i = 0; i < (int)pub.size()-1; i++) {
            for(unsigned j = 0; j < newspapers->size(); j++) {
                if(newspapers->at(j) == pub[i]) {
                    out << j << " ";
                }
            }
        }
        for(unsigned j = 0; j < newspapers->size(); j++) {
            if(newspapers->at(j) == pub[pub.size()-1]) {
                out << j << "|";
            }
        }
        switch(advert->getType()) {
            case AdvertType::Text:
                out << "Text" << "|";
                out << advert->getText() << endl;
                break;
            case AdvertType::Image:
                out << "Image" << "|";
                out << advert->getImage() << endl;
                break;
            case AdvertType::TextImage:
                out << "TextImage" << "|";
                out << advert->getText() << "|";
                out << advert->getImage() << endl;
                break;
        }
    }
}
Database::~Database() {
    save();
    for(User* p : *users) {
        delete p;
    }
    delete users;

    for(Advert* p : *adverts) {
        delete p;
    }
    delete adverts;
    for(Newspaper* p : *newspapers) {
        delete p;
    }
    delete newspapers;
}
vector<User*>* Database::getUsers() {
    return users;
}
vector<Advert*>* Database::getAdverts(){
    return adverts;
}
vector<Newspaper*>* Database::getNewspapers(){
    return newspapers;
}

void Database::replaceUser(User* old, User* newUser) {
    for(auto ad: *adverts) {
        if(ad->getCreator() == old) {
            ad->setCreator(newUser);
        }
    }
    for(unsigned i = 0; i < users->size(); i++) {
        if(users->at(i) == old) {
            users->at(i) = newUser;
        }
    }
    delete old;
}

void Database::deleteUser(User* user) {
    vector<Advert*> todel;
    for(auto i = adverts->begin(); i != adverts->end(); ++i) {
        if((*i)->getCreator() == user) {
            todel.push_back(*i);
        }
    }
    for(auto i : todel) {
        deleteAdvert(i);
    }
    for(auto i = users->begin(); i != users->end(); i++) {
        if(*i == user) {
            users->erase(i);
            break;
        }
    }
}

void Database::replaceAdvert(Advert* old, Advert* newAd) {
    for(unsigned i = 0; i < adverts->size(); i++) {
        if(adverts->at(i) == old) {
            adverts->at(i) = newAd;
        }
    }
    delete old;
}
void Database::deleteAdvert(Advert* ad) {
    for(auto i = adverts->begin(); i != adverts->end(); ++i) {
        if(*i == ad) {
            adverts->erase(i);
            delete ad;
            break;
        }
    }
}

void Database::replaceNewspaper(Newspaper* old, Newspaper* newN) {
    for(auto ad: *adverts) {
        vector<Newspaper*> vec = ad->getNewspapers();
        for(auto i = vec.begin(); i != vec.end(); ++i) {
            if(*i == old) {
                *i = newN;
            }
        }
        ad->setNewspapers(vec);
    }
    for(unsigned i = 0; i < newspapers->size(); i++) {
        if(newspapers->at(i) == old) {
            newspapers->at(i) = newN;
        }
    }
    delete old;
}

void Database::deleteNewspaper(Newspaper* np) {
    for(auto ad: *adverts) {
        vector<Newspaper*> vec = ad->getNewspapers();
        for(auto i = vec.begin(); i != vec.end(); ++i) {
            if(*i == np) {
                vec.erase(i);
                break;
            }
        }
        ad->setNewspapers(vec);
    }
    for(auto i = newspapers->begin(); i != newspapers->end(); i++) {
        if(*i == np) {
            newspapers->erase(i);
            break;
        }
    }
    delete np;
}
