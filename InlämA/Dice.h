#pragma once
#include <cstdlib>

using namespace std;
class Dice
{
private: 
	int nrOfFaces = 0, currentValue = 0;
public:
	Dice(int nrOfFaces = 6);
	~Dice();

	void toss();
	int getCurrentValue() const;
};

