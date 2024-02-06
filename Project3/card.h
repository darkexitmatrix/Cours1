#pragma once

#include <string>
using namespace std;

class Card {
public:
    Card(const string& name, int number);

    string getName() const;
    int getNumber() const;

    virtual void display() const = 0;

private:
    string name;
    int number;
};

class AttackCard : public Card {
public:
    AttackCard(const string& name, int number, int damage, int range);

    void display() const override;

    int getDamage() const;
    int getRange() const;

private:
    int damage;
    int range;
};

class ActionCard : public Card {
public:
    ActionCard(const string& name, int number, const string& effect);

    void display() const override;

    string getEffect() const;

private:
    string effect;
};

class PermanentCard : public Card {
public:
    PermanentCard(const string& name, int number, const string& description);

    void display() const override;

    string getDescription() const;

private:
    string description;
};
