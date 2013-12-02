#include "window.h"

void Window::drawTitle() {
#ifdef _WIN32
	std::system("cls");
#else //assuming linux, yeah, I know
	std::system("clear");
#endif
	std::cout << "   " << title << std::endl;
	std::cout << "================================" << std::endl;
}
std::string Window::readCommand(const std::string& prompt) {
	std::cout << prompt;
	std::string cmd;
	std::getline(std::cin,cmd);
	return cmd;
}
std::string Window::readCommand() {
	return readCommand("> ");
}
