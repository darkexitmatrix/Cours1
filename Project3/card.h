#pragma once

#include <string>

class Card {
public:
    virtual void display() const = 0;
    virtual ~Card() {}
};

class AttackCard : public Card {
public:
    AttackCard(const std::string& name, int damage, int range);
    void display() const override;

private:
    std::string name;
    int damage;
    int range;
};

class ActionCard : public Card {
public:
    ActionCard(const std::string& name, const std::string& effect);
    void display() const override;

private:
    std::string name;
    std::string effect;
};

class PermanentCard : public Card {
public:
    PermanentCard(const std::string& name, const std::string& description);
    void display() const override;

private:
    std::string name;
    std::string description;
};





