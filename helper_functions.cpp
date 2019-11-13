#include "helper_functions.hpp"

bool isSorted(vector<int> &v){
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

string printSorting(vector<int> &v){
  //Returns a string with the elements of the vector
  string sort = "";
  for(int i = 0; i < v.size(); i++){
    sort = sort + to_string(v[i]) + " ";
  }
  return sort;
}

void itemSwap(vector<int> &v, int id1, int id2){
    //Swaps two elements of the vector
    int temp = v[id1];
    v[id1] = v[id2];
    v[id2] = temp;
}

void generate_vector(int size, vector<int> &v, minstd_rand0 &rng){
  v.clear();
  const int max_num = size;
  rng();
  for(int i = 0; i < size; i++){
    int num = int(max_num*(double(rng())/rng.max()));
    v.push_back(num);
  }
}

void shuffle(vector<int>& v, minstd_rand0& rng){
  //two random numbers
  int num1 = int(v.size() * ( double(rng()) / rng.max() ));
  int num2 = int(v.size() * ( double(rng()) / rng.max() ));

  //swap the elements
  itemSwap(v, num1, num2);
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

void MaxHeapify(vector<int> &v, int size, int id, int &swaps, int &comparisons, ofstream &outfile, ofstream &outswap, ofstream &outcomp, ofstream &outind){
  int index = id;
  int left = 2*index + 1;
  int right = 2*index + 2;
  int largest = index;
  comparisons++;
  outcomp << comparisons << endl;
  if(left < size && v[largest] < v[left]){
    largest = left;
  }
  comparisons++;
  outcomp << comparisons << endl;
  if(right < size && v[largest] < v[right]){
    largest = right;
  }
  comparisons++;
  outcomp << comparisons << endl;
  if(largest != id){
    itemSwap(v, largest, id);
    outind << -1 << endl;
    outfile << printSorting(v) << endl;
    swaps++;
    outswap << swaps << endl;
    MaxHeapify(v, size, largest, swaps, comparisons, outfile, outswap, outcomp, outind);
  }
}

void MinHeapify(vector<int> &v, int size, int id, int &swaps, int &comparisons, ofstream &outfile, ofstream &outswap, ofstream &outcomp, ofstream &outind){
  int index = id;
  int left = 2*index + 1;
  int right = 2*index + 2;
  int smallest = index;
  comparisons++;
  outcomp << comparisons << endl;
  if(left < size && v[smallest] > v[left]){
    smallest = left;
  }
  comparisons++;
  outcomp << comparisons << endl;
  if(right < size && v[smallest] > v[right]){
    smallest = right;
  }
  comparisons++;
  outcomp << comparisons << endl;
  if(smallest != id){
    itemSwap(v, smallest, id);
    outind << -1 << endl;
    outfile << printSorting(v) << endl;
    swaps++;
    outswap << swaps << endl;
    MinHeapify(v, size, smallest, swaps, comparisons, outfile, outswap, outcomp, outind);
  }
}
