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
