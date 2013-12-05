#include "AdvertApp.h"

AdvertApp::AdvertApp():db("main.db"),mainMenu(this) {
	// TODO: load users, ads, newspapers
    newspapers = db.getNewspapers();
    users = db.getUsers();
    adverts = db.getAdverts();
}

const User* AdvertApp::getCurrentUser() const {
	return currentUser;
}

void AdvertApp::addAdvert() {
	AddAdvertScreen aw(*newspapers,currentUser);
	aw.show();
	if(!aw.isCancelled()) {
		Advert* ad = aw.getResult();
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
void AdvertApp::editAdvert() {
    vector<Advert*> toList;
    bool own = (currentUser->getLevel() == UserLevel::RegisteredUser);
    if(!own) {
        toList = *adverts;
    }else{
        for(auto ad: *adverts) {
            if(currentUser == ad->getCreator()) {
                toList.push_back(ad);
            }
        }
    }
	AdvertSelectionScreen lw(toList,!own);
    lw.show();
    if(!lw.isCancelled()) {
        Advert* ad = lw.getResult();
        EditAdvertScreen eas(*newspapers,ad);
        eas.show();
        if(!eas.isCancelled()) {
            Advert* newad = eas.getResult();
            newad->setStatus(AdvertStatus::Waiting);
            db.replaceAdvert(ad,newad);
        }
    }
}

void AdvertApp::deleteAdvert() {
    vector<Advert*> toList;
    bool own = (currentUser->getLevel() == UserLevel::RegisteredUser);
    if(!own) {
        toList = *adverts;
    }else{
        for(auto ad: *adverts) {
            if(currentUser == ad->getCreator()) {
                toList.push_back(ad);
            }
        }
    }
	AdvertSelectionScreen lw(toList,!own);
    lw.show();
    if(!lw.isCancelled()) {
        Advert* ad = lw.getResult();
        db.deleteAdvert(ad);
    }
}

void AdvertApp::reviewAdvert() {
    vector<Advert*> toList;
    bool own = (currentUser->getLevel() == UserLevel::RegisteredUser);
    if(!own) {
        toList = *adverts;
    }else{
        for(auto ad: *adverts) {
            if(currentUser == ad->getCreator()) {
                toList.push_back(ad);
            }
        }
    }
	AdvertSelectionScreen lw(toList,!own);
    lw.show();
    if(!lw.isCancelled()) {
        Advert* ad = lw.getResult();
        ReviewAdvertScreen rs(ad);
        rs.show();
        if(!rs.isCancelled()) {
            ad->setStatus(rs.getResult());
        }
    }
}

void AdvertApp::addUser() {
    AddUserScreen us(*users);
    us.show();
    if(!us.isCancelled()) {
        users->push_back(us.getResult());
    }
}

void AdvertApp::editUser() {
}
void AdvertApp::deleteUser() {
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
			currentUser = new Guest();
			loggedIn = true;
		}
	}while(!loggedIn);
}

void AdvertApp::start() {
	login();
	mainMenu.show();
}

AdvertApp::~AdvertApp() {
    if(currentUser->getLevel() == UserLevel::Guest) {
        delete currentUser;
    }
}
