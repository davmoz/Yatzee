#pragma once
#include <string>

using namespace std;

class ProtocolColumn
{
	static const int PROTOCOLCAPACITY = 6;
private:
	string name = "?";
	int results[PROTOCOLCAPACITY] = {};
	bool played[PROTOCOLCAPACITY] = { false };
public:
	ProtocolColumn(string name = "?");
	~ProtocolColumn();

	bool addResult(const int diceValue, const int result);
	string getPlayerName() const;
	int getTotalSum() const;
	bool isFilled() const;
	string toString() const;
};