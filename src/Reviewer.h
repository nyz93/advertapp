#ifndef REVIEWER_H
#define REVIEWER_H
#include "User.h"
#include <string>
class Reviewer: public User{
    public:
    Reviewer(const std::string& name, const std::string& pass);
    virtual UserLevel getLevel() const;
};
#endif
