#include "Reviewer.h"
Reviewer::Reviewer(const std::string& name, const std::string& pass):User(name,pass){}

UserLevel Reviewer::getLevel() const {
    return UserLevel::Reviewer;
}
