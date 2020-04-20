//
//      Created by Goodecheeseburgers on 16/04/2020.
//      SomeRPG. A C++ console role playing game.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/SomeRPG
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

#ifndef SOMERPG_DYNARR_H
#define SOMERPG_DYNARR_H

template<typename T>
class DynArr
{
private:
    unsigned cap{};
    unsigned initialCap{};
    unsigned nrOfEl{};
    T* *arr;

    void expand();
    void initialize(unsigned from);

public:
    explicit DynArr(unsigned size = 5); // Constructor
    DynArr(const DynArr& obj); // Copy Constructor
    ~DynArr(); // Destructor

    T& operator[] (unsigned index); // Index operator
    void operator= (const DynArr& obj); // Assignment operator

    [[nodiscard]] unsigned maxCap() const;
    [[nodiscard]] unsigned size() const;
    void push(T element);
    void remove(unsigned index, bool ordered = false);
};
// Constructor ---------------------------------------------------------------------------------------------------------
template<typename T>
DynArr<T>::DynArr(unsigned size)
{
    this->initialCap = size;
    this->cap = size;
    this->nrOfEl = 0;

    this->arr = new T*[this->cap];

    this->initialize(0);
}
// Copy Constructor ----------------------------------------------------------------------------------------------------
template<typename T>
DynArr<T>::DynArr(const DynArr& obj)
{
    this->initialCap = obj.initialCap;
    this->cap = obj.cap;
    this->nrOfEl = obj.nrOfEl;

    this->arr = new T*[this->cap];

    for (size_t i = 0; i < this->nrOfEl; ++i)
    {
        // Dereference here or we just get the pointer address. as obj.arr is a an array of pointers.
        this->arr[i] = new T(*obj.arr[i]);
    }

    this->initialize(0);
}
// Destructor ---------------------------------------------------------------------------------------------------------
template<typename T>
DynArr<T>::~DynArr()
{
    for (size_t i = 0; i < this->nrOfEl; ++i)
    {
        delete this->arr[i];  // Delete all the cheeses
    }
    delete[] this->arr;  // Delete the hands
}
// Index Operator ------------------------------------------------------------------------------------------------------
template<typename T>
T& DynArr<T>::operator[] (const unsigned index)
{
    if (index < 0 || index >= this->nrOfEl)
        throw "ERROR: OUT OF BOUNDS INDEXING OPERATOR.";

    return *this->arr[index];
}
// Assignment operator -------------------------------------------------------------------------------------------------
template<typename T>
void DynArr<T>::operator= (const DynArr& obj)
{
    for (size_t i = 0; i < this->nrOfEl; ++i)
    {
        delete this->arr[i];
    }
    delete[] this->arr;

    this->initialCap = obj.initialCap;
    this->cap = obj.cap;
    this->nrOfEl = obj.nrOfEl;

    this->arr = new T*[this->cap];

    for (size_t i = 0; i < this->nrOfEl; ++i)
    {
        this->arr[i] = new T(*obj.arr[i]);
    }

    this->initialize(0);
}
//----------------------------------------------------------------------------------------------------------------------
template<typename T>
void DynArr<T>::expand()
{
    this->cap *= 2;

    T* *tempArr = new T*[this->cap];

    for (size_t i = 0; i < this->nrOfEl; ++i)
    {
        tempArr[i] = this->arr[i];
    }

    delete[] this->arr;

    this->arr = tempArr;

    this->initialize(this->nrOfEl);
}
//----------------------------------------------------------------------------------------------------------------------
template<typename T>
void DynArr<T>::initialize(unsigned from)
{
    for (size_t i = from; i < this->cap; ++i)
    {
        this->arr[i] = nullptr;
    }
}
//----------------------------------------------------------------------------------------------------------------------
template<typename T>
unsigned DynArr<T>::maxCap() const
{
    return this->cap;
}
//----------------------------------------------------------------------------------------------------------------------
template<typename T>
unsigned DynArr<T>::size() const
{
    return this->nrOfEl;
}
//----------------------------------------------------------------------------------------------------------------------
template<typename T>
void DynArr<T>::push(T element) {
    if (this->nrOfEl >= this->cap)
        this->expand();

    this->arr[this->nrOfEl++] = new T(element);
}
//----------------------------------------------------------------------------------------------------------------------
template<typename T>
void DynArr<T>::remove(const unsigned index, bool ordered)
{
    if (index < 0 || index >= this->nrOfEl)
        throw "ERROR: OUT OF BOUNDS REMOVE.";

    if (ordered)
    {
        delete this->arr[index]; // Delete the data at index

        for (size_t i = 0; i < this->nrOfEl-1; ++i)
        {
            this->arr[i] = this->arr[i + 1];
        }

        this->arr[--this->nrOfEl] = nullptr;
    }
    else
    {
        delete this->arr[index]; // Delete the data at index

        this->arr[index] = this->arr[this->nrOfEl - 1]; // Point to the last element

        this->arr[--this->nrOfEl] = nullptr;
    }
}


#endif //SOMERPG_DYNARR_H
