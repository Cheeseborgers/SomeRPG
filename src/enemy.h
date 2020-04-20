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

#ifndef SOMERPG_ENEMY_H
#define SOMERPG_ENEMY_H

#include <cstdlib>
#include <string>

class Enemy {

private:
    int level;
    int hp;
    int hpMax;
    int damageMin;
    int damageMax;
    int defence;
    int accuracy;
    float dropChance;

public:
    // Constructor / Deconstructor
    explicit Enemy(int level = 0);
    virtual ~Enemy();

    // Methods
    [[nodiscard]] inline bool isAlive() const { return this->hp > 0;};
    [[nodiscard]] std::string getAsString() const;
    void takeDamage(int damage);

    [[nodiscard]] inline int getLevel() const { return this->level; };
    [[nodiscard]] inline int getDamage() const { return static_cast<int>(rand() % this->damageMax - this->damageMin);};
    [[nodiscard]] inline int getExp() const  { return this->level * 100; };
    [[nodiscard]] inline int getHp() const { return this->hp; };
    [[nodiscard]] inline int getHpMax() const { return this->hpMax; };
    [[nodiscard]] inline int getDefence() const { return this->defence; };
    [[nodiscard]] inline int getAccuracy() const { return this->accuracy;};
};

// NS END

#endif //SOMERPG_ENEMY_H
