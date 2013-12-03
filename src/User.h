#ifndef USER_H
#define USER_H
#include <string>
enum class UserLevel { Guest, RegisteredUser, Reviewer, Admin };
class User {
    std::string name;
    std::string pass;
    public:
    User(const std::string& name, const std::string& pass);
    const std::string& getName() const;
    bool isPassword(const std::string& pass) const;
    const std::string& getPassword() const; //gonna get to hell for this
    virtual ~User() {}
    virtual UserLevel getLevel() const = 0;
};
#endif
