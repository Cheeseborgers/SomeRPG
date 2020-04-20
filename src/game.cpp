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

#include "game.h"


// Constructor ---------------------------------------------------------------------------------------------------------
Game::Game()
{
    this->playing = true;
    this->choice = {};
    this->activeCharacter = {};
    this->characters = {};
    this->filename = "characters.txt";
}
// Methods -------------------------------------------------------------------------------------------------------------
void Game::mainMenu()
{
    std::cout << "\nEnter to continue...\n";
    std::cin.get();
    std::system("clear");

    if (this->characters[activeCharacter].getExp() >
        this->characters[activeCharacter].getExpNxt())
    {
        std::cout << "Level up available!\n";
    }

    std::cout << "=== MAIN MENU ===\n\n";

    std::cout << "= Active Character: " <<
        this->characters[activeCharacter].getName() <<
        " (hp: " << std::to_string(this->characters[activeCharacter].getHp()) <<
        "/" << std::to_string(this->characters[activeCharacter].getHpMax()) <<
        ") Nr: " <<
        this->activeCharacter+1 << "/" << this->characters.size() <<
        " =\n\n";

    std::cout << "(0): Quit\n";
    std::cout << "(1): Travel\n";
    std::cout << "(2): Shop\n";
    std::cout << "(3): Level up\n";
    std::cout << "(4): Rest\n";
    std::cout << "(5): Character sheet\n";
    std::cout << "(6): Create new character\n";
    std::cout << "(7): Select character\n";
    std::cout << "(8): Save characters\n";
    std::cout << "(9): Load characters\n";


    std::cout << "\n\nChoice: ";
    std::cin >> this->choice;
    std::system("clear");

    while (std::cin.fail())
    {
        std::system("clear");
        std::cout << "Faulty input!\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');

        std::cout << "\nChoice: ";
        std::cin >> this->choice;
    }

    std::cin.ignore(100, '\n');
    std::cout << "\n";

    switch (this->choice) {
        case 0: // Quit
            this->playing = false;
            std::cout << "Thank you for playing SomeRPG. <3";
            break;
        case 1: // Travel
            this->travel();
            break;
        case 3: // Level up
            this->levelUpCharacter();
            break;
        case 5: // Char sheet
            //std::system("clear");
            this->characters[this->activeCharacter].printStats();
            break;
        case 6: // New char
            this->createNewCharacter();
            this->saveCharacters();
            break;
        case 7: // Select chars
            this->selectCharacter();
            break;
        case 8: // Save chars
            this->saveCharacters();
            break;
        case 9: // Load chars
            this->loadCharacters();
            break;
        default:
            break;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Game::initGame()
{
    this->createNewCharacter();
}
//----------------------------------------------------------------------------------------------------------------------
void Game::createNewCharacter()
{
    std::string name{};
    std::cout << "Enter a name for your character: ";
    getline(std::cin, name);

    for (auto & character : this->characters)
    {
        while (name == character.getName())
        {
            std::cout << "Error! Character already exists!\n";
            std::cout << "Enter a name for your character: ";
            getline(std::cin, name);
        }
    }

    this->characters.emplace_back();
    this->activeCharacter = static_cast<int>(this->characters.size() - 1);
    this->characters[this->activeCharacter].initialise(name);
}
//----------------------------------------------------------------------------------------------------------------------
void Game::levelUpCharacter()
{
    this->characters[activeCharacter].levelUp();

    if (this->characters[activeCharacter].getStatPoints() > 0)
    {
        std::cout << "You have Stat points to allocate!\n\n";

        std::cout << "Stat to upgrade?\n\n";
        std::cout << "(0): Strength\n";
        std::cout << "(1): Vitality\n";
        std::cout << "(2): Dexterity\n";
        std::cout << "(3): Intelligence \n\n";

        std::cout << "Choice: ";

        std::cin >> this->choice;

        while (std::cin.fail() || this->choice > 3)
        {
            std::system("clear");
            std::cout << "Faulty input!\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << "Stat to upgrade?\n";
            std::cout << "(0): Strength\n";
            std::cout << "(1): Vitality\n";
            std::cout << "(2): Dexterity\n";
            std::cout << "(3): Intelligence \n\n";

            std::cout << "Choice: ";

            std::cin >> this->choice;

        }

        std::cin.ignore(100, '\n');
        std::cout << "\n";

        switch (this->choice)
        {
            case 0: // Strength
                this->characters[activeCharacter].addToStat(0, 1);
                break;
            case 1: // Vitality
                this->characters[activeCharacter].addToStat(1, 1);
                break;
            case 2: // Dexterity
                this->characters[activeCharacter].addToStat(2, 1);
                break;
            case 3: // Intelligence
                this->characters[activeCharacter].addToStat(3, 1);
                break;
            default:
                break;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Game::saveCharacters()
{
    std::ofstream outFile(this->filename);

    if (outFile.is_open())
    {
        for (auto & character : this->characters)
        {
            outFile << character.getAsStr() << "\n";
        }
    }

    outFile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void Game::loadCharacters()
{
    std::ifstream inFile(this->filename);

    this->characters.clear();

    std::string name{};
    int distanceTravelled{};
    int gold{};
    int level{};
    int exp{};
    int strength{};
    int vitality{};
    int dexterity{};
    int intelligence{};
    int hp{};
    int stamina{};
    int statPoints{};
    int skillPoints{};

    std::string line{};
    std::stringstream ss;

    if (inFile.is_open())
    {
        while (std::getline(inFile, line))
        {
            ss.str(line);
            ss >> name;
            ss >> distanceTravelled;
            ss >> gold;
            ss >> level;
            ss >> exp;
            ss >> strength;
            ss >> vitality;
            ss >> dexterity;
            ss >> intelligence;
            ss >> hp;
            ss >> stamina;
            ss >> statPoints;
            ss >> skillPoints;

            Character temp(name, distanceTravelled, gold, level, exp, strength,
                      vitality, dexterity, intelligence, hp, stamina,
                      statPoints, skillPoints);

            this->characters.emplace_back(Character(temp));

            std::cout << "Character: " << name << " was loaded successfully.\n";
            ss.clear();
        }
    }

    inFile.close();

    if (this->characters.empty())
    {
        throw "ERROR: CHARACTERS NOT LOADED OR EMPTY FILE!";
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::selectCharacter()
{
    std::cout << "Select character:\n\n";

    for (size_t i = 0; i < this->characters.size(); ++i)
    {
        std::cout << i << ": " <<
            this->characters[i].getName() << " (lvl:" <<
            this->characters[i].getLevel() << ")\n";
    }

    std::cout << "\n";

    std::cout << "Choice: ";

    std::cin >> this->choice;

    while (std::cin.fail() || this->choice >= this->characters.size() || choice < 0)
    {
        std::cout << "Faulty input!\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');

        std::cout << "Select character:\n\n";
        std::cin >> this->choice;
    }

    std::cin.ignore(100, '\n');
    std::cout << "\n";

    this->activeCharacter = this->choice;

    std::cout << this->characters[activeCharacter].getName() << " is selected.\n\n";
}
//----------------------------------------------------------------------------------------------------------------------
void Game::travel()
{
    this->characters[activeCharacter].travel();

    Event ev;
    ev.generateEvent(this->characters[activeCharacter], this->enemies);
}
//----------------------------------------------------------------------------------------------------------------------

