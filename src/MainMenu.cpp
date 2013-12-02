#include "MainMenu.h"
#include "AdvertApp.h"

void MainMenu::handle() {
    bool quit = false;
    do {
        stringstream cmdstring;
        //cmdstring << "[";
        const User* currentUser = app->getCurrentUser(); 
        drawTitle();
        if(currentUser == nullptr) {
            cout << "Guest user" << endl;
            cout << "(r)egister" << endl;
            cout << "(l)ist offers" << endl;
            cmdstring  << ",r,l";
        } else { // at this point everyone is standard or above
            UserLevel level = currentUser ->getLevel();
            cout << "Logged in as: " << currentUser->getName() << endl;
            cout << "add (a)dvert" << endl;
            cout << "(e)dit advert" << endl;
            cout << "(l)ist advert" << endl;
            cmdstring << ",a,e,l";
            if(level == UserLevel::Reviewer || level == UserLevel::Admin) {
                cout << "(r)eview advert" << endl;
                cout << "add (n)ewspaper" << endl;
                cout << "(e)dit (n)ewspaper" << endl;
                cmdstring  << ",r,n,en";
            }
            cout << "(l)ist (n)ewspaper" << endl;
            cmdstring  << ",ln";
            if(level == UserLevel::Admin) {
                cout << "(a)dd (u)ser" << endl;
                cout << "(e)dit (u)ser" << endl;
            cmdstring  << ",au,eu";
            }
        }
        cout << "(q)uit" << endl;
        cmdstring  << ",q] > ";
        string prompt = cmdstring.str();
        prompt[0] = '[';
        string cmd = readCommand(prompt);
        if(cmd == "q") {
            quit = true;
        }else if(cmd == "a") {
            app->addAdvert();
        }else if(cmd == "l") {
            app->listAdvert();
        }
    }while(!quit);
}
