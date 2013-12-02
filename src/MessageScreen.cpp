#include "MessageScreen.h"

void MessageScreen::show() {
	while(true) {
		drawTitle();
		std::cout << message << endl;
		std::cout << endl << "Write 'q' to close." << endl;
		std::string cmd = readCommand();
		if(cmd == "q") {
			break;
		}
	}
}
