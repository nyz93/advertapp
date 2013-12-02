#include "AdvertApp.h"

AdvertApp::AdvertApp():mainMenu(this) {
	// TODO: load users, ads, newspapers
	User t("user","pass",UserLevel::Admin);
	users.push_back(t);
	currentUser=&users[0];
	Newspaper* np = new Newspaper("Daily News");
	np->setPriceFor(AdvertType::Image,100);
	np->setPriceFor(AdvertType::Text,200);
	np->setPriceFor(AdvertType::TextImage,350);
	newspapers.push_back(np);
}

const User* AdvertApp::getCurrentUser() const {
	return currentUser;
}

void AdvertApp::addAdvert() {
	AddAdvertWindow aw(newspapers,currentUser);
	aw.handle();
	if(!aw.isCancelled()) {
		Advert* ad = new Advert(aw.getAdvert());
		adverts.push_back(ad);
	}
}

void AdvertApp::listAdvert() {
	vector<const Advert*> toList;
	for(auto ad: adverts) {
		if(currentUser == ad->getCreator()) {
			toList.push_back(ad);
		}
	}
	ListAdvertWindow lw(toList);
	lw.handle();
}

void AdvertApp::reviewAdvert() {
}

void AdvertApp::addUser() {
}

void AdvertApp::editUser() {
}

void AdvertApp::listNewspapers() {
}

void AdvertApp::addNewspaper() {
}

void AdvertApp::editNewspaper() {
}

void AdvertApp::registerUser() {
}

void AdvertApp::login() {
	bool loggedIn = false;
	do {
		LoginWindow l;
		l.handle();
		if(!l.isGuest()) {
			string name = l.getUsername();
			string pass = l.getPassword();
			for(auto user = users.begin(); user != users.end(); user++) {
				if(user->getName() == name && user->isPassword(pass)) {
					currentUser = &*user;
					loggedIn = true;
				}
			}
			if(!loggedIn) {
				MessageWindow wnd("Login error, invalid username or password!");
				wnd.handle();
			}
		}else{ //guest
			currentUser = nullptr;
			loggedIn = true;
		}
	}while(!loggedIn);
}

void AdvertApp::start() {
	//login();
	mainMenu.handle();
	close();
}

void AdvertApp::close() {
	//TODO:save stuff
}

AdvertApp::~AdvertApp() {
	for(auto npp : newspapers) {
		delete npp;
	}
	for(auto adp : adverts) {
		delete adp;
	}
}
