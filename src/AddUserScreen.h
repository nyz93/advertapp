#ifndef ADDUSERSCREEN_H
#define ADDUSERSCREEN_H
#include "User.h"
#include "Reviewer.h"
#include "Admin.h"
#include "RegisteredUser.h"
#include "Screen.h"
#include "CancellableAction.h"
#include <string>
class AddUserScreen: public Screen, public CancellableAction<User*> {
    public:
    AddUserScreen();
    virtual void show();
    virtual ~AddUserScreen();
};
#endif
