#include "GameManager.h"
#include <iostream>
using namespace std;

int main() {
    GameManager gameManager;

    gameManager.setupGame(); 
    int numberOfPlayers = gameManager.getNumberOfPlayers(); // get le nbr des joueurs
    gameManager.startGame();

    return 0;
}
