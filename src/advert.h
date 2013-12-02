#ifndef ADVERT_H
#define ADVERT_H
#include <string>
#include <vector>
#include "user.h"
#include "advertenum.h"
#include "newspaper.h"
#include "date.h"
using namespace std;
class Advert {
    string name;
    string text;
    string image;
    AdvertType type;
    const User* user;
    AdvertStatus status;
    Date creationDate;
    Date validUntil;
    vector<Newspaper*> publishedIn;
    Advert(const string& name, const User* user, const Date& date, const vector<Newspaper*>& newspapers, AdvertType type): name(name),type(type),user(user),status(AdvertStatus::Waiting),validUntil(date) {
        for(auto i:newspapers){
            publishedIn.push_back(i);
        }
    }
    public:
    Advert():name(""),text(""),image(""),type(AdvertType::TextImage),user(nullptr),status(AdvertStatus::Waiting),creationDate(Date()),validUntil(Date()) {}
    static Advert imageAdvert(const string& name, const string& image, const User* user, const Date& date, const vector<Newspaper*>& newspapers) {
        Advert ret(name,user,date,newspapers,AdvertType::Image);
        ret.image = image;
        return ret;
    }
    static Advert textAdvert(const string& name, const string& text, const User* user, const Date& date, const vector<Newspaper*>& newspapers) {
        Advert ret(name,user,date,newspapers,AdvertType::Text);
        ret.text = text;
        return ret;
    }
    static Advert textImageAdvert(const string& name, const string& text,const string& image, const User* user, const Date& date, const vector<Newspaper*>& newspapers) {
        Advert ret(name,user,date,newspapers,AdvertType::TextImage);
        ret.text = text;
        ret.image = image;
        return ret;
    }
    virtual ~Advert() {}
    const string& getName() const {
        return name;
    }
    void setName(const string& name) {
        this->name = name;
    }
    const string& getImage() const {
        return image;
    }
    void setImage(const string& image) {
        this->image = image;
    }
    const string& getText() const {
        return image;
    }
    void setText(const string& text) {
        this->text = text;
    }
    int getPrice() const {
        int price=0;
        int days = creationDate.diffDays(validUntil); 
        for(auto newspaper:publishedIn) {
            price+=(newspaper->getPriceFor(getType()) * days);
        }
        return price;
    }
    AdvertType getType() const {
        return type;
    }
    const User* getCreator() const {
        return user;
    }
    bool isValid() const {
        return validUntil > Date();
    }
    void setCreationDate(const Date& nd) {
        creationDate = nd;
    }
};
#endif
