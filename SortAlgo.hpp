#ifndef __SortAlgo_hpp
#define __SortAlgo_hpp

#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <iostream>
using namespace std;

string printSorting(vector<int> & v);
void BubbleSort(vector<int> & v);
void InsertionSort(vector<int> & v);
void SelectionSort(vector<int> & v);
void itemSwap(vector<int> &v, int id1, int id2);

#endif
