#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

#include "File.h"

//Outputing stars or spaces
string File::PrintSymbol(int numSymbols, string starOrSpace) {
    string symbolOutput;
    for (int i = 0; i < numSymbols; i++) {
        if (starOrSpace == "*") {
            symbolOutput += "*";
        }
        else if (starOrSpace == " ") {
            symbolOutput += " ";
        }
    }
    return symbolOutput;
}

//Outputing user menu
void File::PrintMenu() {
    cout << endl << PrintSymbol(20, " ") << PrintSymbol(61, "*") << endl;
    cout << PrintSymbol(20, " ") << setw(60) << left << "* 1-Get frequency of a certain item"
	<< "*" << endl;
    cout << PrintSymbol(20, " ") << setw(60) << left << "* 2-List items with their frequencies" <<
    "*" << endl;
    cout << PrintSymbol(20, " ") << setw(60) << left <<
	"* 3-Create histogram of the items and their frequencies" << "*" << endl;
    cout << PrintSymbol(20, " ") << setw(60) << left << "* 4-Exit Program" << "*" << endl;
    cout << PrintSymbol(20, " ") << PrintSymbol(61, "*") << endl << endl;
}

//Store data from original file in map and vector
void File::ReadData() {
	ifstream inFS;
	string fileValue;

	inFS.open("CS210_Project_Three_Input_File.txt");

	inFS >> fileValue;
	while (!inFS.fail()) {
		if (itemFrequency.count(fileValue) == 1) {
			itemFrequency.at(fileValue) += 1;
		}
		else {
			itemFrequency.emplace(fileValue, 1);
			itemList.push_back(fileValue);
		}	
		inFS >> fileValue;
	}

	inFS.close();
}

//Write data to new file from map and vector
void File::WriteDataToNewFile() {
	ofstream outFS;

	outFS.open("frequency.dat");
	for (int i = 0; i < itemList.size(); i++) {
		outFS << itemList.at(i) << " " << itemFrequency.at(itemList.at(i)) << endl;
	}

	outFS.close();
}

//Create Histogram
void File::CreateHistogram() {
	for (int i = 0; i < itemList.size(); i++) {
		cout << right << setw(20) << itemList.at(i) << setw(1) << "| " << setw(20) << left << 
		PrintSymbol(itemFrequency.at(itemList.at(i)), "*") << endl;
	}
}

//Output data
void File::DisplayData() {
	ifstream inFS;
	string fileValue;

	inFS.open("frequency.dat");
	for (int i = 0; i < itemList.size(); i++) {
		getline(inFS, fileValue);
		cout << fileValue << endl;
	}

	inFS.close();
}

//Find frequency of selected item
void File::Option1() {
	string itemInput;

    cout << "Enter item: " << endl;
	cin >> itemInput;

	try {
		cout << itemFrequency.at(itemInput) << endl;
	}
	catch (out_of_range) {
		cout << "Enter an item from the list. Start with a capital letter." << endl;
	}

}

//Exiting program
bool File::Option4() {
    return true;
}

