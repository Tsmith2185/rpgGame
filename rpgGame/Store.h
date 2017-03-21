// Store.h
#ifndef STORE_H
#define STORE_H

#include "Weapon.h"
#include "Monster.h"
#include <string>

class Store
{
public:

	// Constructor.
	Store();

	// Methods.
	void viewPlayerInventory();
	void viewStoreInventory();
	void buyFromStore();
	void sellToStore();

private:
	// Data members.

};

#endif //STORE_H