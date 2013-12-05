#ifndef USERLEVELSELECTIONSCREEN_H
#define USERLEVELSELECTIONSCREEN_H
#include "Screen.h"
#include "Action.h"
#include "User.h"
class UserLevelSelectionScreen: public Screen, public Action<UserLevel> {
    public:
    UserLevelSelectionScreen();
    virtual ~UserLevelSelectionScreen();
    virtual void show();
};
#endif
