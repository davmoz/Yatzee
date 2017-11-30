#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Dice.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "swedish");
	srand(100);

	Dice aDice(12);
	Dice anotherDice(6);
	Dice aThirdDice(2);

	cout << "F�rv�ntat resultat: 1 1 11 3 11 2 2 11 10 3";

	cout << endl << "Ditt resultat:      ";
	for (int i = 0; i < 10; i++)
	{
		aDice.toss();
		cout << aDice.getCurrentValue() << " ";
	}

	cout <<endl << "Tryck p� en tangent f�r att forts�tta: "<<endl;
	getchar();
	cout << "F�rv�ntat resultat: 2 4 1 1 6 6 4 5 6 1";

	cout << endl << "Ditt resultat:      ";
	for (int i = 0; i < 10; i++)
	{
		anotherDice.toss();
		cout << anotherDice.getCurrentValue() << " ";
	}

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	cout << "F�rv�ntat resultat: 1 2 2 1 2 2 2 1 1 1";

	cout << endl << "Ditt resultat:      ";
	for (int i = 0; i < 10; i++)
	{
		aThirdDice.toss();
		cout << aThirdDice.getCurrentValue() << " ";
	}

	cout << endl << "Tryck p� en tangent f�r att forts�tta: ";
	getchar();
	return 0;
}
