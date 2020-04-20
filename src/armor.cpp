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

#include "armor.h"

// Constructor
Armor::Armor(int type, int defence, const std::string &name,
             int level, int sellValue, int buyValue, int rarity)
        : Item(name, level, sellValue, buyValue, rarity) {
    this->type = type;
    this->defence = defence;
}
//----------------------------------------------------------------------------------------------------------------------
// Destructor
Armor::~Armor() = default;
//----------------------------------------------------------------------------------------------------------------------
// Methods
std::string Armor::getAsString() const
{
    return std::to_string(this->type) + " " +
           std::to_string(this->defence);
}
//----------------------------------------------------------------------------------------------------------------------
Armor *Armor::clone() const {
    return new Armor(*this);
}
//----------------------------------------------------------------------------------------------------------------------


