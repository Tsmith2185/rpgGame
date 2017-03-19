// Wiz.h (Wizard header file.)

#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>

class Wizard
{
public:
	// Methods
	void fight();
	void talk();
	void castSpell();

private:
	// Data members
	std::string mName;
	int mHitPoints;
	int mMagicPoints;
	int mArmor;
};

#endif // WIZARD_H