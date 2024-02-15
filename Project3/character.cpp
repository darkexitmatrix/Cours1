#include "Character.h"

Character::Character(const std::string& name, int health, const std::string& ability)
    : name(name), healthPoints(health), ability(ability) {}

std::string Character::getCharacterName() const {
    return name;
}

int Character::getCharacterHealth() const {
    return healthPoints;
}

std::string Character::getCharacterAbility() const {
    return ability;
}

Benkei::Benkei() : Character("Benkei", 5, "Les autres joueurs vous attaquent avec une difficult� augment�e de 1.") {}

Chiyome::Chiyome() : Character("Chiyome", 4, "Seules les armes peuvent vous faire perdre des points de vie.") {}

Ginchiyo::Ginchiyo() : Character("Ginchiyo", 4, "Vous r�duisez de 1 les d�g�ts des armes (minimum 1).") {}

Goemon::Goemon() : Character("Goemon", 5, "Vous pouvez jouer 1 arme suppl�mentaire par tour.") {}

Hanzo::Hanzo() : Character("Hanzo", 4, "Vous pouvez jouer vos cartes d�arme comme des (� moins que �a ne soit votre derni�re carte en main).") {}

Hideyoshi::Hideyoshi() : Character("Hideyoshi", 4, "Durant votre phase de pioche, piochez 1 carte suppl�mentaire.") {}

Ieyasu::Ieyasu() : Character("Ieyasu", 5, "Durant votre phase de pioche, vous pouvez prendre la carte du dessus de la d�fausse au lieu de piocher votre premi�re carte.") {}

Kojiro::Kojiro() : Character("Kojiro", 5, "Vos armes peuvent attaquer n�importe quel autre joueur sans tenir compte de la difficult�.") {}

Musashi::Musashi() : Character("Musashi", 5, "Vos armes causent 1 d�g�t suppl�mentaire.") {}

Nobunaga::Nobunaga() : Character("Nobunaga", 5, "Durant votre tour, vous pouvez perdre 1 point de vie (sauf votre dernier) pour piocher 1 carte.") {}

Tomoe::Tomoe() : Character("Tomoe", 5, "Chaque fois qu�une de vos armes blesse un joueur, piochez 1 carte.") {}

Ushiwaka::Ushiwaka() : Character("Ushiwaka", 4, "Chaque fois que vous perdez 1 point de vie � cause d�une arme, piochez 1 carte.") {}
