#include "Yatzee.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void testingCopyConstructor(Yatzee theYatzee)
{
	theYatzee.addPlayer("Stina");
	theYatzee.toss();
}

void showProtocols(Yatzee &theYatzee)
{
	for (int i = 0; i < theYatzee.getNrOfPlayers(); i++)
	{
		cout << theYatzee.protocolInfoOfCurrentPlayer() << endl;
		theYatzee.nextPlayersTurn();
		cout << endl;
	}
}

void testingTossing(Yatzee &theYatzee, int n = 3)
{
	int value = rand() % 6 + 1;
	for (int round = 1; round <= n; round++)
	{
		theYatzee.toss();
		theYatzee.toss(value);
		theYatzee.toss(value);
		theYatzee.addResult(value);
		theYatzee.nextPlayersTurn();
		value = rand() % 6 + 1;
		theYatzee.toss();
		theYatzee.toss(value);
		theYatzee.toss(value);
		theYatzee.addResult(value);
		theYatzee.nextPlayersTurn();
		value = rand() % 6 + 1;
	}
}

int main()
{
	setlocale(LC_ALL, "swedish");
	srand(100);
	Yatzee aYatzee;

	cout << "--------------------------------------------1----------------------------------------" << endl;

	cout << "Testar kopieringskonstruktorn p� objekt utan n�gra protokoll" << endl;
	/*
	cout << "F�rv�ntad utskrift:\nRune ska ha 2 po�ng p� 1:or och 5 po�ng p� 5:or samt summan 7"
	<<"\nLisa ska ha 8 po�ng p� 2:or och 6 po�ng p� 6:or samt summan 14"<< endl;*/
	cout << "F�rv�ntad utskrift:\n";
	cout << "Antalet spelare 2\n\nRune\nLisa\n\n"
		<< "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<< "Lisa\n"
		<< "1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     :  0\n6     :  6\n"
		<< "-------------------\nSUM =   14\n" << endl;


	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	cout << endl << "Din utskrift: " << endl;
	testingCopyConstructor(aYatzee);


	cout << "Antalet spelare: " << aYatzee.getNrOfPlayers() << endl;
	aYatzee.addPlayer("Rune");
	aYatzee.addPlayer("Lisa");
	cout << endl;
	for (int i = 0; i < aYatzee.getNrOfPlayers(); i++)
	{
		cout << aYatzee.nameOfCurrentPlayer() << endl;
		aYatzee.nextPlayersTurn();
	}

	cout << endl;

	testingTossing(aYatzee, 2);

	showProtocols(aYatzee);

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	system("cls");
	cout << "--------------------------------------------2----------------------------------------" << endl;

	cout << "Testar kopieringskonstruktor p� objekt inneh�llande protokoll" << endl;

	cout << "F�rv�ntad utskrift:\n";
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<< "Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;
	cout << "Rune\n1     :  2\n2     :   0\n3     : 15\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =   22\n\n"
		<< "Lisa\n1     :  2\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   26\n" << endl;


	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	cout << endl << "Din utskrift: " << endl;

	testingCopyConstructor(aYatzee);

	Yatzee xYatzee = aYatzee;
	testingTossing(xYatzee);
	testingTossing(aYatzee, 1);

	showProtocols(aYatzee);
	showProtocols(xYatzee);
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	system("cls");
	cout << "--------------------------------------------3----------------------------------------" << endl;

	cout << "Testar tilldelningsoperator mellan objekt som inte inneh�ller protokoll och "
		<< " objekt som inneh�ller protokoll" << endl;

	cout << "F�rv�ntad utskrift:\n";
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<< "Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<< "Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;


	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();


	cout << "Din utskrift\n";
	Yatzee anotherYatzee;
	anotherYatzee = aYatzee;

	showProtocols(anotherYatzee);
	showProtocols(aYatzee);
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	system("cls");

	cout << "--------------------------------------------4----------------------------------------" << endl;

	cout << "Testar tilldelningsoperatorn mellan tv� objekt som inneh�ller protokoll" << endl;

	cout << "F�rv�ntad utskrift:\n";
	cout << "Rune\n1     :  2\n2     :  0\n3     :  9\n4     :  8\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =   24\n\n"
		<< "Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<< "Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;


	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	cout << "Din utskrift:\n";
	testingTossing(anotherYatzee, 4);

	showProtocols(anotherYatzee);
	showProtocols(aYatzee);
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	system("cls");

	cout << "--------------------------------------------5----------------------------------------" << endl;

	cout << "Testar tilldelningsoperatorn mellan objekt som inneh�ller protokoll"
		<< " och objekt som inte inneh�ller protokoll" << endl;

	cout << "F�rv�ntad utskrift:\n";
	cout << "Katarina\n1     :  0\n2     :  6\n3     :  9\n4     :  0\n5     :  0\n6     : 18\n"
		<< "-------------------\nSUM =   33\n\n"
		<< "Charlotta\n1     :  0\n2     :  0\n3     :  6\n4     :  8\n5     : 10\n6     :  0\n"
		<< "-------------------\nSUM =   24\n" << endl;



	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();


	cout << "Din utskrift\n";


	Yatzee aThirdYatzee;
	aYatzee = aThirdYatzee;

	aYatzee.addPlayer("Katarina");
	aYatzee.addPlayer("Charlotta");
	testingTossing(aYatzee, 5);

	showProtocols(aYatzee);

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	system("cls");
	cout << "--------------------------------------------6----------------------------------------" << endl;

	cout << "Testar tilldelningsoperatorn mellan tv� objekt som inte inneh�ller protokoll" << endl;

	cout << "F�rv�ntad utskrift:\n";
	cout << "Allan\n1     :  0\n2     :  0\n3     :  9\n4     :  0\n5     : 10\n6     :  0\n"
		<< "-------------------\nSUM =   19\n\n"
		<< "Britta\n1     :  0\n2     :  6\n3     :  9\n4     :  0\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =   15\n" << endl;
	cout << "Herbert\n1     :  0\n2     :  6\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =    6\n\n"
		<< "Hugo\n1     :  0\n2     :  4\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =   4\n" << endl;
	cout << "Rut\n1     :  0\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    5\n\n"
		<< "Bertil\n1     :  0\n2     :  0\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =   0\n" << endl;

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	Yatzee bYatzee(3);
	Yatzee cYatzee;

	cYatzee = bYatzee;

	cYatzee.addPlayer("Allan");
	cYatzee.addPlayer("Britta");
	cYatzee.addPlayer("Herbert");

	testingTossing(cYatzee);
	bYatzee.addPlayer("Bertil");
	bYatzee.addPlayer("Hugo");
	bYatzee.addPlayer("Rut");
	testingTossing(bYatzee, 2);

	showProtocols(cYatzee);
	showProtocols(bYatzee);

	cout << "------------------------------------------SLUT---------------------------------------" << endl;

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	return 0;
}