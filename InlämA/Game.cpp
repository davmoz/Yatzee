#include <iostream>
#include <ctime>
#include "Yatzee.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	setlocale(LC_ALL, "swedish");
	srand(static_cast<unsigned int>(time(0)));

	int nrOfPlayers=0;

	cout << "How many player will be playing? ";
	cin >> nrOfPlayers;
	cin.ignore();

	//Skapa ett Yatzee-objekt baserat på nrOfPlayers
	Yatzee myObject = Yatzee(nrOfPlayers);
	//Låt användaren mata in namnen på spelarna och lägg till spelarna till Yatzee-objektet
	string name = "?";
	for (int i = 0; i < nrOfPlayers; i++)
	{
		cout << "Please enter name " << i + 1 << ": ";
		getline(cin, name);
		myObject.addPlayer(name);
	}
	//Så länge som inte alla spelare har spelat klart
	int nrToKeep = 0;
	bool allFinished = myObject.areAllPlayersDone();
	while (!allFinished)
	{
		//Presentera protokollet för aktuell spelare
		cout << myObject.protocolInfoOfCurrentPlayer();
		//Kasta en omgång tärningar
		myObject.toss();
		//Upprepa 2 gånger
		for (int i = 0; i < 2; i++)
		{
			//Visa tärningarnas utfall
			cout << myObject.infoOfLatestToss();
			//Låt användaren mata in vilket tärningsvärde som ska sparas
			cout << myObject.nameOfCurrentPlayer() << ", which number would you like to keep? " << endl;
			cin >> nrToKeep;
			//Kasta alla övriga tärningar
			myObject.toss(nrToKeep);
		}
		//Visa tärningarnas utfall
		cout << myObject.infoOfLatestToss();
		//Låt användaren mata in vilket tärningsvärde resultatet ska sparas på
		cout << myObject.nameOfCurrentPlayer() << ", which number would you want to save? " << endl;
		cin >> nrToKeep;
		bool added = myObject.addResult(nrToKeep);
		//Så länge som tärningsvärdet redan är ifyllt	
		while (!added)
		{
			//Låt användaren mata in vilket tärningsvärde resultatet ska sparas på	
			cout << nrToKeep << " is already added, please try another number!" << endl;
			cin >> nrToKeep;
			added = myObject.addResult(nrToKeep);
		}
		myObject.addResult(nrToKeep);
		//Presentera protokollkolumnen för aktuell spelare	
		cout << myObject.protocolInfoOfCurrentPlayer() << endl;
		//Nästa spelares tur
		myObject.nextPlayersTurn();
		allFinished = myObject.areAllPlayersDone();
		//Rensa skärmen och pausa
		system("cls");
	}
	//Presentera protokollkolumnen och totalsumman för varje spelare
	for (int i = 0; i < myObject.getNrOfPlayers(); i++)
	{
		cout << myObject.protocolInfoOfCurrentPlayer() << endl;
		myObject.nextPlayersTurn();
	}
	system("pause");
	return 0;
}