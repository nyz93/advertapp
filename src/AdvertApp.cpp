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
    if(toList.size() == 0) {
        MessageScreen ms("No adverts!");
        ms.show();
    }else{
        ListScreen<const Advert*> lw(toList, [](const Advert* ad) -> string {
                return ad->getName();
                });
        lw.show();
    }
}

void AdvertApp::listAllAdvert() {
    if(adverts->size() == 0) {
        MessageScreen ms("No adverts!");
        ms.show();
    }else{
    ListScreen<Advert*> lw(*adverts, [](Advert* ad) -> string {
            stringstream ss;
            ss << ad->getName() << ", by: " << ad->getCreator()->getName();
            return ss.str();
            });
	lw.show();
    }
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
    if(toList.size() == 0) {
        MessageScreen ms("No adverts!");
        ms.show();
    }else{
        SelectionScreen<Advert*>::Converter t;
        if(own) {
            t = [](Advert* ad) -> string { return ad->getName(); };
        }else {
            t = [](Advert* ad) -> string { return ad->getName() + " " + ad->getCreator()->getName(); };
        }
        SelectionScreen<Advert*> lw2(toList,t);
        lw2.show();
        if(!lw2.isCancelled()) {
            Advert* ad = lw2.getResult();
            EditAdvertScreen eas(*newspapers,ad);
            eas.show();
            if(!eas.isCancelled()) {
                Advert* newad = eas.getResult();
                newad->setStatus(AdvertStatus::Waiting);
                db.replaceAdvert(ad,newad);
            }
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
    if(toList.size() == 0) {
        MessageScreen ms("No adverts!");
        ms.show();
    }else{
        SelectionScreen<Advert*>::Converter t;
        if(own) {
            t = [](Advert* ad) -> string { return ad->getName(); };
        }else {
            t = [](Advert* ad) -> string { return ad->getName() + " " + ad->getCreator()->getName(); };
        }
        SelectionScreen<Advert*> lw(toList,t);
        lw.show();
        if(!lw.isCancelled()) {
            Advert* ad = lw.getResult();
            db.deleteAdvert(ad);
        }
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
    SelectionScreen<Advert*>::Converter t;
    if(own) {
        t = [](Advert* ad) -> string { return ad->getName(); };
    }else {
        t = [](Advert* ad) -> string { return ad->getName() + " " + ad->getCreator()->getName(); };
    }
    if(toList.size() == 0) {
        MessageScreen ms("No adverts!");
        ms.show();
    }else{
        SelectionScreen<Advert*> lw(toList,t);
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
}

void AdvertApp::addUser() {
    AddUserScreen us(*users);
    us.show();
    if(!us.isCancelled()) {
        users->push_back(us.getResult());
    }
}

void AdvertApp::editUser() {
    SelectionScreen<User*> su(*users,[](User* u) -> string { return u->getName(); });
    su.show();
    if(!su.isCancelled()) {
        User* res = su.getResult();
        EditUserScreen es(*users,res);
        es.show();
        if(!es.isCancelled()) {
            db.replaceUser(res,es.getResult());
        }
    }
}
void AdvertApp::deleteUser() {
    SelectionScreen<User*> su(*users,[](User* u) -> string { return u->getName(); });
    su.setTitle("Removing a user will also remove EVERY advert by that user!");
    su.show();
    if(!su.isCancelled()) {
        User* res = su.getResult();
        if(res == currentUser) {
            MessageScreen ms("You can't delete yourself!");
            ms.show();
        }else{
            db.deleteUser(res);
        }
    }
}

void AdvertApp::listNewspapers() {
    if(newspapers->size() == 0) {
        MessageScreen ms("No newspapers!");
        ms.show();
    }else{
        ListScreen<Newspaper*> ls(*newspapers, [](Newspaper* np) -> string {
                stringstream ss;
                ss << "name: " << np->getName() << ",";
                ss << " prices: (/day)";
                ss << " text: " << np->getPriceFor(AdvertType::Text) << 
                "$, image: " << np->getPriceFor(AdvertType::Image) <<
                "$, text-image: " << np->getPriceFor(AdvertType::TextImage) << "$";
                return ss.str();
                });
        ls.show();
    }
}

void AdvertApp::addNewspaper() {
    AddNewspaperScreen ans;
    ans.show();
    if(!ans.isCancelled()) {
        newspapers->push_back(ans.getResult());
    }
}

void AdvertApp::editNewspaper() {
    SelectionScreen<Newspaper*> ss(*newspapers, [](Newspaper* np) -> string {
            return np->getName();
            });
    ss.setTitle("Select newspaper to edit");
    ss.show();
    if(!ss.isCancelled()) {
        Newspaper* old = ss.getResult();
        EditNewspaperScreen ens(old);
        ens.show();
        if(!ens.isCancelled()) {
            db.replaceNewspaper(old,ens.getResult());
        }
    }
}

void AdvertApp::deleteNewspaper() {
    SelectionScreen<Newspaper*> ss(*newspapers, [](Newspaper* np) -> string {
            return np->getName();
            });
    ss.setTitle("Select newspaper to delete");
    ss.show();
    if(!ss.isCancelled()) {
        db.deleteNewspaper(ss.getResult());
    }
}

void AdvertApp::registerUser() {
    RegisterUserScreen rus(*users);
    rus.show();
    if(!rus.isCancelled()) {
        users->push_back(rus.getResult());
    }
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
