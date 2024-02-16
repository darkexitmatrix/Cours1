/*#include "AttackLogic.h"
#include "player.h"
#include "character.h"
#include <cmath>

int AttackLogic::calculateAttackDifficulty(Player* attacker, Player* target) {
    if (!attacker || !target) {
        return -1; 
    }

    int attackerIndex = -1;
    int targetIndex = -1;
    std::vector<Player*> players = attacker->getCards(); // Correction ici
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i] == attacker) {
            attackerIndex = static_cast<int>(i);
        }
        else if (players[i] == target) {
            targetIndex = static_cast<int>(i);
        }
    }

    if (attackerIndex == -1 || targetIndex == -1) {
        return -1;
    }

    int clockwiseDistance = (targetIndex - attackerIndex + players.size()) % players.size();

    int anticlockwiseDistance = (attackerIndex - targetIndex + players.size()) % players.size();

    int difficulty = std::min(clockwiseDistance, anticlockwiseDistance);

    return difficulty;
}

void AttackLogic::executeAttack(Player* attacker, Player* target, AttackCard* card) {
    if (!attacker || !target || !card) {
        return; 
    }

    int difficulty = calculateAttackDifficulty(attacker, target);

    if (difficulty <= card->getRange()) {
        // Exécuter l'attaque (implémentation spécifique à votre jeu)
        // Par exemple, réduire les points de vie de la cible
        int damage = card->getDamage();
        target->removeHealth(damage);
    }
}
*/