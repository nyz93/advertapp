#include "ListAdvertScreen.h"

ListAdvertScreen::ListAdvertScreen(const vector<const Advert*>& adverts):Screen("Adverts"), adverts(adverts){
}
void ListAdvertScreen::show() {
	bool completed = false;
	do{
		drawTitle();
		for(auto ad: adverts) {
			cout << ad->getName() << endl;
		}
		cout << "(b)ack" << endl;
		string cmd = readCommand("[b] > ");
		if(cmd == "b") {
			completed = true;
		}
	}while(!completed);
}
