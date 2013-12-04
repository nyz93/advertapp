#include "Guest.h"

Guest::Guest(): User("Guest",""){}

Guest::~Guest(){}

UserLevel Guest::getLevel() const {
    return UserLevel::Guest;
}
