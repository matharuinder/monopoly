#pragma once
#include "Block.h"
#include "Dice.h"
#include "Random.h"

class GameManager
{
private:
	Block* blocks; //dynamically allocated array of doors
	int totalDoors; //how many doors in the game?
	int openedDoors; //how many doors opened?

public:
	GameManager(int totalDoorsToGenerate)
	{
		Player p1("player1",4000);
		Player p2("player2", 4000);

		totalDoors = totalDoorsToGenerate;
		openedDoors = 0;

		blocks = new Block[totalDoors]; //allocate memory 
		for (int i = 0; i < totalDoorsToGenerate; i++)
		{
			//Block bk = 
			/*BLOCK_TYPE dt = (DOOR_TYPE)GEP::RandomRange(0, 1);
			int randVal = 0;
			if (dt == 0)
				randVal = GEP::RandomRange(20, 60);
			else
				randVal = GEP::RandomRange(10, 30);

			doors[i].InitializeDoor(dt, randVal);*/
			Block bk = GEP::RandomRange();
			blocks[i] = bk;
		}
		int x;
		srand(time(0));
		for (int i = 0;i < 100;i++) {
			
			x = ((rand() % 6) + 1);
			if (i % 2 == 0) {
				
				
				if (blocks[x].blockType == 0 && (p1.balance - blocks[x].purchaseValue)>=0) {
					p1.buyCity(blocks[x].city);
					p1.balance -= blocks[x].purchaseValue;
					blocks[x].blockType = OWNED;
					cout << p1.name << " Bought " << blocks[x].city << " for " << blocks[x].purchaseValue << " Balance: " << p1.balance << endl;
				} else
				if (blocks[x].blockType == 1) {
					if (!(blocks[x].owner.name == "player1")) {
						p2.balance += blocks[x].rent;
						p1.balance -= blocks[x].rent;
						if (p1.balance <= 0) {
							cout << p1.name << " Lost! ";
							break;
						}
						cout << p1.name << " payed " << blocks[x].rent << " for " << blocks[x].city << " to " << p2.name << " p2 Balance: " << p2.balance << endl;
					}
					
				}
				else {
					cout << p1.name << " has " << p1.balance << " price " << blocks[x].purchaseValue << " | Cannot be Bought or Rented! " << endl;
				}
			}
			else {
				//x = GenerateDice(totalDoors);
				
				if (blocks[x].blockType == 0 && (p2.balance - blocks[x].purchaseValue) >= 0) {
					p2.buyCity(blocks[x].city);
					p2.balance -= blocks[x].purchaseValue;
					blocks[x].blockType = OWNED;
					cout << p2.name << " Bought " << blocks[x].city << " for " << blocks[x].purchaseValue << " Balance: " << p2.balance << endl;
				}else
				if (blocks[x].blockType == 1) {
					if (!(blocks[x].owner.name == "player2")) {
						p1.balance += blocks[x].rent;
						p2.balance -= blocks[x].rent;
						if (p2.balance <= 0) {
							cout << p2.name << " Lost! ";
							break;
						}
						cout << p2.name << " payed " << blocks[x].rent << " for " << blocks[x].city << " to " << p1.name << " p1 Balance: " << p1.balance << endl;
					}
					
				}
				else {
					cout << p2.name << " has " << p2.balance << " price " << blocks[x].purchaseValue << " | Cannot be Bought or Rented! " << endl;
				}
			}
		}

	}

	~GameManager()
	{
		delete[] blocks;
	}

	/*void PrintAllDoors()
	{
		for (int i = 0; i < totalDoors; i++)
		{
			blocks[i].Print();
		}
	}*/

	int getOpenedDoorsCount() { return openedDoors; }
	int getTotalDoorsCount() { return totalDoors; }
	int getRemainingDoorsCount() { return totalDoors - openedDoors; }

};
