#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include <string>
#include <sstream>
#include "window.h"
using namespace std;
class AdvertApp;
class MainMenu : Window {
    AdvertApp* app;
public:
    MainMenu (AdvertApp* app):Window("Main menu"),app(app){}
    virtual ~MainMenu() {}
    virtual void handle();
};
#endif
