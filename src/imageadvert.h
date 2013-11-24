#ifndef _IMAGEADVERT_H_
#define _IMAGEADVERT_H_
#include <string>
#include "advert.h"
class ImageAdvert: public Advert {
    std::string image;
public:
    ImageAdvert(const std::string& name, const std::vector<Newspaper*>& newspapers,
            const std::string& image):
        Advert(name,newspapers),image(image) {}
    AdvertType getType() const {
        return AdvertType.Image;
    }
    virtual ~ImageAdvert() {}
};
#endif
