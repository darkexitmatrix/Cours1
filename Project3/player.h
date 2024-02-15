// player.h
#pragma once
#include <string>
#include "character.h"
#include "role.h"

class Player {
public:
    Player();
    Player(const std::string& name);

    void setPlayerName(const std::string& name);
    void setPlayerCharacter(Character* character);
    void setRole(Role* role);
    int getPlayerHealth() const;
    void setPlayerHealth(int hp);
    bool isPlayerDefeated() const;

    std::string getPlayerName() const;
    Character* getPlayerCharacter() const;
    Role* getRole() const;
private:
    std::string name;
    Character* character;
    Role* role;
    int healthPoints;
};

