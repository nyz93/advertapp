/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2013 Zoltán Nyikos
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
	int days = creationDate.diffDays(validUntil)+1;
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
void Advert::setNewspapers(const vector<Newspaper*>& nnp) {
    publishedIn = nnp;
}
AdvertStatus Advert::getStatus() const {
    return status;
}
void Advert::setStatus(AdvertStatus ns) {
    status=ns;
}
void Advert::setCreator(User* nc) {
    user=nc;
}
