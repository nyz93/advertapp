#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <iostream>
#include <cstdlib>
class Window {
protected:
    std::string title;	// Miért volt ez private?
    Window(const std::string& title): title(title) {}
    Window() {}
public:
    virtual void handle() = 0;
    void drawTitle();
    std::string readCommand(const std::string& prompt);
    std::string readCommand();
};
#endif
