#ifndef EDITUSERSCREEN_H
#define EDITUSERSCREEN_H
#include "CancellableAction.h"
#include "RegisteredUser.h"
#include "Reviewer.h"
#include "Admin.h"
#include "Screen.h"
#include "UserLevelSelectionScreen.h"
#include "MessageScreen.h"
#include <vector>
class EditUserScreen: public Screen, public CancellableAction<User*> {
    const User* old;
    const std::vector<User*> users;
    public:
    EditUserScreen(const std::vector<User*>&,const User*);
    virtual void show();
    virtual ~EditUserScreen();
};
#endif
