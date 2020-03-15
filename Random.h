#pragma once
#include <cstdlib>
#include <ctime>
#include "Block.h"

namespace GEP
{
	static bool isFirstTimeSeed = false;
	//Block block;
	Block RandomRange()
	{
		int minRange = 500;
		int maxRange = 2500;
		//seed only for the first time we call this function
		if (!isFirstTimeSeed)
		{
			srand(time(0));
			isFirstTimeSeed = true;
		}
		
		int price = (rand() % (maxRange - minRange + 1)) + minRange;

		int ctr = rand() % 6;
		string city;
		if (ctr == 0)
			city = "TORONTO";
		if (ctr == 1)
			city = "LA";
		if (ctr == 2)
			city = "NEW YORK";
		if (ctr == 3)
			city = "BOMBAY";
		if (ctr == 4)
			city = "PARIS";
		if (ctr == 5)
			city = "BRAMPTON";


		int mr=20;
		int mir=200;
		int rent = (rand() % (mr - mir + 1)) + mir;

		Block block(city, price, rent);
		return block;

	}

	//we will come to this later when we explain what static_cast is
	//float RandomRange(float minRange, float maxRange)
	//{
	   // if (!isFirstTimeSeed)
	   // {
	   //	 srand(time(0));
	   //	 isFirstTimeSeed = true;
	   // }

	   //// return ( static_cast<float> (rand())  )

	// }


}


