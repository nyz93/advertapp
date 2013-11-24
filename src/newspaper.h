#ifndef _NEWSPAPER_H_
#define _NEWSPAPER_H_
#include <string>
#include "advertenum.h"
using namespace std;
class Newspaper {
    string name;
    int textPrice, imagePrice, textImagePrice;
    public:
    Newspaper(const string& name): name(name) {}
    int getPriceFor(AdvertType type) const {
        switch(type) {
            case AdvertType::Image:
                return imagePrice;
            case AdvertType::Text:
                return textPrice;
            case AdvertType::TextImage:
                return textImagePrice;
        }
    }
    void setPriceFor(AdvertType type, int price) {
        switch(type) {
            case AdvertType::Image:
                imagePrice=price;
            case AdvertType::Text:
                textPrice=price;
            case AdvertType::TextImage:
                textImagePrice=price;
        }
    }
    const string& getName() const {
        return name;
    }
    virtual ~Newspaper() {}
};
#endif
