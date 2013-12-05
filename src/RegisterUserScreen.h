#ifndef REGISTERUSERSCREEN_H
#define REGISTERUSERSCREEN_H
#include "Screen.h"
#include "CancellableAction.h"
#include "User.h"
#include "RegisteredUser.h"
#include "MessageScreen.h"
#include <vector>
class RegisterUserScreen : public Screen, public CancellableAction<User*> {
    const std::vector<User*> users;
    public:
        RegisterUserScreen(const std::vector<User*>& users);
        virtual ~RegisterUserScreen();
        virtual void show();
};
#endif
