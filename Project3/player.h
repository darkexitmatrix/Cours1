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
    void setPlayerRole(Role* role);
    void addCard(Card* card);

    int getPlayerHealth() const;
    void removeHealth(int healthToRemove); 
    bool isPlayerDefeated() const;
    std::string getPlayerName() const;
    Character* getPlayerCharacter() const;
    Role* getPlayerRole() const;


    void removeCard(Card* card);
    const std::vector<Card*>& getCards() const;

    Card* getPlayerCard(int index) const;
    void setPlayerCard(int index, Card* card);
    void deletePlayerCard(int index);

    int getNumberOfCards() const;
private:
    std::string name;
    Character* character;
    Role* role;
    std::vector<Card*> cards;
};
