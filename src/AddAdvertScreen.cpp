#include "AddAdvertScreen.h"

AddAdvertScreen::AddAdvertScreen(const vector<Newspaper*>& newspapers, const User* currentUser):Screen("Add advert"), currentUser(currentUser){
	for(auto np : newspapers) {
		this->newspapers.push_back(np);
	}
}

void AddAdvertScreen::show() {
	drawTitle();
	bool complete = false;
	AdvertTypeSelectionScreen ts;
	ts.show();
	string name;
	string image;
	string text;
	vector<Newspaper*> selection;
	Date validUntil;
	bool dateSet = false;
	do {
		Advert tmpad;
		bool canSend = false;
		cancelled = false;
		stringstream cmdline;
		drawTitle();
		cout << "(n)ame: " << name << endl;
		cmdline << ",n";
		switch(ts.getType()) {
			case AdvertType::Image: {
				cout << "(i)mage: " << image << endl;
				cmdline << ",i";
				if(image != "" && name != "" && selection.size() && dateSet) {
					canSend = true;
				}
			}break;
			case AdvertType::Text: {
				cout << "(t)ext: " << text << endl;
				cmdline << ",t";
				if(text != "" && name != "" && selection.size() && dateSet) {
					canSend = true;
				}
			}break;
			case AdvertType::TextImage: {
				cout << "(t)ext: " << text << endl;
				cout << "(i)mage: " << image << endl;
				cmdline << ",t,i";
				if(text != "" && image != "" && name != "" && selection.size() && dateSet) {
					canSend = true;
				}
			}break;
		}
		cout << "(s)et expiration (d)ate" << endl;
		cmdline << ",sd";
		cout << "(s)elect (n)newspapers" << endl;
		cmdline << ",sn";
		if(canSend) {
			switch(ts.getType()) {
				case AdvertType::Image: {
					tmpad = Advert::imageAdvert(name,image,currentUser,validUntil,selection);
				}break;
				case AdvertType::Text: {
					tmpad = Advert::textAdvert(name,text,currentUser,validUntil,selection);
				}break;
				case AdvertType::TextImage: {
					tmpad = Advert::textImageAdvert(name,text,image,currentUser,validUntil,selection);
				}break;
			}
			int price = tmpad.getPrice();
			cout << "current price: $ " << price << endl;
			cout << "(s)end" << endl;
			cmdline << ",s";
		}
		cout << "(c)ancel" << endl;
		cmdline << ",c] > ";
		string prompt = cmdline.str();
		prompt[0]='[';
		string cmd = readCommand(prompt);
		if(cmd == "n") {
			name = readCommand("name > ");
		}else if(cmd == "sn") {
			NewspaperSelectionScreen sw(newspapers,selection);
			sw.show();
			if(!sw.isCancelled()) {
				selection = sw.getResult();
			}
		}else if(cmd == "sd") {
			DateSelectionScreen dw(validUntil);
			dw.show();
			if(!dw.isCancelled()) {
				validUntil = dw.getResult();
				dateSet = true;
			}
		}else if(cmd == "i" && (ts.getType() == AdvertType::Image || ts.getType() == AdvertType::TextImage)) {
			image = readCommand("image > ");
		}else if(cmd == "t" && (ts.getType() == AdvertType::Text || ts.getType() == AdvertType::TextImage)) {
			text = readCommand("text > ");
		}else if(cmd == "c") {
			cancelled = true;
			complete = true;
		}else if(cmd == "s" && canSend) {
			complete = true;
			result = new Advert(tmpad);
		}
	}while(!complete);
}
