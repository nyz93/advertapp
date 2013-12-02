#include "listadvertwindow.h"

ListAdvertWindow::ListAdvertWindow(const vector<const Advert*>& adverts):Window("Adverts"), adverts(adverts){
}
void ListAdvertWindow::handle() {
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
