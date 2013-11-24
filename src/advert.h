#ifndef _ADVERT_H_
#define _ADVERT_H_
#include <string>
#include <vector>
#include "advertenum.h"
#include "newspaper.h"
class Advert {
    std::string name;
    int price;
    std::vector<Newspaper*> publishedIn;
    public:
    Advert(const std::string& name, const std::vector<Newspaper*>& newspapers): name(name) {
        for(auto i:newspapers){
            publishedIn.push_back(i);
        }
    }
    virtual ~Advert() {}
    const std::string& getName() const {
        return name;
    }
    int getPrice() const {
        int price=0;
        for(auto newspaper:publishedIn) {
            price+=newspaper->getPriceFor(getType());
        }
        return price;
    }
    virtual AdvertType getType() const = 0;
};
#endif
