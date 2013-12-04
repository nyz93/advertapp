#ifndef GUEST_H
#define GUEST_H
#include "User.h"
class Guest:public User {
public:
    Guest();
    virtual ~Guest();
    virtual UserLevel getLevel() const;
};
#endif
