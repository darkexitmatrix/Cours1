#include "Card.h"
#include <iostream>

Card::Card(const string& name, int number)
    : name(name), number(number) {}

string Card::getName() const {
    return name;
}

int Card::getNumber() const {
    return number;
}

AttackCard::AttackCard(const string& name, int number, int damage, int range)
    : Card(name, number), damage(damage), range(range) {}

void AttackCard::display() const {
    cout << "----------------------" << endl;
    cout << "*                     *" << endl;
    cout << "*   " << getName() << " *" << endl;
    for (int i = getName().length(); i < 12; i++) {
        cout << "?";
    }
    cout << "*                     *" << endl;
    cout << "*                     *" << endl;
    cout << "*  Number: " << getNumber();
    for (int i = 0; i < 5; i++) {
        cout << " ";
    }
    cout << "*" << endl;
    cout << "*  Damage: " << damage;
    for (int i = 0; i < 5; i++) {
        cout << " ";
    }
    cout << "*" << endl;
    cout << "*   Range: " << range;
    for (int i = 0; i < 5; i++) {
        cout << " ";
    }
    cout << "*" << endl;
    cout << "*                   *" << endl;
    cout << "----------------------" << endl;
}

int AttackCard::getDamage() const {
    return damage;
}

int AttackCard::getRange() const {
    return range;
}

ActionCard::ActionCard(const string& name, int number, const string& effect)
    : Card(name, number), effect(effect) {}

void ActionCard::display() const {
    cout << "----------------------" << endl;
    cout << "*                   *" << endl;
    cout << "*   " << getName() << " *" << endl;
    for (int i = getName().length(); i < 12; i++) {
        cout << "?";
    }
    cout << "*                    *" << endl;
    cout << "*                   *" << endl;
    cout << "*  Number: " << getNumber();
    for (int i = 0; i < 5; i++) {
        cout << " ";
    }
    cout << "*" << endl;
    cout << "*  Effect: " << effect;
    for (int i = effect.length(); i < 7; i++) {
        cout << "?";
    }
    cout << "*" << endl;
    cout << "*                   *" << endl;
    cout << "----------------------" << endl;
}

string ActionCard::getEffect() const {
    return effect;
}

PermanentCard::PermanentCard(const string& name, int number, const string& description)
    : Card(name, number), description(description) {}

void PermanentCard::display() const {
    cout << "----------------------" << endl;
    cout << "*                   *" << endl;
    cout << "*   " << getName() << " *" << endl;
    for (int i = getName().length(); i < 12; i++) {
        cout << "?";
    }
    cout << "*                    *" << endl;
    cout << "*                   *" << endl;
    cout << "*  Number: " << getNumber();
    for (int i = 0; i < 5; i++) {
        cout << " ";
    }
    cout << "*" << endl;
    cout << "*  Description: " << description;
    for (int i = description.length(); i < 1; i++) {
        cout << "?";
    }
    cout << "*" << endl;
    cout << "*                   *" << endl;
    cout << "----------------------" << endl;
}

string PermanentCard::getDescription() const {
    return description;
}
