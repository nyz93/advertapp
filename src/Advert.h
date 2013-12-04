#ifndef ADVERT_H
#define ADVERT_H
#include <string>
#include <vector>
#include "AdvertEnum.h"
#include "Newspaper.h"
#include "User.h"
#include "Date.h"
using namespace std;
class Newspaper;
class Advert {
    private:
    string name;
    string text;
    string image;
    AdvertType type;
    const User* user;
    AdvertStatus status;
    Date creationDate;
    Date validUntil;
    vector<Newspaper*> publishedIn;
    Advert(const string& name, const User* user, const Date& date, const vector<Newspaper*>& newspapers, AdvertType type);
    public:
    Advert():name(""),text(""),image(""),type(AdvertType::TextImage),user(nullptr),status(AdvertStatus::Waiting),creationDate(Date()),validUntil(Date()) {}
    static Advert imageAdvert(const string& name, const string& image, const User* user, const Date& date, const vector<Newspaper*>& newspapers);
    static Advert textAdvert(const string& name, const string& text, const User* user, const Date& date, const vector<Newspaper*>& newspapers);
    static Advert textImageAdvert(const string& name, const string& text,const string& image, const User* user, const Date& date, const vector<Newspaper*>& newspapers);
    virtual ~Advert() {}
    const string& getName() const;
    void setName(const string& name);
    const string& getImage() const;
    void setImage(const string& image);
    const string& getText() const;
    void setText(const string& text);
    int getPrice() const;
    AdvertType getType() const;
    const User* getCreator() const;
    void setCreator(User* nc);
    bool isValid() const;
    void setCreationDate(const Date& nd);
    const Date& getCreationDate() const;
    const Date& getExpirationDate() const;
    AdvertStatus getStatus() const;
    void setStatus(AdvertStatus ns);
    const vector<Newspaper*>& getNewspapers() const;
};
#endif
