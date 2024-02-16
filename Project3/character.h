#pragma once
#include <string>

class Character {
public:
    Character(const std::string& name, int health, const std::string& ability);
    std::string getCharacterName() const;
    int getCharacterHealth() const;
    std::string getCharacterAbility() const;
    
private:
    std::string name;
    int healthPoints;
    std::string ability;
};

class Benkei : public Character {
public:
    Benkei();
};

class Chiyome : public Character {
public:
    Chiyome();
};

class Ginchiyo : public Character {
public:
    Ginchiyo();
};

class Goemon : public Character {
public:
    Goemon();
};

class Hanzo : public Character {
public:
    Hanzo();
};

class Hideyoshi : public Character {
public:
    Hideyoshi();
};

class Ieyasu : public Character {
public:
    Ieyasu();
};

class Kojiro : public Character {
public:
    Kojiro();
};

class Musashi : public Character {
public:
    Musashi();
};

class Nobunaga : public Character {
public:
    Nobunaga();
};

class Tomoe : public Character {
public:
    Tomoe();
};

class Ushiwaka : public Character {
public:
    Ushiwaka();
};
