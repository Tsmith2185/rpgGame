// Spell.h 

#ifndef SPELL_H 
#define SPELL_H 

#include "Range.h" 
#include <string> 

struct Spell
{
	std::string mName;
	Range       mDamageRange;
	int mSpellEffect = 0;
	int mMagicNeeded = 0;
};

#endif //SPELL_H