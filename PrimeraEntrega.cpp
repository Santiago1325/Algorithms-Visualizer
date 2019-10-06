#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void itemSwap(vector<int> &v, int id1, int id2){
    int temp = v[id1];
    v[id1] = v[id2];
    v[id2] = temp;
}

int findMax(vector<int> a){
    int max = a[0];
    for(int i = 1; i < a.size(); i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

void printBars(vector<int> &a){
    int b = findMax(a);
    for(int i = 0; i < b; i++){
        for(int j = 0; j < a.size(); j++){
            if(a[j] >= b-i){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

void BubbleSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size()-1-i; j++){
            if(v[j] > v[j+1]){
                itemSwap(v, j, j+1);
                swaps++;
                comparisons++;
                printBars(v);
                printVector(v);
                cout << "\n";
            }else{
                comparisons++;
            }
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

void SelectionSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    int minIndex;
    for(int i = 0; i < v.size(); i++){
        minIndex = i;
        for(int j = i+1; j < v.size(); j++){
            if(v[j] < v[minIndex]){
                comparisons++;
                minIndex = j;
            }else{
                comparisons++;
            }
        }
        if(v[i] > v[minIndex]){
            itemSwap(v, i, minIndex);
            swaps++;
            comparisons++;
            printBars(v);
            printVector(v);
            cout << endl;
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

void InsertionSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    int auxIndex;
    for(int i = 1; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            comparisons++;
            auxIndex = i;
            itemSwap(v, i, i+1);
            swaps++;
            printBars(v);
            printVector(v);
            while(v[auxIndex] < v[auxIndex-1]){
                comparisons++;
                itemSwap(v, auxIndex, auxIndex-1);
                swaps++;
                printBars(v);
                printVector(v);
                cout << endl;
                auxIndex--;
            }
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl; 
}



int main() {
    vector<int> a = {4,6,2,1,9,5,7,3,8};
    printBars(a);
    printVector(a);
    cout << "\n";
    InsertionSort(a);
    return 0;
}