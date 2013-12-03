#include "Advert.h"

Advert::Advert(const string& name, const User* user, const Date& date, const vector<Newspaper*>& newspapers, AdvertType type): name(name),type(type),user(user),status(AdvertStatus::Waiting),validUntil(date) {
	for(auto i:newspapers){
		publishedIn.push_back(i);
	}
}

Advert Advert::imageAdvert(const string& name, const string& image, const User* user, const Date& date, const vector<Newspaper*>& newspapers) {
	Advert ret(name,user,date,newspapers,AdvertType::Image);
	ret.image = image;
	return ret;
}

Advert Advert::textAdvert(const string& name, const string& text, const User* user, const Date& date, const vector<Newspaper*>& newspapers) {
	Advert ret(name,user,date,newspapers,AdvertType::Text);
	ret.text = text;
	return ret;
}

Advert Advert::textImageAdvert(const string& name, const string& text,const string& image, const User* user, const Date& date, const vector<Newspaper*>& newspapers) {
	Advert ret(name,user,date,newspapers,AdvertType::TextImage);
	ret.text = text;
	ret.image = image;
	return ret;
}

const string& Advert::getName() const {
	return name;
}

void Advert::setName(const string& name) {
	this->name = name;
}

const string& Advert::getImage() const {
	return image;
}

void Advert::setImage(const string& image) {
	this->image = image;
}

const string& Advert::getText() const {
	return text;
}

void Advert::setText(const string& text) {
	this->text = text;
}

int Advert::getPrice() const {
	int price=0;
	int days = creationDate.diffDays(validUntil);
	for(auto newspaper:publishedIn) {
		price+=(newspaper->getPriceFor(getType()) * days);
	}
	return price;
}

AdvertType Advert::getType() const {
	return type;
}

const User* Advert::getCreator() const {
	return user;
}

bool Advert::isValid() const {
	return validUntil > Date();
}

void Advert::setCreationDate(const Date& nd) {
	creationDate = nd;
}

const Date& Advert::getCreationDate() const {
    return creationDate;
}
const Date& Advert::getExpirationDate() const{
    return validUntil;
}
const vector<Newspaper*>& Advert::getNewspapers() const {
    return publishedIn;
}
AdvertStatus Advert::getStatus() const {
    return status;
}
void Advert::setStatus(AdvertStatus ns) {
    status=ns;
}
