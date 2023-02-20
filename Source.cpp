#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

#include "File.h"

int main() {
    string userInput;
    bool exitProgram = false;
    File fileObj;

    fileObj.ReadData();
    fileObj.WriteDataToNewFile();

    //Loop runs until user enters 4
    while (exitProgram != true) {
        //Showing options
        fileObj.PrintMenu();
        cout << "Enter number:" << endl;

        //Validating user input
        try {
            cin >> userInput;
            if (userInput != "4" && userInput != "1" && userInput != "2" && userInput != "3") {
                throw runtime_error("Invalid input.");
            }
        }
        catch (runtime_error& excpt) {
            cout << "Enter a number on the menu." << endl;
        }

        //If statement used for all number options
        if (userInput == "1") {
            fileObj.Option1();
        }
        else if (userInput == "2") {
            fileObj.DisplayData();
        }
        else if (userInput == "3") {
            fileObj.CreateHistogram();
        }
        else if (userInput == "4") {
            exitProgram = fileObj.Option4();
        }
    }
	return 0;
}