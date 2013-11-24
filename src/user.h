#ifndef _USER_H_
#define _USER_H_
#include <string>
enum UserLevel { Guest, Standard, Reviewer, Admin };
class User {
    std::string name;
    std::string pass;
    UserLevel level;
    public:
    User(const std::string& name, const std::string& pass,UserLevel level):name(name),pass(pass),level(level){}
    const std::string& getName() const {
        return name;
    }
    bool isPassword(const std::string& pass) const {
        return this->pass==pass;
    }
    UserLevel getLevel() const {
        return level;
    }
    virtual ~User() {}
};
#endif
