#include "player.h"
#include <algorithm>

Player::Player() : character(nullptr), role(nullptr) {}

Player::Player(const std::string& name) : name(name), character(nullptr), role(nullptr) {}

void Player::setPlayerName(const std::string& name) {
    this->name = name;
}

void Player::setPlayerCharacter(Character* character) {
    this->character = character;
}

void Player::setPlayerRole(Role* role) {
    this->role = role;
}

int Player::getPlayerHealth() const {
    return (character != nullptr) ? character->getCharacterHealth() : 0;
}

bool Player::isPlayerDefeated() const {
    return getPlayerHealth() <= 0;
}

std::string Player::getPlayerName() const {
    return name;
}

Character* Player::getPlayerCharacter() const {
    return character;
}

Role* Player::getPlayerRole() const {
    return role;
}

void Player::addCard(Card* card) {
    cards.emplace_back(card);
}

void Player::removeCard(Card* card) {
    auto it = std::find(cards.begin(), cards.end(), card);
    if (it != cards.end()) {
        cards.erase(it);
    }
}

const std::vector<Card*>& Player::getCards() const {
    return cards;
}

Card* Player::getPlayerCard(int index) const {
    return (index >= 0 && index < cards.size()) ? cards[index] : nullptr;
}

void Player::setPlayerCard(int index, Card* card) {
    if (index >= 0 && index < cards.size()) {
        cards[index] = card;
    }
}

void Player::deletePlayerCard(int index) {
    if (index >= 0 && index < cards.size()) {
        delete cards[index];
        cards.erase(cards.begin() + index);
    }
}

int Player::getNumberOfCards() const {
    return cards.size();
}
/*void Player::removeHealth(int healthToRemove) { // Implémentation de la fonction removeHealth
    if (character != nullptr) {
        character->removeHealth(healthToRemove);
    }
}*/