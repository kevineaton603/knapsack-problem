#include "Item.h"
Item::Item() {
	name = "";
	val = 0;
	wt = 0;
}
Item::Item(int value, int weight) {
	val = value;
	wt = weight;
}
Item::~Item() {

}
std::ostream& operator<<(std::ostream& out, Item& obj) {
	out << "Name: " << obj.name << "\tWeight " << obj.wt << "\tVal" << obj.val << "\n";
	return out;
}
std::ifstream& operator>>(std::ifstream & inFile, Item& obj) {
	inFile >> obj.name >> obj.wt >> obj.val;
	return inFile;
}