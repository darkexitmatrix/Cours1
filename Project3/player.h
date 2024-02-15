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

<<<<<<< HEAD
    std::string getPlayerName() const;
    Character* getPlayerCharacter() const;
=======
    int getHealthPoints() const;
    void setHealthPoints(int hp);
    bool isDefeated() const;

    std::string getName() const;
>>>>>>> 1ca5599a4e6e1ae52d94a8f163e67fe4dc027e8f
    Role* getRole() const;
private:
    std::string name;
    Character* character;
    Role* role;
    int healthPoints;
};

