#include "player.h"

Player::Player() : character(nullptr), role(nullptr) {}

Player::Player(const std::string& name) : name(name), character(nullptr), role(nullptr) {}

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

bool Player::isPlayerDefeated() const {
    return getPlayerHealth() <= 0;
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

void Player::addCard(Card* card) {
    cards.push_back(card);
}

void Player::removeCard(Card* card) {
    auto it = std::find(cards.begin(), cards.end(), card);
    if (it != cards.end()) {
        cards.erase(it);
    }
}

std::vector<Card*>& Player::getCards() {
    return cards;
}

Card* Player::getPlayerCard(int index) const {
    if (index >= 0 && index < cards.size()) {
        return cards[index];
    }
    else {
        return nullptr;
    }
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
