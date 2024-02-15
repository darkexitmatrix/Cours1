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