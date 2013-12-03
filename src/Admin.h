#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "Reviewer.h"
class Admin : public Reviewer {
    public:
    Admin(const std::string& name, const std::string& pass):Reviewer(name,pass){}
    virtual UserLevel getLevel() const {
        return UserLevel::Admin;
    }
};
#endif
