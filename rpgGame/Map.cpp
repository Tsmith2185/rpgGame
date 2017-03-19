// Map.cpp

#include "Map.h"
#include <iostream>
#include "Random.h"
using namespace std;

Map::Map()
{
	// Player starts at origin (0, 0)
	mPlayerXPos = 0;
	mPlayerYPos = 0;

}

int Map::getPlayerXPos()
{
	return mPlayerXPos;
}

int Map::getPlayerYPos()
{
	return mPlayerYPos;
}

void Map : movePlayer()
{
	int selection = 1;
	cout << "1) North, 2) East, 3) South, 4) West: ";
	cin >> selection;

	// Update coordinates based on selection.
	switch (selection)
	{
	case 1: // North
		mPlayerYPos++;
		break;
	case 2: // East
		mPlayerXPos++;
		break;
	case 3: // South
		mPlayerYPos--;
		break;
	default: // West
		mPlayerXPos--;
		break;
	}
	cout << endl;
}