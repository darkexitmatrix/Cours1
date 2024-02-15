#pragma once
#include <string>
using namespace std;

class Role {
public:
    Role(const string& name, int number);

    string getName() const;
    int getNumber() const;

private:
    string name;
    int number;
};

class Shogun : public Role {
public:
    Shogun(const string& name, int number);
};

class Samurai : public Role {
public:
    Samurai(const string& name, int number);
};

class Ronin : public Role {
public:
    Ronin(const string& name, int number);
};

class Ninja : public Role {
public:
    Ninja(const string& name, int number);
};