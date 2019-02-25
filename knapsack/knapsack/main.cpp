// A Dynamic Programming based solution for 0-1 Knapsack problem 

#include"Main.h"

int main()
{
	KnapSack knapSack;
	std::string fileName = "";
	do {
		fileName = getFileName();
		if (fileName != "quit" && loadFile(fileName, knapSack)) {
			knapSack.loadMemo();
			printf("The maximum value of loot for the %d pound knapsack is $%d\n", knapSack.maxWeight, knapSack.finalValue);
		}
		else {
			printf("The file did load correctly\n");
		}
	} while (fileName != "quit");
	
	std::cin.get();
	return 0;
}