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

#ifndef SOMERPG_ITEM_H
#define SOMERPG_ITEM_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cmath>
#include <memory>
#include <vector>
#include <fstream>

class Item {

public:
    // Constructor
    explicit Item(const std::string& name = "NONE", int level = 0, int sellVal = 0, int buyVal = 0, int rarity = 0);
    virtual ~Item();

    // Methods
    [[nodiscard]] inline std::string debugPrint() const { return this->name; };
    [[nodiscard]] virtual Item* clone() const = 0;

    // Accessors
    [[nodiscard]] inline const std::string& getName() const { return this->name; };
    [[nodiscard]] inline const int& getLevel() const { return this->level; };
    [[nodiscard]] inline const int& getSellValue() const { return this->sellValue; };
    [[nodiscard]] inline const int& getBuyValue() const { return this->buyValue; };
    [[nodiscard]] inline const int& getRarity() const { return this->rarity; };

    // Modifiers

private:
    std::string name;
    int level;
    int sellValue;
    int buyValue;
    int rarity;
};

// NS END

#endif //SOMERPG_ITEM_H
