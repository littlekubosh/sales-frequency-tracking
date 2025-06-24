#pragma once
#include <string>//including reuired libraries
#include <vector>

#ifndef Produce_h
#define Produce_h
class Produce {
public://Declaring public member functions and variables
	Produce(std::vector <std::string> sales, std::vector <std::string> items);
	void PrintReport();
	void PrintReport(std::string name);
	void PrintHistogram();
	int PrintMenu();
private://Declaring private member functions and variables
	int FindFrequency(std::string name);
	std::vector<std::string> sales;
	std::vector<std::string> items;
};
#endif