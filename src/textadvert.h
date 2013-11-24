#ifndef _TEXTADVERT_H_
#define _TEXTADVERT_H_
#include <string>
#include "advert.h"
class TextAdvert: public Advert {
    std::string text;
public:
    TextAdvert(const std::string& name,const std::vector<Newspaper*>& newspapers,
            const std::string& text):
        Advert(name,newspapers),text(text) {}
    AdvertType getType() const {
        return AdvertType.Text;
    }
    virtual ~TextAdvert() {}
};
#endif
