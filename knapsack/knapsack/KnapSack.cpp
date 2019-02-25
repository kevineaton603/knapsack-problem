#include"Knapsack.h"

KnapSack::KnapSack(int maxWt, Item * items, int numOfItems) 
{
	itemList.numberOfItems = numOfItems;
	itemList.items = items;
	maxWeight = maxWt;
	memo = nullptr;
}

KnapSack::KnapSack()
{
	memo = nullptr;
}

KnapSack::KnapSack(int maxWeight, ItemList itemList)
{
	KnapSack(maxWeight, itemList.items, itemList.numberOfItems);
}

KnapSack::~KnapSack()
{
	clearMemo();
}

void KnapSack::loadMemo()
{
	int i, j;
	memo = new int*[itemList.numberOfItems + 1];
	for (i = 0; i <= itemList.numberOfItems; i++) {
		memo[i] = new int[maxWeight + 1];
	}
	for (i = 0; i <= itemList.numberOfItems; i++) {
		for (j = 0; j <= maxWeight; j++) {
			if (i == 0 || j == 0) {
				memo[i][j] = 0;
			}
			else if (itemList.items[i - 1].wt <= j)
				memo[i][j] = itemList.items[i - 1].val + memo[i - 1][j - itemList.items[i - 1].wt] > memo[i - 1][j] 
				? itemList.items[i - 1].val + memo[i - 1][j - itemList.items[i - 1].wt] 
				: memo[i - 1][j];
			else {
				memo[i][j] = memo[i - 1][j];
			}
		}
	}
	finalValue = memo[itemList.numberOfItems][maxWeight];
}

void KnapSack::clearMemo()
{
	if (memo != nullptr) {
		for (int i = itemList.numberOfItems - 1; i >= 0; i--) {
			delete[] memo[i];
		}
	}
}

std::ifstream & operator>>(std::ifstream & inFile, KnapSack & obj)
{
	inFile >> obj.maxWeight >> obj.itemList.numberOfItems;
	obj.itemList.items = new Item[obj.itemList.numberOfItems];
	for (int i = 0; i < obj.itemList.numberOfItems; i++) {
		inFile >> obj.itemList.items[i];
	}
	return inFile;
}
