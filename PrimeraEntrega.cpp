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

void printSorting(vector<int> &a){
    printBars(a);
    printVector(a);
    cout << endl;
}

void BubbleSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    printSorting(v);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size()-1-i; j++){
            comparisons++;
            if(v[j] > v[j+1]){
                itemSwap(v, j, j+1);
                swaps++;
                printSorting(v);
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
    printSorting(v);
    for(int i = 0; i < v.size(); i++){
        minIndex = i;
        for(int j = i+1; j < v.size(); j++){
            comparisons++;
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        comparisons++;
        if(v[i] > v[minIndex]){
            itemSwap(v, i, minIndex);
            swaps++;
            printSorting(v);
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

void InsertionSort(vector<int> &v){
    int comparisons = 0;
    int swaps = 0;
    int auxIndex;
    printSorting(v);
    for(int i = 1; i < v.size(); i++){
        comparisons++;
        if(v[i] < v[i-1]){
            auxIndex = i-1;
            itemSwap(v, i, i-1);
            swaps++;
            printSorting(v);
            comparisons++;
            while(v[auxIndex] < v[auxIndex-1]){
                itemSwap(v, auxIndex, auxIndex-1);
                swaps++;
                printSorting(v);
                auxIndex--;
            }
        }else{
            comparisons++;
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl; 
}



int main() {
    vector<int> a = {9,8,7,6,5,4,3,2,1};
    vector<int> b = {1,2,3,4,5,6,7,8,9};
    vector<int> c = {5,7,2,4,6,1,9,8,3};
    
    char k;
    char l;
    cout << "Choose the sorting algorithm:\n1) Bubble Sort\n2) Selection Sort\n3) Insertion Sort\n";
    cin >> k;
    cout << "Choose the vector: \n";
    cout << "1) A: ";
    printVector(a);
    cout << "2) B: ";
    printVector(b);
    cout << "3) C: ";
    printVector(c);
    cin >> l;
    
    if(k == '1'){
        if(l == '1'){
            BubbleSort(a);
        }else if(l == '2'){
            BubbleSort(b);
        }else if(l == '3'){
            BubbleSort(c);
        }
    }else if(k == '2'){
        if(l == '1'){
            SelectionSort(a);
        }else if(l == '2'){
            SelectionSort(b);
        }else if(l == '3'){
            SelectionSort(c);
        }
    }else if(k == '3'){
        if(l == '1'){
            InsertionSort(a);
        }else if(l == '2'){
            InsertionSort(b);
        }else if(l == '3'){
            InsertionSort(c);
        }
    }

    return 0;
}