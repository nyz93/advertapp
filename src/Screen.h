#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <iostream>
#include <cstdlib>
class Screen {
protected:
    std::string title;	// Miért volt ez private?
    Screen(const std::string& title);
    Screen():title(""){} //why do we even need this huh?
public:
    virtual void show() = 0;
    void drawTitle();
    std::string readCommand(const std::string& prompt);
    std::string readCommand();
};
#endif
