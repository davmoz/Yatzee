#include <cstdlib>
#include "Dice.h"


using namespace std;

Dice::Dice(int nrOfFaces)
{
	this->nrOfFaces = nrOfFaces;
	toss();
}
Dice::~Dice()
{
}

void Dice::toss()
{
	this->currentValue = rand() % this->nrOfFaces + 1;
}
int Dice::getCurrentValue() const
{
	return this->currentValue;
}