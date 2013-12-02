#ifndef MAINMENU_H
#define MAINMENU_H
#include <string>
#include <sstream>
#include "Screen.h"
using namespace std;
class AdvertApp;
class MainMenu : Screen {
    AdvertApp* app;
public:
    MainMenu (AdvertApp* app):Screen("Main menu"),app(app){}
    virtual ~MainMenu() {}
    virtual void show();
};
#endif
