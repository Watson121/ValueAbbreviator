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


void MonetaryValueAbbrivation(double input) {
	const char* suffixs[] = { "", "K", "M", "B", "T" };
	int suffixIndex = 0; 

	while (input >= 1000 && suffixIndex < 4) {
		input /= 1000;
		suffixIndex++;
	}

	cout << fixed << setprecision(2) << input << suffixs[suffixIndex] << endl;
}

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
		system("pause");
		MainMenu();
		break;
	}

	long long value;
	cout << "\nInput number:" << endl;
	cin >> value;

	switch (option) {
	case 1:
		MonetaryValueAbbrivation(value);
		break;
	case 2:
		cout << DataStorageAbbrivation(2100000000000LL) << endl;
		break;
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
