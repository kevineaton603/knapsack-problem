#pragma once
#include"ItemList.h"
struct KnapSack {
public:
	int ** memo;
	int maxWeight, finalValue;
	ItemList itemList;
	KnapSack();
	KnapSack(int maxWeight, ItemList itemList);
	KnapSack(int maxWeight, Item * items, int numOfItems);
	~KnapSack();
	friend std::ifstream& operator>>(std::ifstream& inFile, KnapSack& obj);
	void loadMemo();
	void clearMemo();
};
