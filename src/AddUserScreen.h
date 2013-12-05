#ifndef ADDUSERSCREEN_H
#define ADDUSERSCREEN_H
#include "User.h"
#include "Reviewer.h"
#include "Admin.h"
#include "RegisteredUser.h"
#include "Screen.h"
#include "MessageScreen.h"
#include "CancellableAction.h"
#include "UserLevelSelectionScreen.h"
#include <string>
#include <vector>
class AddUserScreen: public Screen, public CancellableAction<User*> {
    const std::vector<User*> users;
    public:
    AddUserScreen(const std::vector<User*>& users);
    virtual void show();
    virtual ~AddUserScreen();
};
#endif
