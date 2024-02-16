#include "card.h"
#include <iostream>

AttackCard::AttackCard(const std::string& name, int damage, int range)
    : name(name), damage(damage), range(range) {}

void AttackCard::display() const {
    std::cout << "Attack Card: " << name << " - Damage: " << damage << " - Range: " << range << std::endl;
}

std::string AttackCard::getValue() const {
    return std::to_string(damage);
}

std::string AttackCard::getType() const {
    return "Attack";
}

ActionCard::ActionCard(const std::string& name, const std::string& effect)
    : name(name), effect(effect) {}

void ActionCard::display() const {
    std::cout << "Action Card: " << name << " - Effect: " << effect << std::endl;
}

std::string ActionCard::getValue() const {
    return effect;
}

std::string ActionCard::getType() const {
    return "Action";
}

PermanentCard::PermanentCard(const std::string& name, const std::string& description)
    : name(name), description(description) {}

void PermanentCard::display() const {
    std::cout << "Permanent Card: " << name << " - Description: " << description << std::endl;
}

std::string PermanentCard::getValue() const {
    return description;
}

std::string PermanentCard::getType() const {
    return "Permanent";
}