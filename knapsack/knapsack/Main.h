#pragma once
#include<stdio.h> 
#include<iostream>
#include"Knapsack.h"
void clearItems(Item * items);
bool loadFile(std::string name, KnapSack& ks);
std::string getFileName();