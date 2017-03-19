// Player.cpp

#include <iostream>
#include "Player.h"
#include "Random.h"
#include <string>
using namespace std;

Player::Player()
{
	mName          =  "Default";
	mClassName     =  "Default";
	mAccuracy      =  0;
	mHitPoints     =  0;
	mMaxHitPoints  =  0;
	mExpPoints     =  0;
	mNextLevelExp  =  0;
	mLevel         =  0;
	mArmor         =  0;
	mWeapon.mName  = "Default Weapon Name";
	mWeapon.mDamageRange.mLow   =  0;
	mWeapon.mDamageRange.mHigh  =  0;
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

}