#include "SortAlgo.hpp"

void BubbleSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size()-1-i; j++){
            comparisons++;
            outfile << printSorting(v) << endl; //Writes the vector on the file
            outfileIndx << j+1 << endl; //Writes the index that is beoing looked at
            outfileComp << comparisons << endl; //Wirtes the number of comparisons done
            outfileSwap << swaps << endl; //Writes the number of swaps done
            if(v[j] > v[j+1]){
                itemSwap(v, j, j+1);
                swaps++;
                outfile << printSorting(v) << endl;
                outfileIndx << j+1 << endl;
                outfileComp << comparisons << endl;
                outfileSwap << swaps << endl;
            }
        }
    }
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
}

void SelectionSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    int minIndex;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    for(int i = 0; i < v.size(); i++){
        minIndex = i;
        for(int j = i+1; j < v.size(); j++){
            outfile << printSorting(v) << endl;
            outfileIndx << minIndex << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
            comparisons++;
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        comparisons++;
        if(v[i] > v[minIndex]){
            itemSwap(v, i, minIndex);
            swaps++;
            outfile << printSorting(v) << endl;
            outfileIndx << minIndex << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
        }
    }
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
}

void InsertionSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    int auxIndex;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    for(int i = 1; i < v.size(); i++){
        outfile << printSorting(v) << endl;
        outfileIndx << i << endl;
        outfileComp << comparisons << endl;
        outfileSwap << swaps << endl;
        comparisons++;
        if(v[i] < v[i-1]){
            auxIndex = i-1;
            itemSwap(v, i, i-1);
            swaps++;
            outfile << printSorting(v) << endl;
            outfileIndx << auxIndex-2 << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
            comparisons++;
            while(v[auxIndex] < v[auxIndex-1]){
                comparisons++;
                itemSwap(v, auxIndex, auxIndex-1);
                swaps++;
                outfile << printSorting(v) << endl;
                outfileIndx << auxIndex-2 << endl;
                outfileComp << comparisons << endl;
                outfileSwap << swaps << endl;
                auxIndex--;
            }
        }
    }
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
}

void CocktailSort(vector<int> &v){
    bool swaped = true;
    int comparisons = 0;
    int swaps = 0;
    int upperLimit = v.size()-1;
    int lowerLimit = 0;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    while(swaped){
        swaped = false;
        for(int j = lowerLimit; j < upperLimit; j++){
            comparisons++;
            outfile << printSorting(v) << endl; //Writes the vector on the file
            outfileIndx << j+1 << endl; //Writes the index that is beoing looked at
            outfileComp << comparisons << endl; //Wirtes the number of comparisons done
            outfileSwap << swaps << endl; //Writes the number of swaps done
            if(v[j] > v[j+1]){
                itemSwap(v, j, j+1);
                swaped = true;
                swaps++;
                outfile << printSorting(v) << endl;
                outfileIndx << j+1 << endl;
                outfileComp << comparisons << endl;
                outfileSwap << swaps << endl;

            }
        }
        if(!swaped){
            break;
        }
        swaped = false;
        upperLimit--;
        for(int k = upperLimit; k > lowerLimit; k--){
            comparisons++;
            outfile << printSorting(v) << endl;
            outfileIndx << k-1 << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
            if(v[k] < v[k-1]){
                itemSwap(v,k,k-1);
                swaped = true;
                swaps++;
                outfile << printSorting(v) << endl;
                outfileIndx << k-1 << endl;
                outfileComp << comparisons << endl;
                outfileSwap << swaps << endl;
            }
        }
        lowerLimit++;  
    }
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close(); 
}

void BogoSort(vector<int>& v, minstd_rand0& rng){
    int comparisons = 0;
    int swaps = 0;
    int count = 0;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");    
    while(!isSorted(v)){
        shuffle(v, rng);
        swaps++;
        comparisons += v.size();
        outfile << printSorting(v) << endl;
        outfileComp << comparisons << endl;
        outfileIndx << -1 << endl;
        outfileSwap << swaps << endl;
        count++;
    }
}