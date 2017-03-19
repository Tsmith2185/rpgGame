// Main.cpp (The file with main.)

#include <iostream>
#include <string>
#include "Wiz.h"
using namespace std;

int main()
{
	Wizard wiz0; // Declare a variable called wiz0 of the type Wizard.
	wiz0.fight();
	wiz0.talk();

	wiz0.mArmor = 10;

	cout << "Players name = " << wiz0.mName << endl;

	// Test to see if player has enough magic points to cast a spell
	if (wiz0.mMagicPoints > 4)
		wiz0.castSpell();
	else
		cout << "Not enough magic points!" << endl;
}