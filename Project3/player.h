#pragma once

#include <string>
#include <vector>
#include "character.h"
#include "role.h"
#include "card.h"

class Player {
public:
    Player();
    Player(const std::string& name);

    void setPlayerName(const std::string& name);
    void setPlayerCharacter(Character* character);
    void setRole(Role* role);
    void addCard(Card* card);

    int getPlayerHealth() const;
    bool isPlayerDefeated() const;
    std::string getPlayerName() const;
    Character* getPlayerCharacter() const;
    Role* getRole() const;

    void removeCard(Card* card);
    std::vector<Card*>& getCards();

    Card* getPlayerCard(int index) const;
    void setPlayerCard(int index, Card* card);
    void deletePlayerCard(int index);

private:
    std::string name;
    Character* character;
    Role* role;
    std::vector<Card*> cards;
};
