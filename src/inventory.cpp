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

#include "inventory.h"


// Constructor --------------------------------------------------------------------------------------------------------
Inventory::Inventory()
{
    this->cap = 5;
    this->nrOfItems = {};
    this->itemArray = new Item*[this->cap];
    this->initialise(this->cap);
}
// Deconstructor -------------------------------------------------------------------------------------------------------
Inventory::~Inventory()
{
    for (size_t i = 0; i < this->nrOfItems; ++i)
    {
        delete this->itemArray[i];
    }
    delete[] this->itemArray;
}
// Copy Constructor ----------------------------------------------------------------------------------------------------
Inventory::Inventory(const Inventory &obj)
{
    this->cap = obj.cap;
    this->nrOfItems = obj.nrOfItems;
    this->itemArray = new Item*[this->cap];

    for (size_t i = 0; i < this->nrOfItems; ++i)
    {
        this->itemArray[i] = obj.itemArray[i]->clone();
    }

    this->initialise(this->nrOfItems);
}
// Methods ------------------------------------------------------------------------------------------------------------
void Inventory::expand()
{
    /* Doubles the inventory capacity, creates a temp inventory array
     * copying the items from the current inventory item array.
     * We the delete all items from the current item array and the array
     * itself. Finally we can now point the inventory item_arr to the
     * expanded temp array
     * */
    this->cap *= 2;

    Item ** temp_array = new Item*[this->cap];

    for (size_t i = 0; i < this->nrOfItems; ++i)
    {
        temp_array[i] = this->itemArray[i];
    }

    delete[] this->itemArray;

    this->itemArray = temp_array;

    this->initialise(this->nrOfItems);
}

void Inventory::initialise(const int from)
{
    for (size_t i = from; i < this->cap; ++i)
    {
        this->itemArray[i] = nullptr;
    }
}

[[maybe_unused]] void Inventory::addItem(const Item &item)
{
    if (this->nrOfItems >= this->cap)
    {
        this->expand();
    }

    this->itemArray[this->nrOfItems++] = item.clone();

}

void Inventory::removeItem(int index)
{

}

Item &Inventory::operator[](const int index)
{
    if (index < 0 || index >= this->nrOfItems)
    {
        throw ("Bad index!"); // NOLINT(hicpp-exception-baseclass)
    }
    return *this->itemArray[index];
}
