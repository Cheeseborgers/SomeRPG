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

#include "enemy.h"


// Constructor ---------------------------------------------------------------------------------------------------------
Enemy::Enemy(int level)
{
    this->level = level;
    this->hpMax = this->level * 10;
    this->hp = hpMax;

    this->damageMin = this->level * 4;
    this->damageMax = this->level * 5;
    this->dropChance = static_cast<float>(std::rand() % 100);
    this->accuracy = static_cast<int>(std::rand() % 100);

    this->defence = {};
    this->accuracy = {};
}
// Deconstructor---------------------------------------------------------------------------------------------------------------------
Enemy::~Enemy() = default;
// Methods -------------------------------------------------------------------------------------------------------------
std::string Enemy::getAsString() const
{
  return "Level: " + std::to_string(this->level) + "\n" +
         "HP: " + std::to_string(this->hp) + " / " +
         std::to_string(this->hpMax) + "\n" +
         "Damage: " + std::to_string(this->damageMin) + " - " +
         std::to_string(this->damageMax) + "\n" +
         "Defence: " + std::to_string(this->defence) + "\n" +
         "Accuracy: " + std::to_string(this->accuracy) + "\n" +
         "Drop Chance: " + std::to_string(this->dropChance);
}

void Enemy::takeDamage(const int damage)
{
    this->hp -= damage;

    if (this->hp <= 0)
    {
        this->hp = 0; // ensure hp is zero and not a negative number for display
    }
}

