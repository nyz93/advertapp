#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <iostream>
#include <cstdlib>
class Screen {
    std::string title;
    protected:
    Screen(const std::string& title): title(title) {}
    Screen() {}
    public:
    virtual void show() = 0;
    void drawTitle() {
#ifdef _WIN32
        std::system("cls");
#else //assuming linux, yeah, I know
        std::system("clear");
#endif
        std::cout << "   " << title << std::endl;
        std::cout << "================================" << std::endl;
    }
    std::string readCommand(const std::string& prompt) {
        std::cout << prompt;
        std::string cmd;
        std::getline(std::cin,cmd);
        return cmd;
    }
    std::string readCommand() {
        return readCommand("> ");
    }
};
#endif
