#ifndef _NEWSPAPER_H_
#define _NEWSPAPER_H_
#include <string>
#include "advertenum.h"
class Newspaper {
    std::string name;
    int textPrice, imagePrice, textImagePrice;
    Newspaper(const std::string& name): name(name) {}
    public:
    int getPriceFor(AdvertType type) {
        switch(type) {
            case AdvertType::Image:
                return imagePrice;
            case AdvertType::Text:
                return textPrice;
            case AdvertType::TextImage:
                return textImagePrice;
        }
    }
    void setTextPrice(int np) {
        textPrice = np;
    }
    void setImagePrice(int np) {
        imagePrice = np;
    }
    void setTextImagePrice(int np) {
        textImagePrice = np;
    }
    virtual ~Newspaper() {}
};
#endif
