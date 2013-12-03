#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include <string>
#include "Advert.h"
#include "AdvertEnum.h"
using namespace std;
class Advert;
class Newspaper {
    string name;
    int textPrice, imagePrice, textImagePrice;
    public:
    Newspaper(): name("") {}
    Newspaper(const string& name): name(name) {}
    int getPriceFor(AdvertType type) const;
    void setPriceFor(AdvertType type, int price);
    const string& getName() const;
    virtual ~Newspaper() {}
};
#endif
