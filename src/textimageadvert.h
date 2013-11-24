#ifndef _TEXTIMAGEADVERT_H_
#define _TEXTIMAGEADVERT_H_
#include <string>
#include "advert.h"
class TextImageAdvert: public Advert {
    std::string text;
    std::string image;
public:
    TextImageAdvert(const std::string name&, const std::vector<Newspaper*>& newspapers,
            const std::string& text, const std::string& image):
        Advert(name,newspapers),text(text),image(image) {}
    AdvertType getType() const {
        return AdvertType.TextImage;
    }
    virtual ~TextImageAdvert() {}
};
#endif
