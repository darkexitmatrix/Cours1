#pragma once
#include <string>
#include "role.h"

class Player {
public:
    Player();
    Player(const std::string& name);

    void setName(const std::string& name);
    void setRole(Role* role);

    int getHealthPoints() const;
    void setHealthPoints(int hp);
    bool isDefeated() const;

    std::string getName() const;
    Role* getRole() const;

private:
    std::string name;
    Role* role;
    int healthPoints;
};
