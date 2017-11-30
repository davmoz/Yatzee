#include "ProtocolColumn.h"

ProtocolColumn::ProtocolColumn(string name)
{
	this->name = name;
}
ProtocolColumn::~ProtocolColumn()
{

}

bool ProtocolColumn::addResult(const int diceValue, const int result)
{
	bool added = false;

	if (played[diceValue - 1] == false)
	{
		this->results[diceValue - 1] = result;
		this->played[diceValue - 1] = true;
		added = true;
	}
	return added;
}
string ProtocolColumn::getPlayerName() const
{
	return this->name;
}
int ProtocolColumn::getTotalSum() const
{
	int sum = 0;
	for (int i = 0; i < PROTOCOLCAPACITY; i++)
	{
		sum += this->results[i];
	}
	return sum;
}
bool ProtocolColumn::isFilled() const
{
	bool filled = true;
	for (int i = 0; i < PROTOCOLCAPACITY; i++)
	{
		if (this->played[i] == false)
		{
			filled = false;
		}
	} 
	return filled;
}
string ProtocolColumn::toString() const
{
	string info = "?";
	info = this->name + ":\n";
	for (int i = 0; i < PROTOCOLCAPACITY; i++)
	{
		info += to_string(i+1) + "     :  " + to_string(this->results[i]);
		if (this->played[i] == true)
		{
			info += "  [played] \n";
		}
		else
		{
			info += "\n";
		}
	}
	info += "-------------------\n";
	info += "SUM =    " + to_string(this->getTotalSum()) + "\n";
	return info;
}