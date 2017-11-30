#include <iostream>
#include "ProtocolColumn.h"
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	setlocale(LC_ALL, "swedish");
	ProtocolColumn aProtocol("Kalle");
	aProtocol.addResult(1, 5);
	
	cout << "-------------------------------------------1-----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	cout << "F�rv�ntat resultat: " << endl
		<< "Kalle" << endl 
		<< "1     :  5" << endl
		<< "2     :  0" << endl
		<< "3     :  0" << endl
		<< "4     :  0" << endl
		<< "5     :  0" << endl
		<< "6     :  0" << endl
		<< "-------------------" << endl
		<< "SUM =    5" << endl;



	cout << endl << "Ditt resultat: "<<endl;


	cout<< aProtocol.toString() << endl;

	cout << "-------------------------------------------2-----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	
	cout << "F�rv�ntat resultat: " << endl
		<< "Korrekt retur p� addResult(...)" << endl;
	cout << endl << "Ditt resultat: " << endl;
	if (!aProtocol.addResult(1, 3))
	{
		cout << "Korrekt retur p� addResult(...)" << endl;
	}
	else
	{
		cout << "FEL retur p� addResult(...)" << endl;
	}

	cout << "-------------------------------------------3-----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	cout << "F�rv�ntat resultat: " << endl
		<< "Kalle" << endl 
		<< "1     :  5" << endl
		<< "2     :  0" << endl
		<< "3     :  0" << endl
		<< "4     :  0" << endl
		<< "5     :  0" << endl
		<< "6     :  0" << endl
		<< "-------------------" << endl
		<< "SUM =    5" << endl;



	cout << endl << "Ditt resultat: " << endl;


	cout << aProtocol.toString() << endl;
	cout << "-------------------------------------------4-----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	

	for (int i = 2; i <= 6; i++)
	{
		if (i != 4)
		{
			if (i % 2 == 0)
			{
				aProtocol.addResult(i, i * 3); // 2, 6
			}
			else
			{
				aProtocol.addResult(i, i * 2); // 3, 5
			}
			if (i == 5)
			{
				aProtocol.addResult(5, 25); // 5
			}
		}
	}


	cout << "F�rv�ntat resultat: " << endl
		<< "Kalle" << endl 
		<< "1     :  5" << endl
		<< "2     :  6" << endl
		<< "3     :  6" << endl
		<< "4     :  0" << endl
		<< "5     : 10" << endl
		<< "6     : 18" << endl
		<< "-------------------" << endl
		<< "SUM =   45" << endl;



	cout << endl << "Ditt resultat: " << endl;


	cout << aProtocol.toString() << endl;

	cout << "-------------------------------------------5-----------------------------------------------" << endl;

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();


	cout << "F�rv�ntat resultat: " << endl
		<< "Korrekt retur p� isFilled(...)" << endl;
	cout << endl << "Ditt resultat: " << endl;
	if (!aProtocol.isFilled())
	{
		cout << "Korrekt retur p� isFilled(...)" << endl;
	}
	else
	{
		cout << "FEL retur p� isFilled(...)" << endl;
	}

	cout << "-------------------------------------------6-----------------------------------------------" << endl;

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();


	cout << "F�rv�ntat resultat: " << endl
		<< "Korrekt retur p� getTotalSum()" << endl;
	cout << endl << "Ditt resultat: " << endl;
	if (aProtocol.getTotalSum() == 45) 
	{
		cout << "Korrekt retur p� getTotalSum()" << endl;
	}
	else
	{
		cout << "FEL retur p� getTotalSum()" << endl;
	}

	cout << "-------------------------------------------7-----------------------------------------------" << endl;

	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	aProtocol.addResult(4, 20);
	cout << "F�rv�ntat resultat: " << endl
		<< "Kalle" << endl
		<< "1     :  5" << endl
		<< "2     :  6" << endl
		<< "3     :  6" << endl
		<< "4     : 20" << endl
		<< "5     : 10" << endl
		<< "6     : 18" << endl
		<< "-------------------" << endl
		<< "SUM =   65" << endl;



	cout << endl << "Ditt resultat: " << endl;


	cout << aProtocol.toString() << endl;

	cout << "-------------------------------------------8-----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	ProtocolColumn anotherProtocol("Pelle");
	anotherProtocol.addResult(6, 12);
	anotherProtocol.addResult(2, 0);
	anotherProtocol.addResult(1, 3);
	anotherProtocol.addResult(5, 10);
	anotherProtocol.addResult(3, 9);
	anotherProtocol.addResult(4, 20);


	cout << "F�rv�ntat resultat: " << endl
		<< "Korrekt retur p� isFilled()" << endl;
	cout << endl << "Ditt resultat: " << endl;

	if (anotherProtocol.isFilled())
	{
		cout << "Korrekt retur p� isFilled()" << endl;
	}
	else
	{
		cout << "FEL retur p� isFilled()" << endl;
	}

	cout << "-------------------------------------------9-----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();


	cout << "F�rv�ntat resultat: " << endl
		<< "Korrekt retur p� getTotalSum()" << endl;
	cout << endl << "Ditt resultat: " << endl;

	if (aProtocol.getTotalSum() > anotherProtocol.getTotalSum())
	{
		cout << "Korrekt retur p� getTotalSum()" << endl;
	}
	else
	{
		cout << "FEL retur p� getTotalSum()" << endl;
	}

	cout << "-------------------------------------------10----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();

	cout << "F�rv�ntat resultat: " << endl
		<< "Korrekt retur p� getPlayerName()" << endl;
	cout << endl << "Ditt resultat: " << endl;

	if (aProtocol.getPlayerName() == "Kalle" && anotherProtocol.getPlayerName() == "Pelle")
	{
		cout << "Korrekt retur p� getPlayerName()" << endl;
	}
	else
	{
		cout << "FEL retur p� getPlayerName()" << endl;
	}

	cout << "-----------------------------------------SLUT----------------------------------------------" << endl;
	cout << endl << "Tryck p� en tangent f�r att forts�tta: " << endl;
	getchar();
	return 0;
}