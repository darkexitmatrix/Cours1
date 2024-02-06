#include "role.h"

Role::Role(const string& name, int number) : name(name), number(number) {}

string Role::getName() const {
    return name;
}

int Role::getNumber() const {
    return number;
}

Shogun::Shogun(const string& name, int number) : Role(name, number) {}

Samurai::Samurai(const string& name, int number) : Role(name, number) {}

Ronin::Ronin(const string& name, int number) : Role(name, number) {}

Ninja::Ninja(const string& name, int number) : Role(name, number) {}
