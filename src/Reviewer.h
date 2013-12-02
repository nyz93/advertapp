#ifndef REVIEWER_H
#define REVIEWER_H
#include "User.h"
#include "AdvertApp.h"
class Reviewer: public User{
    public:
        Reviewer(const string& name, const string& pass):User(name,pass){}
    void reviewAdvert() {
        AdvertApp::getInstance()->reviewAdvert(); 
    }
};
#endif
