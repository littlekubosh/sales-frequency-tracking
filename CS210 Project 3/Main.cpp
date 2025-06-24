#include <iostream>//Including required libraries
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "Produce.h"//Including Produce class

std::vector<std::string> salesList;//Declaring vectors to hold sales and item type data
std::vector<std::string> produceList;

int main() {
	std::ifstream inFS;//Declaring variables
	std::ofstream outFS;
	std::string word;
	std::string item;
	int count = 0;
	bool contains = false;
	int numItems = 0;
	int menuOption = 0;
	std::string quit;

	inFS.open("CS210 Project Three Input File.txt");//Opening input file
	if (!inFS.is_open()) {
		std::cout << "Could not open file \"CS210 Project Three Input File.txt.\"" << std::endl;
		return 1; // 1 indicates error
	}

	while (!inFS.eof()) {//Populating salesList with each item sold
		inFS >> word;
		salesList.push_back(word);
	}

	for (int i = 0; i < salesList.size(); ++i) {//Populating produceList with each type of produce sold
		if (std::find(produceList.begin(), produceList.end(), salesList.at(i)) == produceList.end()) {
			std::string temp = salesList.at(i);
			produceList.push_back(temp);
		}
	}

	outFS.open("frequency.dat");//opening backup file
	if (!outFS.is_open()) {
		std::cout << "Could not open file myoutfile.txt." << std::endl;
		return 1;
	}

	for (int i = 0; i < produceList.size(); ++i) {//Outputting data to backup file
		item = produceList.at(i);
		for (int i = 0; i < salesList.size(); ++i) {
			if (salesList.at(i) == item) {
				numItems += 1;
			}
		}
		outFS << item << " " << numItems << std::endl;
	}

	outFS.close();//Closing files
	inFS.close();
	
	Produce CornerGrocer(salesList, produceList);//Declaring Produce class object

	menuOption = CornerGrocer.PrintMenu();//Printing the menu and getting the chosen menu option
	while (menuOption == -1) {
		std::cout << menuOption;
	}

	while ((menuOption >= 1) && (menuOption <= 4)) {//Performing required functions based on menu choice
		if (menuOption == 1) {//Printing the frequency of sales for a single item
			std::cin >> word;
			for (int i = 0; i < produceList.size(); ++i) {//Determining if the user input is an item type sold
				if (word == produceList.at(i)) {
					contains = true;
				}
			}

			if (contains) {//Prints report if the input is a type of item sold
				std::cout << std::endl;
				CornerGrocer.PrintReport(word);
				std::cout << std::endl;
				menuOption = CornerGrocer.PrintMenu();
			}

			else {
				std::cout << std::endl << "Item not found." << std::endl << std::endl;
				menuOption = CornerGrocer.PrintMenu();
			}
		}

		else if (menuOption == 2) {//Prints a report of the frequency of each item sold
			CornerGrocer.PrintReport();
			menuOption = CornerGrocer.PrintMenu();
		}

		else if (menuOption == 3) {//Prints a histogram of the frequency of each item sold
			CornerGrocer.PrintHistogram();
			menuOption = CornerGrocer.PrintMenu();
		}

		else if (menuOption == 4) {//Quits the program
			std::cout << "Are you sure you want to quit? yes or no" << std::endl;
			std::cin >> quit;

			while ((quit != "no") && (quit != "No") && (quit != "yes") && (quit != "Yes")) {
				std::cout << std::endl << "Please respond yes or no." << std::endl;
				std::cin >> quit;
			}

			if ((quit == "yes") || (quit == "Yes")) {//Ensures the user wants to quit the program
				return 0;
			}

			else if ((quit == "no") || (quit == "No")) {//Returns the user to the menu
				menuOption = CornerGrocer.PrintMenu();
			}
		}
	}
	return 0;
}