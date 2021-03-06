// Player.cpp

#include <iostream>
#include "Player.h"
#include "Random.h"
#include <string>
#include <fstream>
using namespace std;

Player::Player()
{
	mName          =  "Default";
	mClassName     =  "Default";
	mClassNumber   =  0;
	mAccuracy      =  0;
	mHitPoints     =  0;
	mMaxHitPoints  =  0;
	mMagicPoints = 0;
	mMaxMagicPoints = 0;
	mExpPoints     =  0;
	mNextLevelExp  =  0;
	mGold = 0;
	mLevel         =  0;
	mArmor         =  0;
	mWeapon.mName  = "Default Weapon Name";
	mWeapon.mDamageRange.mLow   =  0;
	mWeapon.mDamageRange.mHigh  =  0;
	mSpell.mName                =  "Default Spell Name";
	mSpell.mDamageRange.mLow    =  0;
	mSpell.mDamageRange.mHigh   =  0;
	mSpell.mSpellEffect         =  0;
	mSpell.mMagicNeeded         =  0;
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmor()
{
	return mArmor;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Player::createClass()
{
	cout << endl; 
	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "==========================" << endl;

	// Input Character's Name.
	cout << "Enter your character's name: ";
	cin >> mName;
	
	cout << endl;

	// Character Selection.
	cout << "Please select a character class number..." << endl;
	cout << "1) Figher 2) Wizard 3) Cleric 4) Thief: ";

	int characterNum = 1;
	cin >> characterNum;

	switch (characterNum)
	{
	case 1: // Fighter
		mClassName      =  "Fighter";
		mClassNumber    =  1;
		mAccuracy       =  10;
		mHitPoints      =  20;
		mMaxHitPoints   =  20;
		mMagicPoints    =  0;
		mMaxMagicPoints =  0;
		mExpPoints      =  0;
		mGold           =  0;
		mNextLevelExp   =  1000;
		mLevel          =  1;
		mArmor          =  4;
		mWeapon.mName   =  "Long Sword";
		mWeapon.mDamageRange.mLow   =  1;
		mWeapon.mDamageRange.mHigh  =  8;
		mSpell.mName                =  "No Spell";
		mSpell.mDamageRange.mLow    =  0;
		mSpell.mDamageRange.mHigh   =  0;
		mSpell.mSpellEffect         =  0;
		mSpell.mMagicNeeded         =  0;
		break;

	case 2: // Wizard
		mClassName      = "Wizard";
		mClassNumber    =  2;
		mAccuracy       =  5;
		mHitPoints      =  10;
		mMaxHitPoints   =  10;
		mMagicPoints    =  20;
		mMaxMagicPoints =  20;
		mExpPoints      =  0;
		mGold           =  0;
		mNextLevelExp   =  1000;
		mLevel          =  1;
		mArmor          =  1;
		mWeapon.mName   =  "Staff";
		mWeapon.mDamageRange.mLow   =  1;
		mWeapon.mDamageRange.mHigh  =  4;
		mSpell.mName                =  "Ice Bolt";
		mSpell.mDamageRange.mLow    =  3;
		mSpell.mDamageRange.mHigh   =  9;
		mSpell.mSpellEffect         =  1;
		mSpell.mMagicNeeded         =  3;
		break;
	case 3: // Cleric
		mClassName      =  "Cleric";
		mClassNumber    =  3;
		mAccuracy       =  8;
		mHitPoints      =  15;
		mMaxHitPoints   =  15;
		mMagicPoints    =  10;
		mMaxMagicPoints =  10;
		mExpPoints      =  0;
		mGold           =  0;
		mNextLevelExp   =  1000;
		mLevel          =  1;
		mArmor          =  3;
		mWeapon.mName   =  "Flail";
		mWeapon.mDamageRange.mLow   =  1;
		mWeapon.mDamageRange.mHigh  =  6;
		mSpell.mName                =  "No Spell";
		mSpell.mDamageRange.mLow    =  0;
		mSpell.mDamageRange.mHigh   =  0;
		mSpell.mSpellEffect         =  0;
		mSpell.mMagicNeeded         =  0;
		break;
	case 4: // Thief
		mClassName      =  "Thief";
		mClassNumber    =  4;
		mAccuracy       =  7;
		mHitPoints      =  12;
		mMaxHitPoints   =  12;
		mMagicPoints    =  0;
		mMaxMagicPoints =  0;
		mExpPoints      =  0;
		mGold           =  0;
		mNextLevelExp   =  1000;
		mLevel          =  1;
		mArmor          =  2;
		mWeapon.mName   =  "Short Sword";
		mWeapon.mDamageRange.mLow   =  1;
		mWeapon.mDamageRange.mHigh  =  6;
		mSpell.mName                =  "No Spell";
		mSpell.mDamageRange.mLow    =  0;
		mSpell.mDamageRange.mHigh   =  0;
		mSpell.mSpellEffect         =  0;
		mSpell.mMagicNeeded         =  0;
		break;
	}
}

bool Player::attack(Monster& monster)
{
	// Combat is turned based: display an options menu.  You can,
	// of course, extend this to let the player use an item,
	// cast a spell, and so on.
	int selection = 1;
	cout << "1) Attack, 2) Use Spell, 3) Use Item, 4) Run: ";
	cin >> selection;
	cout << endl;

	switch (selection)
	{
	case 1: // Attack
		cout << "You attack an " << monster.getName()
			<< " with a " << mWeapon.mName << endl;

		if (Random(0, 20) < mAccuracy)
		{
			int damage = Random(mWeapon.mDamageRange);
			
			int totalDamage = damage - monster.getArmor();

			if (totalDamage <= 0)
			{
				cout << "Your attack failed to penetrate "
					<< "the armor!" << endl;
			}
			else
			{
				int noSpell = 0;
				cout << "You attack for " << totalDamage
					<< " damage!" << endl;

				// Subtrack from monster's hitpoints
				monster.takeDamage(totalDamage, noSpell);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		break;

		case 2: // Spell
			if (mMagicPoints >= mSpell.mMagicNeeded)
			{
				mMagicPoints -= mSpell.mMagicNeeded;

				cout << "You use " << mSpell.mName
					<< " on " << monster.getName() << endl;

				if (Random(0, 20) < mAccuracy)
				{
					int damage = Random(mSpell.mDamageRange);
					int spellDuration = 0;
					int spellEffect = 0;
					int totalDamage = damage - monster.getArmor();

					if (totalDamage <= 0)
					{
						cout << "Your spell had no effect!" << endl;
					}
					else
					{
						cout << "You use " << mSpell.mName << " for "
							<< totalDamage << " damage!" << endl;

						if (Random(1, 4))
						{
							spellEffect = 1;
						}

						// Subtrack from monster's hitpoints
						monster.takeDamage(totalDamage, spellEffect);
					}
				}
				else
				{
					cout << "Your spell misses!" << endl;
				}
				cout << endl;
				break;
			}
			else
			{
				cout << "Your fingertips sparked but nothing happened!" << endl << endl;
				break;
			}
	
	case 3: // Item (to be added)
		// 25% chance of being able to run.
					break;
	
	case 4: // Run Away
		// 25% chance of being able to run.
		int escape = Random(1, 4);

		if (escape == 1)
		{
			cout << "You run away!" << endl;
			return true; //<-- Return out of the function.
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
}
	return false;
}

void Player::levelUp()
{
	if (mExpPoints >= mNextLevelExp)
	{
		cout << "You gained a level!" << endl;

		int doGetMagic = 0;

		// Increment level.
		mLevel++;

		// Set experience points required for next level.
		mNextLevelExp = mLevel * mLevel * 1000;

		// Level up stats based on class.
		switch (mClassNumber) 
		{
		case 1: // Fighter
			// Increase stats randomly.
			mAccuracy += Random(1, 3);
			mMaxHitPoints += Random(5, 10);
			mArmor += Random(3, 4);
				// 10% Chance of gaining magic ability.
			doGetMagic = Random(1, 10);
			if (doGetMagic == 1)
			{
				mMaxMagicPoints += Random(1, 2);
			}
			break;
		case 2: // Wizard
				// Increase stats randomly.
			mAccuracy += Random(1, 3);
			mMaxHitPoints += Random(1, 5);
			mArmor += Random(1, 2);
			mMaxMagicPoints += Random(5, 10);
			break;
		case 3: // Cleric
				// Increase stats randomly.
			mAccuracy += Random(2, 4);
			mMaxHitPoints += Random(2, 6);
			mArmor += Random(1, 3);
			// 25% Chance of gaining magic ability.
			doGetMagic = Random(1, 4);
			if (doGetMagic == 1)
			{
				mMaxMagicPoints += Random(1, 2);
			}
			break;
		case 4: // Thief
				// Increase stats randomly.
			mAccuracy += Random(2, 4);
			mMaxHitPoints += Random(4, 8);
			mArmor += Random(2, 3);
			// 20% Chance of gaining magic ability.
			doGetMagic = Random(1, 5);
			if (doGetMagic == 1)
			{
				mMaxMagicPoints += Random(1, 2);
			}
			break;
		}

		// Give player full hitpoints and magic whehn they level up.
		mHitPoints = mMaxHitPoints;
		mMagicPoints = mMaxMagicPoints;

		
	}
}

void Player::rest()
{
	cout << "Resting..." << endl;

	mHitPoints = mMaxHitPoints;
	mMagicPoints = mMaxMagicPoints;
}

void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;

	cout << "Name             =  " << mName << endl;
	cout << "Class            =  " << mClassName << endl;
	cout << "Accuracy         =  " << mAccuracy << endl;
	cout << "Hit points       =  " << mHitPoints << endl;
	cout << "Max Hit points   =  " << mMaxHitPoints << endl;
	cout << "Magic Points     =  " << mMagicPoints << endl;
	cout << "Max Magic Points =  " << mMaxMagicPoints << endl;
	cout << "XP               =  " << mExpPoints << endl;
	cout << "XP for Next Lvl  =  " << mNextLevelExp << endl;
	cout << "Gold             =  " << mGold << endl;
	cout << "Level            =  " << mLevel << endl;
	cout << "Armor            =  " << mArmor << endl;
	cout << "Weapon Name      =  " << mWeapon.mName << endl;
	cout << "Weapon Damage    =  " << mWeapon.mDamageRange.mLow << "-" <<
		mWeapon.mDamageRange.mHigh << endl;

	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

void Player::victory(int xp)
{
	int gold = 0;
    
	gold = (Random(100, 2000));

	cout << "You won the battle!" << endl;
	cout << "You win " << xp
		<< " experience points and " << gold 
		<< " Gold!" << endl << endl;

	mExpPoints += xp;
	
	mGold += gold;
}

void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "================================" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
	cout << mName << "'s magic points = " << mMagicPoints<< endl;
}

void Player::save(ofstream& outFile)
{
	outFile << "ClassName= "      << mClassName      << endl;
	outFile << "Name= "           << mName           << endl;
	outFile << "Accuracy= "       << mAccuracy       << endl;
	outFile << "HitPoints= "      << mHitPoints      << endl;
	outFile << "MaxHitPoints= "   << mMaxHitPoints   << endl;
	outFile << "MagicPoints= "    << mMagicPoints    << endl;
	outFile << "MaxMagicPoints= " << mMaxMagicPoints << endl;
	outFile << "ExpPoints= "      << mExpPoints      << endl;
	outFile << "Gold= "           << mGold           << endl;
	outFile << "NextLevelExp= "   << mNextLevelExp   << endl;
	outFile << "Level= "          << mLevel          << endl;
	outFile << "Armor= "          << mArmor          << endl;
	outFile << "WeaponName= "     << mWeapon.mName   << endl;
	outFile << "DamageLow= "      << mWeapon.mDamageRange.mLow  << endl;
	outFile << "damageHigh "      << mWeapon.mDamageRange.mHigh << endl;
	outFile << "SpellName= " << mSpell.mName << endl;
	outFile << "DamageLow= " << mSpell.mDamageRange.mLow << endl;
	outFile << "DamageHigh " << mSpell.mDamageRange.mHigh << endl;
}

void Player::load(ifstream& inFile)
{
	string garbage;
	inFile >> garbage >> mClassName;
	inFile >> garbage >> mName;
	inFile >> garbage >> mAccuracy;
	inFile >> garbage >> mHitPoints;
	inFile >> garbage >> mMaxHitPoints;
	inFile >> garbage >> mMagicPoints;
	inFile >> garbage >> mMaxMagicPoints;
	inFile >> garbage >> mExpPoints;
	inFile >> garbage >> mNextLevelExp;
	inFile >> garbage >> mLevel;
	inFile >> garbage >> mArmor;
	inFile >> garbage >> mWeapon.mName;
	inFile >> garbage >> mWeapon.mDamageRange.mLow;
	inFile >> garbage >> mWeapon.mDamageRange.mHigh;
	inFile >> garbage >> mSpell.mName;
	inFile >> garbage >> mSpell.mDamageRange.mLow;
	inFile >> garbage >> mSpell.mDamageRange.mHigh;
}
