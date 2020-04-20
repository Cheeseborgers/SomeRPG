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

#include "puzzle.h"


// Constructor ---------------------------------------------------------------------------------------------------------
Puzzle::Puzzle(const std::string &filename)
{
      // SAVE/LOAD FORMAT
      /*
      * Question
      * nrOfAns
      * answers
      * correctAns
      */

      this->correctAnswer = {};

      std::ifstream inFile(filename);

      int nrOfAns = {};
      std::string answer = {};
      int correctAns = {};

      if (inFile.is_open())
      {
            std::getline(inFile, this->question);
            inFile >> nrOfAns;
            inFile.ignore();

            for (size_t i = 0; i < nrOfAns; i++)
            {
                  std::getline(inFile, answer);
                  this->answers.emplace_back(answer);
            }

        inFile >> correctAns;
        this->correctAnswer = correctAns;
        inFile.ignore();

      } else
            throw("Could not open puzzle!");

      inFile.close();
}
// Deconstructor -------------------------------------------------------------------------------------------------------
Puzzle::~Puzzle() = default;
// Methods -------------------------------------------------------------------------------------------------------------
std::string Puzzle::getAsString()
{
    std::string string = {};

    for (size_t i = 0; i < this->answers.size(); ++i)
    {
        string += std::to_string(i + 1) + ": " + this->answers[i] + "\n";
    }

    /*
     * Debug:
     *  return this->question + "\n\n" + string + "\n" +
     *  std::to_string(this->correctAnswer) + "\n";
     */

    return this->question + "\n\n" + string + "\n";
}
//----------------------------------------------------------------------------------------------------------------------