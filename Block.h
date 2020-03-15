#pragma once

#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

enum BLOCK_TYPE { UNOWNED, OWNED };

class Block
{
public:
	BLOCK_TYPE blockType;
	string city;
	int purchaseValue;
	int rent;
	Player owner;
public:
	Block() {}
	Block(string city, int purchaseValue, int rent) {
		this->purchaseValue = purchaseValue;
		this->city = city;
		this->rent = rent;
		this->blockType = UNOWNED;

	}
	~Block() { }
	void Print() {  cout << "Door Type is: " << blockType << " | val: " << purchaseValue << " | val: " << city << endl; }

};

