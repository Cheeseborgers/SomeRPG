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

#ifndef SOMERPG_PUZZLE_H
#define SOMERPG_PUZZLE_H

#include "functions.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Puzzle {

private:
    std::string question;
    std::vector<std::string> answers;
    int correctAnswer;

public:

    // Constructor
    explicit Puzzle(const std::string& filename);
    virtual ~Puzzle();

    // Methods
    std::string getAsString();

    [[nodiscard]] inline const int& getCorrectAnswer() const { return this->correctAnswer; } ;

};

#endif //SOMERPG_PUZZLE_H
