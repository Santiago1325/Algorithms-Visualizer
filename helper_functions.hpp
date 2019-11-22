#ifndef __helper_functions_hpp
#define __helper_functions_hpp

#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <random>
#include <iostream>
using namespace std;

bool isSorted(vector<int> &v);
string printSorting(vector<int> &v);
void generate_vector(vector<int> &v, int size, minstd_rand0 &rng);
void itemSwap(vector<int> &v, int id1, int id2);
void shuffle(vector<int>& v, minstd_rand0& rng);
void generate_even_vector(vector<int> &v, int size, minstd_rand0& rng);
void MaxHeapify(vector<int> &v, int size, int id, int &swaps, int &comparisons, ofstream &outfile, ofstream &outswap, ofstream &outcomp, ofstream &outind);
void MinHeapify(vector<int> &v, int size, int id, int &swaps, int &comparisons, ofstream &outfile, ofstream &outswap, ofstream &outcomp, ofstream &outind);
void generate_ordered_vector(vector<int>& v,int size, minstd_rand0& rng, bool inv);
void generate_ordered_even_vector(vector<int> &v, int size, bool inv);

#endif
