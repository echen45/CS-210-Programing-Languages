#ifndef FILE_H
#define FILE_H

class File {
	public:
		string PrintSymbol(int numSymbols, string chosenSymbol);
		void PrintMenu();
		void ReadData();
		void WriteDataToNewFile();
		void CreateHistogram();
		void DisplayData();
		void Option1();
		bool Option4();
	private:
		vector<string> itemList;
		map<string, int> itemFrequency;
};

#endif