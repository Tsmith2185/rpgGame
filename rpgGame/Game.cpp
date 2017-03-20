// Main.cpp (The file with main.)

#include "Map.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	srand( time(0) );

	Map gameMap;

	int startSelect = 0;
	int store = 0;
	int checkStoreEncounter();
	Player mainPlayer;

	std::cout << "Welcome to RPG v.1.5" << endl
		<< "1) Start a new game." << endl
		<< "2) Load a saved game." << endl
		<< "Please choose an option: ";
	std::cin >> startSelect;

	if (startSelect == 2)
	{
		ifstream inFile("player.txt");
		mainPlayer.load(inFile);
	}
	else
		mainPlayer.createClass();


	// Begin Adventure.
	bool done = false;
	while (!done)
	{
		// Each loop cycle we output the player position and
		// a selection menu.
		gameMap.printPlayerPos();

		int selection = 1;
		std::cout << "1) Move, 2) Rest, 3) View Stats, 4) Save, 5) Quit: ";
		std::cin >> selection;

		ofstream outFile("player.txt");
		
		Monster* monster = 0;
		switch (selection)
		{
		case 1: 
			// Move the player.
			gameMap.movePlayer();

			// Check for a random encounter.  This function
			// returns a null pointer if no monsters are
			// encountered.
			monster = gameMap.checkRandomEncounter();

			// 'monster' not null, run combat simulation.
			if (monster != 0)
			{
				// Loop until a 'break' statement.
				while (true)
				{
					// Display hitpoints
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					std::cout << endl;

					// Player's turn to attack first.
					bool runAway = mainPlayer.attack(*monster);

					if (runAway)
						break;

					if (monster->isDead())
					{
						mainPlayer.victory(monster->getXPReward());
						mainPlayer.levelUp();
						break;
					}

					monster->attack(mainPlayer);

					if (mainPlayer.isDead())
					{
						mainPlayer.gameover();
						done = true;
						break;
					}
				}

				// The pointer to a monster returned from
				// checkRandomEncounter was allocated with
				// 'new', so we must delete it to avoid
				// memory leaks.
				delete monster;
				monster = 0;
			}
			/*
			checkStoreEncounter();
			{
				int roll = Random(0, 20);

				int store = 0;

				if (roll <= 15)
				{
					// No encounter, return a null pointer.
					return 1;
				}
				else
					return 0;
			}
			// 'store' not null, run store simulation.
			if (store != 0)
			{
				// Loop until a 'break' statement.
				while (true)
				{
					int select = 0;
					cout << "This is the store Place holder" << endl
						<< "To shop press 1, to leave press 2" << endl
						<< "They all exit lol, gotcha!!!" << endl << endl;
					break;
				}
				// The pointer to a monster returned from
				// checkRandomEncounter was allocated with
				// 'new', so we must delete it to avoid
				// memory leaks.
				store = 0;

			}
			break;
			*/
		case 2:
			mainPlayer.rest();
			break;
		case 3:
			mainPlayer.viewStats();
			break;
		case 4:
				mainPlayer.save(outFile);
			outFile.close();
			break;
		case 5:
			int saveselect = 0;
			std::cout << "Do you want to save? 1) Yes, 2) No: ";
			std::cin >> saveselect;
			if (saveselect = 1)
			{
				mainPlayer.save(outFile);
				outFile.close();
			}
			done = true;
			break;
		}// End Switch Statement
	}// End While Statement
}// End main function