#include "User.h"

const std::string& User::getName() const {
	return name;
}
bool User::isPassword(const std::string& pass) const {
	return this->pass==pass;
}
UserLevel User::getLevel() const {
	return level;
}
