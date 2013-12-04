#include "RegisteredUser.h"

RegisteredUser::RegisteredUser(const std::string& name, const std::string& pass):User(name,pass){}

RegisteredUser::~RegisteredUser(){}

UserLevel RegisteredUser::getLevel() const {
    return UserLevel::RegisteredUser;
}
