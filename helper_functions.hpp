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
void generate_vector(int size, vector<int> &v, minstd_rand0 &rng);
void swap(int i, int j, vector<int>& v);
void shuffle(vector<int>& v, minstd_rand0& rng);
void generate_norepeat_vector(int size, vector<int>& v, minstd_rand0& rng);
void generate_even_vector(vector<int> &v, int size, minstd_rand0& rng);


#endif