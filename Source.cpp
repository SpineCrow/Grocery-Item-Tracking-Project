#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// made a class to name functions and variables for coding
class Grocery {
	//public functions for easy modification throughout the code
public:
	int groceryList();

	int openFile();

	int option = 0;

	//private functions to make sure there are no changes during debugging
private:
	string food;

	int frequency = 0;

	map <string, int> groceryFrequency;
};

//menu made to ask the user for their inputs
int Grocery::groceryList() {
	do {
		cout << "----Corner Grocer Application----" << endl;
		cout << "1. Search for a food item" << endl;
		cout << "2. Print food numeric value of frequencies" << endl;
		cout << "3. Print food frequencies in histogram" << endl;
		cout << "4. Exit Program" << endl;
		cout << "Enter your options: ";
		cin >> option;

		//switch made in order to track user's input, and then generate 
		switch (option) {

			//switch option that prints this message if the input is wrong
		default: {
			cout << "Wrong option, please try again!" << endl;
			break;
		}
			   //case option that prints the food Item you want to search for
		case 1: {
			string searchFood;
			cout << "Enter food item name: ";
			cin >> searchFood;

			if (groceryFrequency.count(searchFood) > 0) {
				cout << searchFood << " " << groceryFrequency[searchFood] << endl;

			}
			else {
				cout << "Item not found, try again!" << endl; //This prints if the food item you named is not on the lsit
			}
			break;
		}
			  //case option that prints the food's numeric value 
		case 2: {
			for (auto&& food : groceryFrequency) {
				cout << food.first << " - " << food.second << endl;
			}
			break;
		}
			  //case option that prints the food's numeric value in histogram
		case 3: {
			for (auto&& food : groceryFrequency) {
				cout << food.first << " ";
				for (int i = 1; i <= food.second; i++) {
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
			  //case option that ends the program after input
		case 4: {
			cout << "Exiting program" << endl;
			break;

		}
		}

		//this loop helps open the stream class to write in the file
	} while (option != 4);
	ofstream Frequency;

	//the Frequency file is now Frequency.dat
	Frequency.open("frequency.dat");

	//the if statement makes sure the Frequency file is being open
	if (!Frequency.is_open()) {
		cout << "Can't open file frequency.dat" << endl;
		return 1;
		}
	//this code writes the data recieved towards the Frequency file
	for (auto&& food : groceryFrequency) {
		Frequency << food.first << " - " << food.second << endl;
	}
	//closes Frequency file
	Frequency.close();
}

//reads the "CS210_Project_Three_Input_File.txt" file and checks to see if the file is in reach of opening
int Grocery::openFile() {
	ifstream inputFile("CS210_Project_Three_Input_File.txt");
	if (!inputFile) {
		cout << "There was an error opening the input file, try again" << endl;
		return 1;
	}
	string line, word;
	while (getline(inputFile, line)) {
		// this code processes each line made in the file
		istringstream iss(line);
		while (iss >> word) {
			// this code processes each word made in the file
			groceryFrequency[word]++;
		}
	}
}

//class made to open grocery file with variable groceryList, and makes Grocery object f to open new file
int main() {

	Grocery f;

	f.openFile();
	f.groceryList();

	return 0;
}