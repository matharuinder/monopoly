#pragma once
#include <cstdlib>
#include <ctime>

int GenerateDice(int x)
{
	srand(time(0));
	return ((rand() % x) + 1);
	//
}