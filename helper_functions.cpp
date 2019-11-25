#include "helper_functions.hpp"

bool isSorted(vector<int> &v){
    //Verifica si un vector esta organizado
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

string printSorting(vector<int> &v){
  //Retorna un string con los elementos del vector
  string sort = "";
  for(int i = 0; i < v.size(); i++){
    sort = sort + to_string(v[i]) + " ";
  }
  return sort;
}

void itemSwap(vector<int> &v, int id1, int id2){
  //Intercambia dos elementos del vector
  int temp = v[id1];
  v[id1] = v[id2];
  v[id2] = temp;
}

void generate_vector(vector<int> &v, int size, minstd_rand0 &rng){
  //Genera un vector con el tamaño dado y numeros aleatorios
  v.clear();
  const int max_num = size;
  rng();
  for(int i = 0; i < size; i++){
    int num = int(max_num*(double(rng())/rng.max()));
    v.push_back(num);
  }
}

void shuffle(vector<int>& v, minstd_rand0& rng){
  //Dos indices aleatorios
  int num1 = int(v.size() * ( double(rng()) / rng.max() ));
  int num2 = int(v.size() * ( double(rng()) / rng.max() ));

  //Intercambia los indices
  itemSwap(v, num1, num2);
}

void generate_even_vector(vector<int> &v, int size, minstd_rand0& rng){
  //Genera un vector con una secuencia de numeros desde 1 hasta el tamaño dado
  for(int i = 1; i <= size; i++){
    v.push_back(i);
  }
  //Intercambia aleatoriamente los elementos del vector
  for(int k = 0; k < 1000; k++){
    shuffle(v, rng);
  }
}

void generate_ordered_even_vector(vector<int> &v, int size, bool inv){
  //Genera un vector con elementos aleatorios y sin repeticion pero ordenados o invertidos
  if(inv){
    for(int i = size; i > 0; i--){
      v.push_back(i);
    }
  }else{
    for(int i = 1; i <= size; i++){
      v.push_back(i);
    }
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

void generate_ordered_vector(vector<int>& v,int size, minstd_rand0& rng, bool inv){
  //Genera una secuencia de numeros aleatorios, pero ordenados o invertidos
  v.clear();
  rng();
  if(!inv){
    int current = 0;
    for(int i = 0; i < size; ++i){
      //number between 0 and 1
      int bin = int(2 * ( double(rng()) / rng.max() ));
      int num;
      if(bin == 1){
  num = i;
  current = i;
      }else
  num = current;
      v.push_back(num);
    }
  }else{
    int current = size-1;
    for(int i = size-1; i >= 0; --i){
      //number between 0 and 1
      int bin = int(2 * ( double(rng()) / rng.max() ));
      int num;
      if(bin == 1){
  num = i;
  current = i;
      }else
  num = current;
      v.push_back(num);
    }
  }
}

