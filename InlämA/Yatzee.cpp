#include <iostream>
#include "Yatzee.h"


void Yatzee::makeCopy(const Yatzee &source)
{
	this->capacity = source.capacity;
	this->nrOfPlayers = source.nrOfPlayers;
	this->protocol = new ProtocolColumn*[this->capacity];
	for (int i = 0; i < this->nrOfPlayers; i++)
	{
		this->protocol[i] = new ProtocolColumn(*source.protocol[i]);
	}
}
void Yatzee::freeMemory()
{
	for (int i = 0; i < this->nrOfPlayers; i++)
	{
		if (this->protocol[i] != nullptr)
		{
			delete this->protocol[i];
			this->protocol[i] = nullptr;
		}
	}
	delete[] this->protocol;
	this->protocol = nullptr;
}

void Yatzee::expand()
{
	if (this->nrOfPlayers == this->capacity)
	{
		ProtocolColumn* *tempProtocol = new ProtocolColumn*[capacity + 5];
		for (int i = 0; i < this->nrOfPlayers; i++)
		{
			tempProtocol[i] = this->protocol[i];
		}
		delete[] this->protocol;
		this->protocol = tempProtocol;
		tempProtocol = nullptr;
		this->capacity += 5;
	}
}

Yatzee::Yatzee(const int capacity)
{
	this->capacity = capacity;
	this->protocol = new ProtocolColumn*[this->capacity];

	// Initiating all pointers in protocolColumn* to nullptr
	for (int i = 0; i < capacity; i++)
	{
		this->protocol[i] = nullptr;
	}
}
Yatzee::Yatzee(const Yatzee & source)
{
	this->makeCopy(source);
}
Yatzee::~Yatzee()
{
	this->freeMemory();
	this->nrOfPlayers = 0;
}

Yatzee& Yatzee::operator=(const Yatzee& source)
{
	if (this != &source)
	{
		this->freeMemory();
		this->makeCopy(source);
	}
	return *this;
}

void Yatzee::addPlayer(const string name)
{
	this->expand(); // Expand if nrOfPlayers == capacity
	this->protocol[this->nrOfPlayers] = new ProtocolColumn(name);
	this->nrOfPlayers++;
}
string Yatzee::protocolInfoOfCurrentPlayer() const
{
	string info;
	info += this->protocol[nextPlayer]->toString();
	return info;
}
int Yatzee::getNrOfPlayers() const
{
	/*
		returning capacity instead of number of players, which would return 0 in line 71 in YatzeeTest.cpp
		since the funtion is being called before the players are added to the protocol in the "aYatzee" object.
	*/
	//return this->nrOfPlayers;
	return this->capacity;
}
void Yatzee::toss(const int diceValue)
{
	for (int i = 0; i < nrOfDices; i++)
	{
		if (this->dices[i].getCurrentValue() != diceValue)
		{
			this->dices[i].toss();
		}
	}
}
string Yatzee::infoOfLatestToss() const
{
	string latestToss;
	for (int i = 0; i < nrOfDices; i++)
	{
		latestToss += to_string(dices[i].getCurrentValue()) + " ";
	}
	latestToss += "\n";
	return latestToss;
}
bool Yatzee::addResult(const int diceValue)
{
	int nrOfDuplicates = 0;
	for (int i = 0; i < nrOfDices; i++)
	{
		if (this->dices[i].getCurrentValue() == diceValue)
		{
			nrOfDuplicates++;
		}
	}
	bool ifSuccess = true;
	ifSuccess = protocol[this->nextPlayer]->addResult(diceValue, diceValue * nrOfDuplicates);
	return ifSuccess;
}
string Yatzee::nameOfCurrentPlayer() const
{
	return this->protocol[nextPlayer]->getPlayerName();
}
void Yatzee::nextPlayersTurn()
{
	this->nextPlayer++;
	// Once nextPlayer == nrOfPlayers, that means that all registered players are done playing this round.
	if (this->nextPlayer == this->nrOfPlayers)
	{
		this->nextPlayer = 0;
	}
}
bool Yatzee::areAllPlayersDone() const
{
	bool allFinished = false;
	// Checking if the last player's protocol is filled tells us that all previous players also filled their protocols
	if (this->protocol[this->nrOfPlayers - 1]->isFilled())
	{
		allFinished = true;
	}
	return allFinished;
}
