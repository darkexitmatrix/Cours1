#include "gameManager.h"
#include "card.h"
#include "role.h"
#include "player.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

GameManager::GameManager() {}

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
    distributeCharacters();
    currentPlayerIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        string playerName;
        cout << "Enter the name of Player " << i + 1 << ": ";
        cin >> playerName;
        players[i].setPlayerName(playerName);
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
    vector<Role*> allRoles = { new Shogun("Shogun", 1), new Samurai("Samurai", 2), new Ronin("Ronin", 3), new Ninja("Ninja", 4) };

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(allRoles.begin(), allRoles.end(), default_random_engine(seed));

    cout << "Chargement des roles \n\n\n";
    for (int i = 0; i < numberOfPlayers; ++i) {
        players[i].setPlayerRole(allRoles[i]);
    }
}

void GameManager::distributeCharacters() {
    std::vector<Character*> allCharacters = { new Benkei(), new Chiyome(), new Ginchiyo(), new Goemon(), new Hanzo(), new Hideyoshi(), new Ieyasu(), new Kojiro(), new Musashi(), new Nobunaga(), new Tomoe(), new Ushiwaka() };

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(allCharacters.begin(), allCharacters.end(), std::default_random_engine(seed));

    std::cout << "Distribution character :\n";
    for (size_t i = 0; i < players.size(); ++i) {
        if (!allCharacters.empty()) {
            players[i].setPlayerCharacter(allCharacters.front());
            std::cout << "Player " << i + 1 << " : " << allCharacters.front()->getCharacterName() << std::endl;
            allCharacters.erase(allCharacters.begin());
        }
    }
}

void GameManager::distributeCards() {
    cards.clear();

    int numActionCards[] = { 4, 4, 4, 6, 3, 15, 4, 3 };
    string actionCardNames[] = { "cri_de_guerre", "daimyo", "diversion", "geisha", "meditation", "parade", "ceremonie_du_the", "jujitsu" };
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < numActionCards[i]; ++j) {
            cards.push_back(new ActionCard(actionCardNames[i], "effect"));
        }
    }

    string weaponNames[] = { "nodachi", "nagayari", "tanegashima", "daikyu", "katana", "kanabo", "wakizashi", "naginata", "bo", "kusarigama", "shuriken", "bokken", "kiseru" };
    int numWeaponCards[] = { 1, 1, 1, 1, 1, 1, 1, 2, 5, 4, 3, 6, 5 };
    int weaponDamages[] = { 3, 2, 1, 3, 3, 2, 3, 1, 1, 2, 1, 1, 2 };
    int weaponRanges[] = { 3, 4, 5, 5, 2, 3, 1, 4, 2, 2, 2, 1, 1 };
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < numWeaponCards[i]; ++j) {
            cards.push_back(new AttackCard(weaponNames[i], weaponDamages[i], weaponRanges[i]));
        }
    }

    string permanentCardNames[] = { "attaque_rapide", "code_du_bushido", "armure", "concentration" };
    int numPermanentCards[] = { 3, 2, 4, 6 };
    string permanentCardDescriptions[] = { "", "", "", "" };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < numPermanentCards[i]; ++j) {
            cards.push_back(new PermanentCard(permanentCardNames[i], permanentCardDescriptions[i]));
        }
    }

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(cards.begin(), cards.end(), default_random_engine(seed));

    int shogunCards = 4;
    int secondAndThirdPlayersCards = 5;
    int fourthAndFifthPlayersCards = numberOfPlayers >= 5 ? 6 : 0;
    int sixthAndSeventhPlayersCards = numberOfPlayers >= 7 ? 7 : 0;

    vector<int> cardsToDistribute;
    cardsToDistribute.push_back(shogunCards);
    cardsToDistribute.push_back(secondAndThirdPlayersCards);
    cardsToDistribute.push_back(secondAndThirdPlayersCards);
    cardsToDistribute.push_back(fourthAndFifthPlayersCards);
    cardsToDistribute.push_back(fourthAndFifthPlayersCards);
    cardsToDistribute.push_back(sixthAndSeventhPlayersCards);
    cardsToDistribute.push_back(sixthAndSeventhPlayersCards);

    int currentPlayerIndex = 0;
    for (int i = 0; i < cardsToDistribute.size(); ++i) {
        for (int j = 0; j < cardsToDistribute[i]; ++j) {
            if (currentPlayerIndex < numberOfPlayers) {
                players[currentPlayerIndex].addCard(cards.front());
                cards.erase(cards.begin());
                currentPlayerIndex = (currentPlayerIndex + 1) % numberOfPlayers;
            }
        }
    }
}

void GameManager::displayHealthPoints() const {
    cout << "\nHealth Points:" << endl;
    for (const Player& player : players) {
        cout << player.getPlayerName() << ": ";
        if (player.getPlayerRole() != nullptr && player.getPlayerCharacter() != nullptr) {
            cout << player.getPlayerHealth() << " HP (Character: " << player.getPlayerCharacter()->getCharacterName() << ")" << endl;
        }
        else {
            cout << "Unknown (No Role or Character assigned)" << endl;
        }
    }
    cout << endl;
}

void GameManager::startGame() {
    system("cls");
    distributeCards();
    int shogunIndex = -1;

    for (int i = 0; i < players.size(); i++) {
        if (players[i].getPlayerRole() != nullptr && players[i].getPlayerRole()->getName() == "Shogun") {
            shogunIndex = i;
            break;
        }
    }

    if (shogunIndex != -1) {
        currentPlayerIndex = shogunIndex;
    }
    else {
        shuffle(players.begin(), players.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
        currentPlayerIndex = 0;
        players[currentPlayerIndex].setPlayerRole(new Shogun("Shogun", 1));
    }

    while (true) {
        Player& currentPlayer = players[currentPlayerIndex];
        cout << "\nIt's " << currentPlayer.getPlayerName() << "'s turn." << endl;
        int choice;
        displayHealthPoints();
        cout << "[1] Play card" << endl;
        cout << "[2] Pass" << endl;
        cout << "[3] View my role & character" << endl;
        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Invalid choice. Please enter 1, 2, or 3: ";
            system("clear");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        if (choice == 1) {
            system("cls");
            cout << "Player's Cards:\n";
            cout << "------------------------------------------------------------\n";
            cout << "  Card Number  |  Card Type       |  Card Value            \n";
            cout << "------------------------------------------------------------\n";

            // Retrieve the player's cards
            vector<Card*> playerCards = currentPlayer.getCards();
            // Display each card's details in a table format
            for (int i = 1; i < playerCards.size(); ++i) {
                cout << "      " << i << "       |     " << playerCards[i]->getType();

                // Display additional details based on card type
                if (playerCards[i]->getType() == "Attack") {
                    cout << "        |  Damage: " << dynamic_cast<Card*>(playerCards[i])->getValue();
                }
                else if (playerCards[i]->getType() == "Action") {
                    cout << "        |  Effect: " << dynamic_cast<Card*>(playerCards[i])->getValue();
                }
                else if (playerCards[i]->getType() == "Permanent") {
                    cout << "     |  Description: " << dynamic_cast<Card*>(playerCards[i])->getValue();
                }

                cout << "\n";
            }

            cout << "--------------------------------------------------\n";

            cout << "Enter the number of the card you want to display: ";
            int cardNumber;
            cin >> cardNumber;

            // Check if the card number is valid
            if (cardNumber >= 0 && cardNumber < playerCards.size()) {
                playerCards[cardNumber]->display();
            }
            else {
                cout << "Invalid card number. Please try again.\n";
            }
        }
        else if (choice == 3) {
            system("cls");
            Role* playerRole = currentPlayer.getPlayerRole();
            Character* playerCharacter = currentPlayer.getPlayerCharacter();
            if (playerRole != nullptr && playerCharacter != nullptr) {
                cout << "Your role is: " << playerRole->getName() << endl;
                cout << "Your character is: " << playerCharacter->getCharacterName() << endl;
            }
            else {
                cout << "ERROR 0x0001 no role or character, please restart the game" << endl;
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
    // Implement logic for playing the next turn
}

GameManager::~GameManager() {
    // Clean up memory used by cards
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}
