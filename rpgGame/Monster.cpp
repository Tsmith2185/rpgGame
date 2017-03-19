// Monster.cpp

#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Random.h"
#include "Spell.h"
using namespace std;

Monster::Monster(const std::string& name, int hp, int acc,
		int xpReward, int armor, const std::string& weaponName,
		int lowDamage, int highDamage, int spellEffect)
{
	mName                       =  name;
	mHitPoints                  =  hp;
	mAccuracy                   =  acc;
	mExpReward                  =  xpReward;
	mArmor                      =  armor;
	mWeapon.mName               =  weaponName;
	mWeapon.mDamageRange.mLow   =  lowDamage;
	mWeapon.mDamageRange.mHigh  =  highDamage;
	mSpellEffect                =  spellEffect;

}

bool Monster::isDead()
{
	return mHitPoints <= 0;
}

int Monster::getXPReward()
{
	return mExpReward;
}

std::string Monster::getName()
{
	return mName;
}

int Monster::getArmor()
{
	return mArmor;
}

void Monster::attack(Player& player)
{
	cout << "A " << mName << " attacks you with a"
		<< mWeapon.mName << "!" << endl;

	// Test to see if the monster hit the player
	if (Random(0, 20) < mAccuracy)
	{
		// Generate a damage value based on the weapons range.
		int damage = Random(mWeapon.mDamageRange);

		// Subtract the player's armor from damage to 
		// simulate armor weakening the attack.  Note that
		// if the armor > damage this results in a nagative
		// number.
		int totalDamage = 0;

		if (mSpellEffect > 0)
		{
			cout << "The " << mName << " still feels the effects of your spell." << endl;
			totalDamage = (damage / 2) - player.getArmor();
		}
		else
		{
			int totalDamage = damage - player.getArmor();
		}

		// If totalDamage <= 0, then we say that, although
		// the attack hit, it did not penetrate the armor.
		if (totalDamage <= 0)
		{
			cout << "The " << mName << "'s attack failed to "
				<< "penetrate your armor." << endl;
		}
		else
		{
			cout << "You are hit for " << totalDamage
				<< " damage!" << endl;

			// Subtract damage from players hitpoints
			player.takeDamage(totalDamage);
		}
	}
	else
	{
		cout << "The " << mName << " missed!" << endl;
	}
	cout << endl;
}

void Monster::takeDamage(int damage, int spellEffect)
{
	mHitPoints -= damage;
	mSpellEffect = spellEffect;
}

void Monster::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}