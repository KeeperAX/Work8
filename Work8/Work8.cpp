#include <iostream>
#include "header.h"
#include "header2.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	bool work = false;
	while (!work)
	{
		system("cls");
		cout << "\tКакой пункт выбрать? " << endl;
		cout << "[1] 8.1 - Умножение матрицы. " << endl;
		cout << "[2] 8.2 - Возведение в степень. " << endl;
		cout << "[3] Остановить программу. " << endl;
		int choice; cin >> choice;
		switch (choice)
		{
		case 1: system("cls"); mainone(); break;
		case 2: system("cls"); localmain(); break;
		case 3: system("cls"); work = true; break;
		default: system("cls"); cout << "Error"; break;
		}
	}
	return 0;
}

