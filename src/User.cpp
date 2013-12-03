#include "User.h"

User::User(const std::string& name, const std::string& pass): name(name),pass(pass){}
const std::string& User::getName() const {
	return name;
}
bool User::isPassword(const std::string& pass) const {
	return this->pass==pass;
}
