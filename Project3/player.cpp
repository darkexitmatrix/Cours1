<<<<<<< HEAD
// player.cpp
#include "player.h"
#include "character.h"
using namespace std;

Player::Player() : character(nullptr), healthPoints(0) {
}

Player::Player(const std::string& name) : name(name), character(nullptr), healthPoints(0) {
}

void Player::setPlayerName(const std::string& name) {
    this->name = name;
}

void Player::setPlayerCharacter(Character* character) {
    this->character = character;
}
void Player::setRole(Role* role) {
    this->role = role;
}

int Player::getPlayerHealth() const {
    if (character != nullptr) {
        return character->getCharacterHealth(); 
    }
    else {
        return 0;
    }
}


void Player::setPlayerHealth(int hp) {
    healthPoints = hp;
}

bool Player::isPlayerDefeated() const {
    return healthPoints <= 0;
}

std::string Player::getPlayerName() const {
    return name;
}

Character* Player::getPlayerCharacter() const {
    return character;
}
Role* Player::getRole() const {
    return role;
}
=======
    #include "player.h"

    Player::Player() : role(nullptr), healthPoints(0) {
    }

    Player::Player(const std::string& name) : name(name), role(nullptr), healthPoints(0) {
    }

    void Player::setName(const std::string& name) {
        this->name = name;
    }

    void Player::setRole(Role* role) {
        this->role = role;
    }

    int Player::getHealthPoints() const {
        return healthPoints;
    }

    void Player::setHealthPoints(int hp) {
        healthPoints = hp;
    }

    bool Player::isDefeated() const {
        return healthPoints <= 0;
    }

    std::string Player::getName() const {
        return name;
    }

    Role* Player::getRole() const {
        return role;
    }
>>>>>>> 1ca5599a4e6e1ae52d94a8f163e67fe4dc027e8f
