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

#ifndef SOMERPG_INVENTORY_H
#define SOMERPG_INVENTORY_H

#include "weapon.h"
#include "armor.h"

class Inventory {

public:
    // Constructor
    Inventory();
    ~Inventory();
    Inventory(const Inventory &obj);
    [[nodiscard]] inline int size() const { return this->nrOfItems;};
    Item& operator[](int index);

    // Methods
    void addItem(const Item& item);
    void removeItem(int index);
    inline void debugPrint() const
    {
        for (size_t i = 0; i < this->nrOfItems; ++i)
        {
            std::cout << this->itemArray[i]->debugPrint() << "\n";
        }
    }

private:
    int cap;
    int nrOfItems;
    Item **itemArray;

    // Methods
    void expand();
    void initialise(int from = 0);


};

#endif //SOMERPG_INVENTORY_H
