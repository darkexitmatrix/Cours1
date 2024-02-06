#include "gameManager.h"
#include "card.h"
#include "role.h"
#include "player.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

GameManager::GameManager() {
}

void GameManager::setupGame() {
    string asciiArt =
        "  dP     dP            dP                              \n"
        "  88   .d8'            88                              \n"
        "  88aaa8P'  .d8888b. d8888P .d8888b. 88d888b. .d8888b. \n"
        "  88   `8b. 88'  `88   88   88'  `88 88'  `88 88'  `88 \n"
        "  88     88 88.  .88   88   88.  .88 88    88 88.  .88 \n"
        "  dP     dP `88888P8   dP   `88888P8 dP    dP `88888P8 \n"
        "  ooooooooooooooooooooooooooooooooooooooooooooooooooooo"
        "By ESCALIBUR GROUP \n\n\n\n\n\n\n";

    cout << asciiArt << endl;


    cout << "Enter the number of players:\n"
        << "4 players: 1 shogun, 1 samurai, 2 ninjas.\n"
        << "5 players: 1 shogun, 1 samurai, 1 ronin, 2 ninjas.\n"
        << "6 players: 1 shogun, 1 samurai, 1 ronin, 3 ninjas.\n"
        << "7 players: 1 shogun, 2 samurais, 1 ronin, 3 ninjas.\n";

    cin >> this->numberOfPlayers;

    while (this->numberOfPlayers < 4 || this->numberOfPlayers > 7 || cin.fail()) {
        cout << "Invalid input. Please enter 4, 5, 6, or 7: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> this->numberOfPlayers;
    }

    initializePlayers(this->numberOfPlayers);
    distributeRoles();
    currentPlayerIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        string playerName;
        cout << "Enter the name of Player " << i + 1 << ": ";
        cin >> playerName;
        players[i].setName(playerName);
    }
}


void GameManager::initializePlayers(int numberOfPlayers) {
    players.clear();

    for (int i = 0; i < numberOfPlayers; i++) {
        string playerName = "Player " + to_string(i + 1);
        Player player(playerName); 
        players.push_back(player);
    }
}



void GameManager::distributeRoles() {



    Role* shogun = new Shogun("Shogun", 1);
    Role* samurai = new Samurai("Samurai", 2);
    Role* ronin = new Ronin("Ronin", 3);
    Role* ninja1 = new Ninja("Ninja", 4);
    Role* ninja2 = new Ninja("Ninja", 5);
    Role* ninja3 = new Ninja("Ninja", 6);
    Role* ninja4 = new Ninja("Ninja", 7);

    if (numberOfPlayers == 4) {
        players[0].setRole(shogun);
        players[1].setRole(samurai);
        players[2].setRole(ninja1);
        players[3].setRole(ninja2);
    }
    else if (numberOfPlayers == 5) {
        players[0].setRole(shogun);
        players[1].setRole(samurai);
        players[2].setRole(ronin);
        players[3].setRole(ninja1);
        players[4].setRole(ninja2);
    }
    else if (numberOfPlayers == 6) {
        players[0].setRole(shogun);
        players[1].setRole(samurai);
        players[2].setRole(ronin);
        players[3].setRole(ninja1);
        players[4].setRole(ninja2);
        players[5].setRole(ninja3);
    }
    else if (numberOfPlayers == 7) {
        players[0].setRole(shogun);
        players[1].setRole(samurai);
        players[2].setRole(samurai);
        players[3].setRole(ronin);
        players[4].setRole(ninja1);
        players[5].setRole(ninja2);
        players[6].setRole(ninja3);
    }

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
}

void GameManager::distributeCards() {
    cards.clear(); 

    for (int i = 0; i < numberOfPlayers; i++) {
        Card* attackCard = new AttackCard("nodachi", i + 1, 3, 3);
        Card* actionCard = new ActionCard("action", i + 1, "effect");
        Card* permanentCard = new PermanentCard("permanent", i + 1, "description");

        cards.push_back(attackCard);
        cards.push_back(actionCard);
        cards.push_back(permanentCard);
    }

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(cards.begin(), cards.end(), default_random_engine(seed));
}



void GameManager::startGame() {
    cout << "Game started!" << endl;
    distributeCards();
    int shogunIndex = -1;

    for (int i = 0; i < players.size(); i++) {
        if (players[i].getRole() != nullptr && players[i].getRole()->getName() == "Shogun") {
            shogunIndex = i;
            break;
        }
    }
    if (shogunIndex != -1) {
        currentPlayerIndex = shogunIndex;
    }

    while (true) {
        Player& currentPlayer = players[currentPlayerIndex];
        cout << "It's " << currentPlayer.getName() << "'s turn." << endl;
        int choice;

        cout << "[1] Play card" << endl;
        cout << "[2] Pass" << endl;
        cout << "[3] View my role" << endl;
        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Invalid choice. Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        if (choice == 1) {
            int cardNumber;
            cin >> cardNumber;

            if (cardNumber >= 0 && cardNumber < cards.size()) {
                cards[cardNumber]->display();
                cout << "Enter the number of the card: ";
            }
            else {
                cout << "Card number invalid" << endl;
            }
        }
        else if (choice == 2) {
            cout << "You have passed your turn" << endl;
        }
        else if (choice == 3) {
            Role* playerRole = currentPlayer.getRole();
            if (playerRole != nullptr) {
                cout << "Your role is: " << playerRole->getName() << endl;
            }
            else {
                cout << "ERROR 0x0001 no roles, please restart the game" << endl;
            }
        }

        if (choice != 3) {
            currentPlayerIndex = (currentPlayerIndex + 1) % numberOfPlayers;
        }
    }
}





int GameManager::getNumberOfPlayers() const {
    return this->numberOfPlayers;
}

void GameManager::playNextTurn() {
    // Implémentez la logique pour le tour suivant
}

GameManager::~GameManager() {
    // Libérer la mémoire des cartes
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}
