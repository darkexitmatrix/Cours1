#pragma once
#include <vector>
#include "Player.h"
#include "Card.h" 

using namespace std;

class GameManager {
public:
    GameManager();
    ~GameManager();  
    void setupGame();
    void startGame();
    int getNumberOfPlayers() const;
    void displayHealthPoints() const;
    void playNextTurn();

private:
    vector<Player> players;
    vector<Card*> cards;  
    int numberOfPlayers;
    int currentPlayerIndex;
    void initializePlayers(int numberOfPlayers);
    void distributeRoles();
    void distributeCharacters();
    void distributeCards();

    
    
};

