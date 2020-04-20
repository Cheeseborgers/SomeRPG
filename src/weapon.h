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

#ifndef SOMERPG_WEAPON_H
#define SOMERPG_WEAPON_H

#include "item.h"

class Weapon :
        public Item {

private:
    int damageMin;
    int damageMax;

public:

    // Constructor
    explicit Weapon(int damageMin = 0, int damageMax = 0,
                    const std::string &name = "NONE", int level = 0,
                    int sellValue = 0, int buyValue = 0, int rarity = 0);

    ~Weapon() override;

    // Pure virtual
    [[nodiscard]] Weapon * clone() const override;

    // Methods
    std::string getAsString() const;

};


#endif //SOMERPG_WEAPON_H
