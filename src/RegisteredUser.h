#ifndef REGISTEREDUSER_H
#define REGISTEREDUSER_H
#include "User.h"
class RegisteredUser: public User
{
public:
    RegisteredUser (const std::string& name, const std::string& pass);
    virtual ~RegisteredUser();
    virtual UserLevel getLevel() const;
};
#endif
