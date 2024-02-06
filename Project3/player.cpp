#include "player.h"

Player::Player() : role(nullptr) {
}

Player::Player(const std::string& name) : name(name), role(nullptr) {
}

void Player::setName(const std::string& name) {
    this->name = name;
}

void Player::setRole(Role* role) {
    this->role = role;
}

std::string Player::getName() const {
    return name;
}

Role* Player::getRole() const {
    return role;
}
