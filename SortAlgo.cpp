#include "SortAlgo.hpp"

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



void BubbleSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    ofstream outfile;
    outfile.open("Sorting.txt");
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size()-1-i; j++){
            comparisons++;
            outfile << printSorting(v) << endl; //Writes the vector on the file
            outfile << j << endl; //Writes the index that is beoing looked at
            outfile << comparisons << endl; //Wirtes the number of comparisons done
            outfile << swaps << endl; //Writes the number of swaps done
            if(v[j] > v[j+1]){
                itemSwap(v, j, j+1);
                swaps++;
                outfile << printSorting(v) << endl;
                outfile << j << endl;
                outfile << comparisons << endl;
                outfile << swaps << endl;
            }
        }
    }
    outfile.close();
}

void SelectionSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    int minIndex;
    ofstream outfile;
    outfile.open("Sorting.txt");
    for(int i = 0; i < v.size(); i++){
        minIndex = i;
        for(int j = i+1; j < v.size(); j++){
            comparisons++;
            outfile << printSorting(v) << endl;
            outfile << i << endl;
            outfile << comparisons << endl;
            outfile << swaps << endl;
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        comparisons++;
        if(v[i] > v[minIndex]){
            itemSwap(v, i, minIndex);
            swaps++;
            outfile << printSorting(v) << endl;
            outfile << i << endl;
            outfile << comparisons << endl;
            outfile << swaps << endl;
        }
    }
}

void InsertionSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    int auxIndex;
    ofstream outfile;
    outfile.open("Sorting.txt");
    for(int i = 1; i < v.size(); i++){
        outfile << printSorting(v) << endl;
        outfile << i << endl;
        outfile << comparisons << endl;
        outfile << swaps << endl;
        if(v[i] < v[i-1]){
            auxIndex = i-1;
            itemSwap(v, i, i-1);
            swaps++;
            comparisons++;
            outfile << printSorting(v) << endl;
            outfile << i << endl;
            outfile << comparisons << endl;
            outfile << swaps << endl;
            while(v[auxIndex] < v[auxIndex-1]){
                itemSwap(v, auxIndex, auxIndex-1);
                swaps++;
                comparisons++;
                outfile << printSorting(v) << endl;
                outfile << i << endl;
                outfile << comparisons << endl;
                outfile << swaps << endl;
                auxIndex--;
            }
        }else{
            comparisons++;
        }
    }
}
