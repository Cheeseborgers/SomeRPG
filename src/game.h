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

#ifndef SOMERPG_GAME_H
#define SOMERPG_GAME_H

#include "event.h"

#include <sstream>



class Game {

private:
    bool playing;
    int choice;

    // Character related
    int activeCharacter;
    std::vector<Character> characters;
    std::string filename;

    // Enemy related
    DynArr<Enemy> enemies;


public:

    // Constructor
    Game();

    // Operators

    // Methods
    void initGame();
    void mainMenu();

    void createNewCharacter();
    void levelUpCharacter();
    void saveCharacters();
    void loadCharacters();
    void selectCharacter();

    void travel();

    // Accessors
    [[nodiscard]] inline bool getPlaying() const { return this->playing;}

};

// NS END

#endif //SOMERPG_GAME_H
