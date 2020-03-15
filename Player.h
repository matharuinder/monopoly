#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Block.h"
using namespace std;

class Player
{
private:
	
	vector<string> cities;
public:
	string name;
	int balance;
	Player() { }
	Player(string name, int balance) {
		this->name = name;
		this->balance = balance;
	}
	~Player() { }
	void buyCity(string name) {
		cities.push_back(name);

	}
	

};