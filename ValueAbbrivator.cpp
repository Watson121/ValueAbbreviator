// ValueAbbrivator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <iomanip>  
#include <cmath>
#include <sstream> 
#include <cfloat> 

using namespace std;


// Function that works out monetary value abbrivation
string MonetaryValueAbbrivation(long long input) {
	const char* suffixs[] = { "", "K", "M", "B", "T" };
	const long long exponents[] = { 1, 1e3, 1e6, 1e9, 1e12, 1e15 };

	// Handling case if input is 0
	if (input == 0) {
		return "0";
	}

	// Working out what suffix and exponent to use
	int indexToUse = static_cast<int>(log(input) / log(1000));

	// output string stream
	ostringstream oss;

	// calculating the result
	double result = static_cast<double>(input) / exponents[indexToUse];
	oss.precision(1);
	oss << fixed << result;

	return oss.str() + " " + suffixs[indexToUse];
}

// Funciton that works out data storage abbrivation
string DataStorageAbbrivation(long long input) {
	
	const char* suffixes[] = { "B", "KB", "MB", "GB", "TB"};
	const long long exponents[] = { 1e0, 1e3, 1e6, 1e9, 1e12 };

	// Handling case if input is 0
	if (input == 0) {
		return "0 B";
	}

	// Working out what the suffix will be
	int suffixIndex = static_cast<int>(log(input) / log(1024));

	// output string stream
	ostringstream oss;

	// Calculating the result
	double result = static_cast<double>(input) / exponents[suffixIndex];
	oss.precision(1);
	oss << fixed << result;

	return oss.str() + " " + suffixes[suffixIndex];

}

// Loading up the main menu
void MainMenu() {

	//Clearing Screen
	system("cls");
	
	while (true) {

		cout << "\nMain Menu:" << endl;
		cout << "\nOption 1: Would you like to abbreviate a monetary value?" << endl;
		cout << "Option 2: Would you like to abbreviate a data storage value?" << endl;
		cout << "\nEnter 1, 2 or 0 to Quit:" << endl;

		int option;
		cin >> option;

		if (option == 0) {
			break;
		}

		switch (option) {
		case 1:
			cout << "\nYou have chosen Money" << endl;
			break;
		case 2:
			cout << "\nYou have chosen Data" << endl;
			break;
		default:
			cout << "\nPlease choose valid option" << endl;
			system("pause");
			break;
		}

		long long value;
		cout << "\nInput number:" << endl;
		cin >> value;

		cout << "Abbreivated value: ";
		switch (option) {
		case 1:
			cout << MonetaryValueAbbrivation(value) << endl;
			break;
		case 2:
			cout << DataStorageAbbrivation(value) << endl;
			break;
		}
	}
	//system("pause");

	//MainMenu();
}



int main()
{
	MainMenu();
	return 0;
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
