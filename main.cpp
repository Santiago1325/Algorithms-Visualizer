#include "SortAlgo.hpp"

void generate_vector(int size, vector<int> &v, minstd_rand0 &rng){
  v.clear();
  const int max_num = size;
  rng();
  for(int i = 0; i < size; i++){
    int num = int(max_num*(double(rng())/rng.max()));
    v.push_back(num);
  }
}


int main(){
  vector<int> v;
  unsigned seed = 123;
  minstd_rand0 rng(seed);
  generate_vector(15,v,rng);
  InsertionSort(v);
  return 0;
}
