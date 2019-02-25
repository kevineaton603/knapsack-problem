#pragma once
#include"Item.h"
struct ItemList {
	int numberOfItems;
	Item * items;
	ItemList();
	~ItemList();
};
