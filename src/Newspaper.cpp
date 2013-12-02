#include "Newspaper.h"

int Newspaper::getPriceFor(AdvertType type) const {
	switch(type) {
		case AdvertType::Image:
			return imagePrice;
		case AdvertType::Text:
			return textPrice;
		case AdvertType::TextImage:
			return textImagePrice;
	}
	return 0;
}

void Newspaper::setPriceFor(AdvertType type, int price) {
	switch(type) {
		case AdvertType::Image:
			imagePrice=price;
		case AdvertType::Text:
			textPrice=price;
		case AdvertType::TextImage:
			textImagePrice=price;
	}
}

const string& Newspaper::getName() const {
	return name;
}
