#include"Main.h"
void clearItems(Item * items) {
	if (items != nullptr)
		delete[] items;
}
bool loadFile(std::string name, KnapSack& ks) {
	std::ifstream inFile;
	bool goodFile = false;
	ks.clearMemo();
	inFile.open(name);
	if (inFile.good()) {
		inFile >> ks;
		goodFile = true;
	}
	inFile.close();
	return goodFile;
}

std::string getFileName()
{
	std::string fileName;
	std::cout << "Please Enter The Name of the File or quit:\n";
	std::cin >> fileName;
	return fileName;
}
