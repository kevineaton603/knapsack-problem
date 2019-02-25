#include "ItemList.h"

ItemList::ItemList()
{
	numberOfItems = 0;
	items = nullptr;
}

ItemList::~ItemList()
{
	if (items != nullptr) {
		delete[] items;
	}
}