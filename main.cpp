#include "SortAlgo.hpp"

int main(){
  vector<int> v;
  unsigned seed = 754;
  minstd_rand0 rng(seed);
  generate_even_vector(v,500,rng);
  InsertionSort(v);
  return 0;
}
