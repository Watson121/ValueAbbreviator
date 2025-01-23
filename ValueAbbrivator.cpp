// ValueAbbrivator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <iomanip>  

using namespace std;



void MonetaryValueAbbrivation(float input) {
	const char* suffixs[] = { "", "K", "M", "B", "T" };
	int suffixIndex = 0; 

	while (input >= 1000) {
		input /= 1000;
		suffixIndex++;
	}

	cout << input << fixed << setprecision(2) << suffixs[suffixIndex] << endl;
}

void DataStorageAbbrivation(float input) {

}

// Loading up the main menu
void MainMenu() {

	//Clearing Screen
	system("cls");
	
	cout << "Main Menu:" << endl;
	cout << "\nOption 1: Would you like to abbreviate a monetary value?" << endl;
	cout << "Option 2: Would you like to abbreviate a data storage value?" << endl;
	cout << "\nEnter 1 or 2:" << endl;

	int option;
	cin >> option;

	switch (option) {
	case 1:
		cout << "\nYou have chosen Money" << endl;
		break;
	case 2:
		cout << "\nYou have chosen Data" << endl;
		break;
	default:
		cout << "\nPlease choose valid option" << endl;
		break;
	}

	int value;
	cout << "\nInput number:" << endl;
	cin >> value;

	switch (option) {
	case 1:
		MonetaryValueAbbrivation(value);
		break;
	case 2:
		DataStorageAbbrivation(value);
		break;
	}

	system("pause");

	MainMenu();
}



int main()
{
	MainMenu();
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
