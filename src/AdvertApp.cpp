#include "AdvertApp.h"

AdvertApp::AdvertApp():db("main.db"),mainMenu(this) {
	// TODO: load users, ads, newspapers
    newspapers = db.getNewspapers();
    users = db.getUsers();
    adverts = db.getAdverts();
	//Reviewer* t = new Reviewer("user","pass");
	//users->push_back(t);
	//currentUser=users->at(0);
	//Newspaper* np = new Newspaper("Daily News");
	//np->setPriceFor(AdvertType::Image,100);
	//np->setPriceFor(AdvertType::Text,200);
	//np->setPriceFor(AdvertType::TextImage,350);
	//newspapers->push_back(np);
}

const User* AdvertApp::getCurrentUser() const {
	return currentUser;
}

void AdvertApp::addAdvert() {
	AddAdvertScreen aw(*newspapers,currentUser);
	aw.show();
	if(!aw.isCancelled()) {
		Advert* ad = new Advert(aw.getAdvert());
		adverts->push_back(ad);
	}
}

void AdvertApp::listAdvert() {
	vector<const Advert*> toList;
	for(auto ad: *adverts) {
		if(currentUser == ad->getCreator()) {
			toList.push_back(ad);
		}
	}
	ListAdvertScreen lw(toList);
	lw.show();
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
		LoginScreen l;
		l.show();
		if(!l.isGuest()) {
			string name = l.getUsername();
			string pass = l.getPassword();
			for(auto userp = users->begin(); userp != users->end(); userp++) {
                User* user = *userp;
				if(user->getName() == name && user->isPassword(pass)) {
					currentUser = user;
					loggedIn = true;
				}
			}
			if(!loggedIn) {
				MessageScreen wnd("Login error, invalid username or password!");
				wnd.show();
			}
		}else{ //guest
			currentUser = nullptr;
			loggedIn = true;
		}
	}while(!loggedIn);
}

void AdvertApp::start() {
	login();
	mainMenu.show();
}

AdvertApp::~AdvertApp() {
}
