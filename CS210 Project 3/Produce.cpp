#include <string>//Declaring required libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Produce.h"

Produce::Produce(std::vector<std::string> sales, std::vector<std::string> items) {//Defining constructor
	this->sales = sales;
	this->items = items;
}

int Produce::FindFrequency(std::string item) {//Defining FindFrequency
	int itemCount = 0;
	for (int i = 0; i < sales.size(); ++i) {//Iterates through the days sales to find the number of occurances for a specific item
		if (item == sales.at(i)) {
			itemCount += 1;
		}
	}

	return itemCount;
}
void Produce::PrintReport() {//Defining PrintReport
	std::string tempItem;
	for (int i = 0; i < items.size(); ++i) {//Iterates through the sales and finds the number of sales for each item
		tempItem = items.at(i);
		std::cout << std::setw(12) << tempItem;
		std::cout << " " << this->FindFrequency(tempItem) << std::endl;
	}
	std::cout << std::endl;
}
void Produce::PrintReport(std::string name) {//Calls FindFrequency for a user input item
	std::cout << std::setw(12) << name;
	std::cout << " " << this->FindFrequency(name) << std::endl;
}
void Produce::PrintHistogram() {//Defining PrintHistogram
	std::string tempItem;
	int itemCount;
	for (int i = 0; i < items.size(); ++i) {//Iterates through the sales, prints each unique item name and prints a carrot for each sale of that item
		tempItem = items.at(i);
		itemCount = this->FindFrequency(tempItem);
		std::cout << std::setw(12) << tempItem;
		std::cout << " ";
		for (int i = 0; i < itemCount; ++i) {
			std::cout << "^";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Produce::PrintMenu() {//Prints the menu and takes a menu option
	int menuOption;
	std::cout << "Please select from the below menu" << std::endl << std::endl;
	std::cout << "1: Search for the number of sales for a specific item." << std::endl << "2: Print a report of how many of each item was sold." << std::endl << "3: Print a histogram showing how many of each item was sold" << std::endl << "4: Quit" << std::endl;
	std::cin >> menuOption;
	while ((menuOption < 1) || (menuOption > 4)) {//Validating user input
		std::cout << "Please choose an option shown between 1 and 4." << std::endl;
		std::cin >> menuOption;
	}
	return menuOption;
}