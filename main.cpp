#include "SortAlgo.hpp"
#include <set>

void generate_vector(int size, vector<int> &v, minstd_rand0 &rng){
  v.clear();
  const int max_num = size;
  rng();
  for(int i = 0; i < size; i++){
    int num = int(max_num*(double(rng())/rng.max()));
    v.push_back(num);
  }
}

void swap(int i, int j, vector<int>& v){
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void shuffle(vector<int>& v, minstd_rand0& rng){
  //two random numbers
  int num1 = int(v.size() * ( double(rng()) / rng.max() ));
  int num2 = int(v.size() * ( double(rng()) / rng.max() ));

  //swap the elements
  swap(num1, num2, v);
}

void generate_norepeat_vector(int size, vector<int>& v, minstd_rand0& rng){
  v.clear();
  const int max_num = size;
  //use set to profit from the count method
  set<int> numbers;
  //Generation of a sequence of (pseudo)random numbers
  rng();
  int count = 0;
  while(count < size){
    int num = int(max_num * ( double(rng()) / rng.max() ));
    if(numbers.count(num) == 0){ //if number not in set
      numbers.insert(num);
      v.push_back(num);
      count++;
    }
  }
}


void generate_even_vector(vector<int> &v, int size, minstd_rand0& rng){
  for(int i = 1; i <= size; i++){
    v.push_back(i);
  }
  for(int k = 0; k < 1000; k++){
    shuffle(v, rng);
  }
}


int main(){
  vector<int> v;
  unsigned seed = 123;
  minstd_rand0 rng(seed);
  generate_even_vector(v,100,rng);
  BubbleSort(v);
  return 0;
}
