#include "Screen.h"

Screen::Screen(const std::string& title): title(title) {}
void Screen::drawTitle() {
#ifdef _WIN32
	//std::system("cls");
#else //assuming linux, yeah, I know
	//std::system("clear");
#endif
	std::cout << "   " << title << std::endl;
	std::cout << "================================" << std::endl;
}
std::string Screen::readCommand(const std::string& prompt) {
	std::cout << prompt;
	std::string cmd;
	std::getline(std::cin,cmd);
	return cmd;
}
std::string Screen::readCommand() {
	return readCommand("> ");
}
