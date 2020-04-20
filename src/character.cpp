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

#include "character.h"

// Constructor
Character::Character()
{
    this->playerName = {};

    // World
    this->distanceTraveled = {};

    // Inventory
    this->gold = {};

    // Statistics
    this->level = {};
    this->exp = {};
    this->expNxt = {};

    this->strength = {};
    this->vitality = {};
    this->dexterity = {};
    this->intelligence = {};

    this->hp = {};
    this->hpMax = {};
    this->stamina = {};
    this->staminaMax = {};
    this->damageMin = {};
    this->damageMax = {};
    this->accuracy = {};
    this->defence = {};
    this->luck = {};

    this->statPoints = {};
    this->skillPoints = {};
}
Character::Character(const std::string &name, int distanceTravelled, int gold,
                     int level, int exp, int strength, int vitality,
                     int dexterity, int intelligence, int hp, int stamina,
                     int statPoints, int skillPoints){

    this->playerName = name;

    // World
    this->distanceTraveled = distanceTravelled;

    // Inventory
    this->gold = gold;

    // Statistics
    this->level = level;
    this->exp = exp;
    this->expNxt = {};

    this->strength = strength;
    this->vitality = vitality;
    this->dexterity = dexterity;
    this->intelligence = intelligence;

    this->hp = hp;
    this->hpMax = {};
    this->stamina = stamina;
    this->staminaMax = {};
    this->damageMin = {};
    this->damageMax = {};
    this->accuracy = {};
    this->defence = {};
    this->luck = {};

    this->statPoints = statPoints;
    this->skillPoints = skillPoints;

    this->updateStats();
}
// Methods -------------------------------------------------------------------------------------------------------------
void Character::initialise(const std::string& name)
{
    this->playerName = name;

    // World
    this->distanceTraveled = 0;

    // Inventory
    this->gold = 100;

    // Statistics
    this->level = 1;
    this->exp = 0;
    this->expNxt = static_cast<int>(
            (50 / 3 * // NOLINT(bugprone-integer-division)
             ((pow(this->level, 3) -
               6 * pow(this->level, 2)) +
              17 * this->level - 12)) + 100);

    this->strength = 5;
    this->vitality = 5;
    this->dexterity = 5;
    this->intelligence = 5;

    this->hpMax = this->vitality * 2 + this->strength / 2;
    this->hp = hpMax;

    this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
    this->stamina = this->staminaMax;

    this->damageMin = this->strength;
    this->damageMax = this->strength + 2;

    this->defence = this->dexterity + (this->intelligence / 2);
    this->accuracy = this->dexterity / 2;
    this->luck = this->intelligence;

    this->statPoints = 0;
    this->skillPoints = 0;
}
//----------------------------------------------------------------------------------------------------------------------
void Character::printStats() const {

    std::cout << "= Character sheet =\n\n";
    
    std::cout << "= Name: " << this->playerName << " =\n";
    std::cout << "= Level: " << this->level  << " =\n";
    std::cout << "= Exp: " << this->exp  << " =\n";
    std::cout << "= Exp to next level: " << this->expNxt << " =\n";
    std::cout << "= Gold: " << this->gold << " =\n";

    std::cout << std::setw(30) << std::setfill('=') << "\n";

    std::cout << "= Strength: " << this->strength  << " =\n";
    std::cout << "= Vitality: " << this->vitality  << " =\n";
    std::cout << "= Dexterity: " << this->dexterity  << " =\n";
    std::cout << "= Intelligence: " << this->intelligence  << " =\n\n";

    std::cout << "= Statpoints: " << this->statPoints << "\n";

    std::cout << std::setw(30) << std::setfill('=') << "\n";

    std::cout << "= HP: " << this->hp << " / " << this->hpMax << " =\n";
    std::cout << "= Stamina: " << this->stamina << " / " << this->staminaMax << " =\n";
    std::cout << "= Damage: " << this->damageMin << " <-> " << this->damageMax << " =\n";
    std::cout << "= Defence: " << this->defence  << " =\n";
    std::cout << "= Accuracy: " << this->accuracy  << " =\n";
    std::cout << "= Luck: " << this->luck  << " =\n\n";
}
//----------------------------------------------------------------------------------------------------------------------
std::string Character::getAsStr() const
{
    return this->playerName + " "
           + std::to_string(this->distanceTraveled) + " "
           + std::to_string(this->gold) + " "
           + std::to_string(this->level) + " "
           + std::to_string(this->exp) + " "
           + std::to_string(this->strength) + " "
           + std::to_string(this->vitality) + " "
           + std::to_string(this->dexterity) + " "
           + std::to_string(this->intelligence) + " "
           + std::to_string(this->hp) + " "
           + std::to_string(this->stamina) + " "
           + std::to_string(this->statPoints) + " "
           + std::to_string(this->skillPoints);
}
//----------------------------------------------------------------------------------------------------------------------
void Character::updateStats()
{
    this->expNxt = static_cast<int>(
            (50 / 3 * // NOLINT(bugprone-integer-division)
             ((pow(this->level, 3) -
               6 * pow(this->level, 2)) +
              17 * this->level - 12)) + 100);

    this->hpMax = this->vitality * 2 + this->strength / 2;
    this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
    this->damageMin = this->strength;
    this->damageMax = this->strength + 2;
    this->defence = this->dexterity + (this->intelligence / 2);
    this->accuracy = this->dexterity / 2;
    this->luck = this->intelligence;
}

// Modifiers -----------------------------------------------------------------------------------------------------------
void Character::levelUp()
{
    if (this->exp >= this->expNxt) {
        this->exp -= this->expNxt;
        this->level++;
        this->expNxt = static_cast<int>(
            (50 / 3 * // NOLINT(bugprone-integer-division)
             ((pow(this->level, 3) -
               6 * pow(this->level, 2)) +
              17 * this->level - 12)) + 100);

        this->statPoints++;
        this->skillPoints++;

        this->updateStats();

        std::cout << "You are now level: " << this->level << "!\n\n";
    } else {
        std::cout << "Not enough exp.\n\n";
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Character::addToStat(const int stat, const int value)
{
    if (this->statPoints < value)
    {
        std::cout << "ERROR: NOT ENOUGH STAT POINTS!";
    } else {

        switch (stat)
        {
            case 0:
                this->strength += value;
                std::cout << "Strength increased by " << std::to_string(value) << " points";
                break;
            case 1:
                this->vitality += value;
                std::cout << "Vitality increased by " << std::to_string(value) << " points";
                break;
            case 2:
                this->dexterity += value;
                std::cout << "Dexterity increased by " << std::to_string(value) << " points";
                break;
            case 3:
                this->intelligence += value;
                std::cout << "Intelligence increased by " << std::to_string(value) << " points";
                break;
            default:
                std::cout << "ERROR: NO SUCH STAT!";
                break;
        }

        this->statPoints -= value;
    }

    std::cout << "\n\n";
}
//----------------------------------------------------------------------------------------------------------------------
void Character::takeDamage(const int damage)
{
    this->hp -= damage;

    if (this->hp <= 0)
    {
        this->hp = 0; // ensure hp is zero and not a negative number for display
    }
}
