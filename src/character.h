//
//      Created by Goodecheeseburgers on 15/04/2020.
//      SomeRPG. A C++ console role playing game.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/somerpg
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef SOMERPG_CHARACTER_H
#define SOMERPG_CHARACTER_H

#include "inventory.h"
#include "enemy.h"

class Character {

public:

    // Constructors
    Character();
    Character(const std::string &name, int distanceTravelled, int gold, int level, int exp, int strength, int vitality,
              int dexterity, int intelligence, int hp, int stamina, int statPoints, int skillPoints);

// Methods
    void initialise(const std::string& name);
    void printStats() const;
    [[nodiscard]] std::string getAsStr() const;
    void levelUp();
    void updateStats();
    void addToStat(int stat, int value);

    // Accessors
    [[nodiscard]] inline const std::string& getName() const { return this->playerName; }

    [[nodiscard]] inline const int& getDistTraveled() const { return this->distanceTraveled; }

    [[nodiscard]] inline const int& getLevel() const { return this->level; }
    [[nodiscard]] inline const int& getExp() const { return this->exp; }
    [[nodiscard]] inline const int& getExpNxt() const { return this->expNxt; }
    [[nodiscard]] inline const int& getStatPoints() const { return this->statPoints; }
    [[nodiscard]] inline const int& getHp() const { return this->hp; }
    [[nodiscard]] inline const int& getHpMax() const { return this->hpMax; }
    [[nodiscard]] inline bool isAlive() const { return this->hp > 0;};
    [[nodiscard]] inline const int& getStamina() const { return this->stamina; }
    [[nodiscard]] inline const int& getDamageMin() const { return this->damageMin; }
    [[nodiscard]] inline const int& getDamageMax() const { return this->damageMax; }
    [[nodiscard]] inline int getAttackDamage() const
    {
        return static_cast<int>(rand() % this->damageMax + this->damageMin);
    };
    [[nodiscard]] inline const int& getDefence() const { return this->defence; }
    [[nodiscard]] inline const int& getAccuracy() const { return this->accuracy; }
    [[nodiscard]] inline const int& getLuck() const { return this->luck; }
    [[nodiscard]] inline const int& getGold() const { return this->gold; }

    // Modifiers
    inline void setDistTraveled(const int& distance) { this->distanceTraveled = distance; }
    inline void travel() { this->distanceTraveled++; }
    inline void gainExp(const int& expGain) { this->exp += expGain; };
    void takeDamage(int damage);

private:
    std::string playerName;

    // World
    int distanceTraveled;

    // Inventory
    Inventory inventory;
    Weapon weapon;
    Armor armorHead;
    Armor armorChest;
    Armor armorArms;
    Armor armorLegs;

    int gold;

    // Statistics
    int level;
    int exp;
    int expNxt;

    int strength;
    int vitality;
    int dexterity;
    int intelligence;

    int hp;
    int hpMax;
    int stamina;
    int staminaMax;
    int damageMin;
    int damageMax;
    int defence;
    int accuracy;
    int luck;

    int statPoints;
    int skillPoints;
};

#endif //SOMERPG_CHARACTER_H
