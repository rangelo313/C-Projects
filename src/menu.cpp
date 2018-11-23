
#include <iostream>

using namespace std;

#include "studentlist.h"

void menu()
{
	cout << "                *** Student List menu ***" << endl;
	cout << "        I       Import students from a file" << endl;
	cout << "        S       Show student list (brief)" << endl;
	cout << "        E       Export a grade report (to file)" << endl;
	cout << "        M       Show this Menu" << endl;
	cout << "        Q       Quit Program" << endl;
	cout << "        O       Sort The Array" << endl;
}

int main()
{
	char choice;
	StudentList w;
	char fileName[30];
	menu();
	do
	{
		cout << "> ";
		cin >> choice;
		cin.getline(fileName, 3);//endl
		switch (choice)
		{
		case 'I':
		case 'i':
			cout << "Enter filename: ";
			cin.getline(fileName, 30);
			w.ImportFile(fileName);
			break;
		case 'S':
		case 's':
			w.ShowList();
			break;
		case 'M':
		case 'm':
			menu();
			break;
		case 'E':
		case 'e':
			cout << "Enter filename: ";
			cin.getline(fileName, 30);
			w.CreateReportFile(fileName);
			break;
		case 'O':
		case 'o':
			w.SortArray();
			break;
		}

	} while (choice != 'Q');
	return 0;
}