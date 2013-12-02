#include "adverttypeselectionwindow.h"

AdvertType AdvertTypeSelectionWindow::getType() const {
	return type;
}

void AdvertTypeSelectionWindow::handle() {
	bool complete = false;
	do {
		cout << "(i)mage advert" << endl;
		cout << "(t)ext advert" << endl;
		cout << "(t)ext (i)mage advert" << endl;
		string cmd = readCommand("[i,t,ti] > ");
		if(cmd == "i") {
			type = AdvertType::Image;
			complete = true;
		}else if(cmd == "t") {
			type = AdvertType::Text;
			complete = true;
		}else if(cmd == "ti") {
			type = AdvertType::TextImage;
			complete = true;
		}
	}while(!complete);
}
