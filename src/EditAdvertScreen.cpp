#include "EditAdvertScreen.h"

EditAdvertScreen::EditAdvertScreen(const vector<Newspaper*>& newspapers, const Advert* a) : Screen("Edit advertisment"),newspapers(newspapers),old(a) {}

void EditAdvertScreen::show() {
	drawTitle();
	bool complete = false;
    AdvertType type = old->getType();
    const User* currentUser = old->getCreator();
	string name = old->getName();
	string image = old->getImage();
	string text = old->getText();
	vector<Newspaper*> selection = old->getNewspapers();
	Date validUntil = old->getExpirationDate();
	do {
        Advert tmpad;
		stringstream cmdline;
		drawTitle();
		cout << "(n)ame: " << name << endl;
		cmdline << ",n";
		switch(type) {
			case AdvertType::Image: {
				cout << "(i)mage: " << image << endl;
				cmdline << ",i";
			}break;
			case AdvertType::Text: {
				cout << "(t)ext: " << text << endl;
				cmdline << ",t";
			}break;
			case AdvertType::TextImage: {
				cout << "(t)ext: " << text << endl;
				cout << "(i)mage: " << image << endl;
				cmdline << ",t,i";
			}break;
		}
        cout << "(ty)pe: ";
		cmdline << ",ty";
        switch(type) {
            case AdvertType::Text:
                cout << "text";
                break;
            case AdvertType::Image:
                cout << "image";
                break;
            case AdvertType::TextImage:
                cout << "text-image";
                break;
        }
        cout << endl;
		cout << "(s)et expiration (d)ate" << endl;
		cmdline << ",sd";
		cout << "(s)elect (n)newspapers" << endl;
        cmdline << ",sn";
        switch(type) {
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
        if(selection.size() > 0) {
            cout << "(f)inish" << endl;
            cmdline << ",f";
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
			}
		}else if(cmd == "i" && (type == AdvertType::Image || type == AdvertType::TextImage)) {
			image = readCommand("image > ");
		}else if(cmd == "t" && (type == AdvertType::Text || type == AdvertType::TextImage)) {
			text = readCommand("text > ");
		}else if(cmd == "c") {
			cancelled = true;
			complete = true;
		}else if(cmd == "f" && selection.size() > 0) {
			complete = true;
			result = new Advert(tmpad);
		}else if(cmd == "ty") {
            AdvertTypeSelectionScreen ts;
            ts.show();
            type = ts.getType();
        }
	}while(!complete);
}
