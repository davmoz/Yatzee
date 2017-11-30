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

	//Skapa ett Yatzee-objekt baserat p� nrOfPlayers
	Yatzee myObject = Yatzee(nrOfPlayers);
	//L�t anv�ndaren mata in namnen p� spelarna och l�gg till spelarna till Yatzee-objektet
	string name = "?";
	for (int i = 0; i < nrOfPlayers; i++)
	{
		cout << "Please enter name " << i + 1 << ": ";
		getline(cin, name);
		myObject.addPlayer(name);
	}
	//S� l�nge som inte alla spelare har spelat klart
	int nrToKeep = 0;
	bool allFinished = myObject.areAllPlayersDone();
	while (!allFinished)
	{
		//Presentera protokollet f�r aktuell spelare
		cout << myObject.protocolInfoOfCurrentPlayer();
		//Kasta en omg�ng t�rningar
		myObject.toss();
		//Upprepa 2 g�nger
		for (int i = 0; i < 2; i++)
		{
			//Visa t�rningarnas utfall
			cout << myObject.infoOfLatestToss();
			//L�t anv�ndaren mata in vilket t�rningsv�rde som ska sparas
			cout << myObject.nameOfCurrentPlayer() << ", which number would you like to keep? " << endl;
			cin >> nrToKeep;
			//Kasta alla �vriga t�rningar
			myObject.toss(nrToKeep);
		}
		//Visa t�rningarnas utfall
		cout << myObject.infoOfLatestToss();
		//L�t anv�ndaren mata in vilket t�rningsv�rde resultatet ska sparas p�
		cout << myObject.nameOfCurrentPlayer() << ", which number would you want to save? " << endl;
		cin >> nrToKeep;
		bool added = myObject.addResult(nrToKeep);
		//S� l�nge som t�rningsv�rdet redan �r ifyllt	
		while (!added)
		{
			//L�t anv�ndaren mata in vilket t�rningsv�rde resultatet ska sparas p�	
			cout << nrToKeep << " is already added, please try another number!" << endl;
			cin >> nrToKeep;
			added = myObject.addResult(nrToKeep);
		}
		myObject.addResult(nrToKeep);
		//Presentera protokollkolumnen f�r aktuell spelare	
		cout << myObject.protocolInfoOfCurrentPlayer() << endl;
		//N�sta spelares tur
		myObject.nextPlayersTurn();
		allFinished = myObject.areAllPlayersDone();
		//Rensa sk�rmen och pausa
		system("cls");
	}
	//Presentera protokollkolumnen och totalsumman f�r varje spelare
	for (int i = 0; i < myObject.getNrOfPlayers(); i++)
	{
		cout << myObject.protocolInfoOfCurrentPlayer() << endl;
		myObject.nextPlayersTurn();
	}
	system("pause");
	return 0;
}