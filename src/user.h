#ifndef USER_H
#define USER_H
#include <string>
enum UserLevel { Guest, Standard, Reviewer, Admin };
class User {
    std::string name;
    std::string pass;
    UserLevel level;
    public:
    User(const std::string& name, const std::string& pass,UserLevel level):name(name),pass(pass),level(level){}
    const std::string& getName() const;
    bool isPassword(const std::string& pass) const;
    UserLevel getLevel() const;
    virtual ~User() {}
};
#endif
