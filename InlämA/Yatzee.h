#pragma once
#include <string>
#include "dice.h";
#include "ProtocolColumn.h"



using namespace std;

class Yatzee
{
	static const int nrOfDices = 5;
private:
	int nextPlayer = 0;
	int nrOfPlayers = 0;
	int capacity = 0;
	Dice dices[nrOfDices];
	ProtocolColumn* *protocol;
	// Help functions
	void makeCopy(const Yatzee &source);
	void freeMemory();
	void expand();
public:
	Yatzee(const int capacity = 2);
	Yatzee(const Yatzee& other);
	~Yatzee();
	
	Yatzee& Yatzee::operator=(const Yatzee& other);
	void addPlayer(const string name);
	string protocolInfoOfCurrentPlayer() const;
	int getNrOfPlayers() const;
	void toss(const int diceValue = 0);
	string infoOfLatestToss() const;
	bool addResult(const int diceValue);
	string nameOfCurrentPlayer() const;
	void nextPlayersTurn();
	bool areAllPlayersDone() const;
};