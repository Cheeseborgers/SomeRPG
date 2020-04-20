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
#include "event.h"


// Constructor ---------------------------------------------------------------------------------------------------------
Event::Event()
{
    this->nrOfEvents = 2;
}
// Deconstructor -------------------------------------------------------------------------------------------------------
Event::~Event() = default;
// Methods -------------------------------------------------------------------------------------------------------------
void Event::generateEvent(Character &character, const DynArr<Enemy>& enemies) const
{
    int i = static_cast<int>(rand() % this->nrOfEvents);

    switch (i)
    {
        case 0:
            enemyEncounter(character, enemies);
            break;
        case 1:
            puzzleEncounter(character);
            break;
        case 2:
            break;
        default:
            break;
    }
}
// Other Events---------------------------------------------------------------------------------------------------------
void Event::enemyEncounter(Character &character, DynArr<Enemy> enemies)
{
    bool playerTurn{false};
    int choice{};

    // Coin toss for turn
    int coinToss = rand() % 2 + 1;
    playerTurn = coinToss == 1; // Simplified if/else

    // End conditions
    bool escape{false};
    bool playerDefeated{false};
    bool enemiesDefeated{false};

    // Enemies
    int nrOfEnemies = rand() % 5 + 1;

    for (size_t i = 0; i < nrOfEnemies; ++i)
    {
        enemies.push(Enemy(character.getLevel()));
    }

    // Battle variables
    int damage{};
    int expGain{};
    int playerAccuracy{};
    int playerDefence{};
    int playerTotal{};
    int enemyAccuracy{};
    int enemyDefence{};
    int enemyTotal{};
    int combatTotal{};
    int combatRoll{};

    while (!escape && !playerDefeated && !enemiesDefeated)
    {
        if (playerTurn && !playerDefeated)
        {
            //system("clear");

            std::cout << "= BATTLE MENU =" << "\n\n";

            std::cout << "0: Escape" << "\n";
            std::cout << "1: Attack" << "\n";
            std::cout << "4: Defend" << "\n";
            std::cout << "3: Use Item" << "\n\n";

            std::cout << "Choice: ";

            std::cin >> choice;

            while (std::cin.fail() || choice > 3 || choice < 0)
            {
                std::cout << "Faulty input!\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');

                //system("clear");

                std::cout << "= BATTLE MENU =" << "\n\n";

                std::cout << "0: Escape" << "\n";
                std::cout << "1: Attack" << "\n";
                std::cout << "4: Defend" << "\n";
                std::cout << "3: Use Item" << "\n\n";

                std::cout << "Choice: ";

                std::cin >> choice;
            }

            std::cin.ignore(100, '\n');
            std::cout << "\n";


            // Move / Actions
            switch (choice)
            {
            case 0: // Escape
                escape = true;
                //break;
            case 1: // Attack

                std::cout << "Select enemy: " << "\n\n";

                // Create enemy selection menu
                for (size_t i = 0; i < enemies.size(); ++i)
                {
                    std::cout << "(" << i << "): "
                        << "Lvl: " << enemies[i].getLevel() << " | "
                        << "HP:" << enemies[i].getHp() << "/"
                        << enemies[i].getHpMax() << "\n";
                }

                std::cout << "\n";

                std::cout << "Choice: ";

                std::cin >> choice;

                while (std::cin.fail() || choice >= enemies.size() || choice < 0)
                {
                    std::cout << "Faulty input!\n";
                    std::cin.clear();
                    std::cin.ignore(100, '\n');

                    //system("clear");

                    std::cout << "Select enemy: " << "\n\n";

                    // Create enemy selection menu
                    for (size_t i = 0; i < enemies.size(); ++i)
                    {
                        std::cout << "(" << i << "):"
                                  << "Lvl: " << enemies[i].getLevel() << " | "
                                  << "HP:" << enemies[i].getHp() << "/"
                                  << enemies[i].getHpMax() << "\n";
                    }

                    std::cout << "\n";

                    std::cout << "Choice: ";

                    std::cin >> choice;
                }

                std::cin.ignore(100, '\n');
                std::cout << "\n";

                // Combat roll
                combatRoll = rand() % 100 + 1;

                combatTotal = enemies[choice].getDefence() + character.getAccuracy();
                enemyTotal = combatTotal / enemies[choice].getDefence();
                playerTotal = combatTotal / character.getAccuracy();

                if (combatRoll > 50) // Hit
                {
                    std::cout << "HIT!\n\n";

                    damage = character.getAttackDamage();
                    enemies[choice].takeDamage(damage);

                    std::cout << "You dealt " << std::to_string(damage)
                              << "! to " << choice << "\n";

                    if (!enemies[choice].isAlive())
                    {
                        expGain = enemies[choice].getExp();
                        character.gainExp(expGain);

                        std::cout << "Enemy defeated!\n";
                        std::cout << "Exp gained: " << expGain << "!\n\n";

                        enemies.remove(choice);
                    }

                } else { // Miss
                    std::cout << "Missed!\n";
                }

                break;
            case 2: // Defend
                break;
            case 3: // Item
                break;
            default:
                break;
            }

            // Move

            // End player turn
            playerTurn = false;

        } else if (!playerTurn && !escape && !enemiesDefeated)
        {

            // Enemy attack
            for (size_t i = 0; i < enemies.size(); ++i)
            {

            }

            // End enemies turn
            playerTurn = true;



        }


        // Conditions

        if (!character.isAlive())
        {
            playerDefeated = true;
        }
        else if (enemies.size() <= 0)
        {
            enemiesDefeated = true;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Event::puzzleEncounter(Character &character)
{
    bool completed{false};
    int userAns{};
    int chances{3};

    int expGain = static_cast<int>(chances * character.getLevel() * (rand()%10 + 1));

    Puzzle puzzle("puzzles/1.txt");

    while (!completed && chances > 0)
    {
        std::cout << "Chances left: " << chances << "\n\n";
        chances--;
        std::cout << puzzle.getAsString();

        std::cout << "\nYour answer: ";
        std::cin >> userAns;

        while (std::cin.fail())
        {
            std::cout << "Faulty input!\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << "\nYour answer: ";
            std::cin >> userAns;
        }

        std::cin.ignore(100, '\n');
        std::cout << "\n";

        if ((puzzle.getCorrectAnswer() + 1) == userAns)
        {
            completed = true;
            character.gainExp(expGain);
            std::cout << "You gained: " << expGain << "Exp!\n\n";
        }
        else
        {
            std::cout << "Wrong! try again\n\n";
        }
    }

    if (completed)
    {
        std::cout << "Congratz, you succeeded!\n\n";
    }
    else
    {
        std::cout << "You failed bruh!\n\n";
    }
}
//----------------------------------------------------------------------------------------------------------------------

