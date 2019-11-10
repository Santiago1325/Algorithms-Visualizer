#ifndef __SortAlgo_hpp
#define __SortAlgo_hpp

#include "helper_functions.hpp"


string printSorting(vector<int> & v);
void BubbleSort(vector<int> & v);
void InsertionSort(vector<int> & v);
void SelectionSort(vector<int> & v);
void itemSwap(vector<int> &v, int id1, int id2);
void CocktailSort(vector<int> &v);
void BogoSort(vector<int>& v, minstd_rand0& rng);

#endif
