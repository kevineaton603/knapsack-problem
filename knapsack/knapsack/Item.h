#pragma once
#include<string>
#include<fstream>
struct Item
{
	std::string name;
	int val, wt;
	//Default Constructor
	Item();
	Item(int value, int weight);
	//Default Constructor
	~Item();
	//Operator Overloading
	friend std::ostream& operator<<(std::ostream& out, Item& obj);
	friend std::ifstream& operator>>(std::ifstream & inFile, Item& obj);
};