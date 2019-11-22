#ifndef __SortAlgo_hpp
#define __SortAlgo_hpp

#include "helper_functions.hpp"

void BubbleSort(vector<int> & v);
void InsertionSort(vector<int> & v);
void SelectionSort(vector<int> & v);
void CocktailSort(vector<int> &v);
void BogoSort(vector<int>& v, minstd_rand0& rng);
void MaxHeapSort(vector<int> &v);
void MinHeapSort(vector<int> &v);
void CountingSort(vector<int> &v);
void OddEvenSort(vector<int> &v);   
void GnomeSort(vector<int> &v);

#endif
