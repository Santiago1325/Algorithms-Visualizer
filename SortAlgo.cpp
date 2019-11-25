#include "SortAlgo.hpp"

void BubbleSort(vector<int> &v){
    //Declaracion de variables
    int comparisons = 0;
    int swaps = 0;
    bool sorted = false;
    ofstream outfile; 
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    ofstream outfileInfo;
    //Abriendo los archivos
    outfileInfo.open("Info.txt");
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    //Insertando informacion dentro de los archivos
    outfileInfo << "Bubble Sort " << endl;
    outfileInfo << "O(N^2)" << endl;
    outfile << printSorting(v) << endl;
    outfileIndx << 0 << endl;
    outfileComp << comparisons << endl;
    outfileSwap << swaps << endl;
    //Ordenamiento
    while(!sorted){
        sorted = true;
        for(int j = 0; j < v.size()-1; j++){
            comparisons++;
            outfile << printSorting(v) << endl; 
            outfileIndx << j+1 << endl; 
            outfileComp << comparisons << endl; 
            outfileSwap << swaps << endl;
            //¿Es el elemento mayor al siguiente? 
            if(v[j] > v[j+1]){
                itemSwap(v, j, j+1);
                swaps++;
                sorted = false;
                //Insertando informacion actualizada
                outfile << printSorting(v) << endl;
                outfileIndx << j+1 << endl;
                outfileComp << comparisons << endl;
                outfileSwap << swaps << endl;
            }
        }
    }
    //Cierre de archivos
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
    outfileInfo.close(); 
}

void SelectionSort(vector<int> &v){
    //Declaracion de variables
    int comparisons = 0;
    int swaps = 0;
    int minIndex;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    ofstream outfileInfo;
    //Abriendo los archivos
    outfileInfo.open("Info.txt");
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    //Insertando informacion importante en los archivos
    outfileInfo << "Selection Sort" << endl;
    outfileInfo << "O(N^2)" << endl;
    outfile << printSorting(v) << endl;
    outfileIndx << 0 << endl;
    outfileComp << comparisons << endl;
    outfileSwap << swaps << endl;
    //Ordenamiento
    for(int i = 0; i < v.size(); i++){
        minIndex = i;
        for(int j = i+1; j < v.size(); j++){
            //Insertando informacion actualizada a los archivos
            outfile << printSorting(v) << endl;
            outfileIndx << minIndex << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
            comparisons++;
            //¿Es menor que el elemento seleccionado?
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        comparisons++;
        //Si el elemento seleccionado es menor al que se esta observando
        if(v[i] > v[minIndex]){
            itemSwap(v, i, minIndex);
            swaps++;
            //Insertando informacion actualizada a los archivos
            outfile << printSorting(v) << endl;
            outfileIndx << minIndex << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
        }
    }
    //Cierre de archivos
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
    outfileInfo.close(); 
}

void InsertionSort(vector<int> &v){
    //Declaracion de variables
    int comparisons = 0;
    int swaps = 0;
    int auxIndex;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    ofstream outfileInfo;
    //Preparando los archivos
    outfileInfo.open("Info.txt");
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    //Insertando informacion en los archivos
    outfileInfo << "Insertion Sort" << endl;
    outfileInfo << "O(N^2)" << endl;
    outfile << printSorting(v) << endl;
    outfileIndx << 0 << endl;
    outfileComp << comparisons << endl;
    outfileSwap << swaps << endl;
    //Ordenamiento
    for(int i = 1; i < v.size(); i++){
        //Insertando informacion actualizada a los archivos
        outfile << printSorting(v) << endl;
        outfileIndx << i << endl;
        outfileComp << comparisons << endl;
        outfileSwap << swaps << endl;
        comparisons++;
        //¿Es el elemento mayor al elemento anterior?
        if(v[i] < v[i-1]){
            auxIndex = i-1;
            itemSwap(v, i, i-1);
            swaps++;
            outfile << printSorting(v) << endl;
            outfileIndx << auxIndex-2 << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
            comparisons++;
            //Mientras el elemento sea mayor al elemento anterior
            while(v[auxIndex] < v[auxIndex-1]){
                comparisons++;
                itemSwap(v, auxIndex, auxIndex-1);
                swaps++;
                //Insertando informacion actualizada a los archivos
                outfile << printSorting(v) << endl;
                outfileIndx << auxIndex-2 << endl;
                outfileComp << comparisons << endl;
                outfileSwap << swaps << endl;
                auxIndex--;
            }
        }
    }
    //Cierrre de archivos
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
    outfileInfo.close(); 
}

void CocktailSort(vector<int> &v){
    //Declaracion de variables
    bool swaped = true;
    int comparisons = 0;
    int swaps = 0;
    int upperLimit = v.size()-1;
    int lowerLimit = 0;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    ofstream outfileInfo;
    //Abriendo los archivos
    outfileInfo.open("Info.txt");
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    //Insertando informacion en los archivos
    outfileInfo << "Cocktail Sort" << endl;
    outfileInfo << "O(N^2)" << endl;
    outfile << printSorting(v) << endl;
    outfileIndx << 0 << endl;
    outfileComp << comparisons << endl;
    outfileSwap << swaps << endl;
    //Ordenamiento
    while(swaped){
        swaped = false;
        //Direccion izquierda a derecha
        for(int j = lowerLimit; j < upperLimit; j++){
            comparisons++;
            //Insertando informacion actualizada a los archivos
            outfile << printSorting(v) << endl;
            outfileIndx << j+1 << endl;
            outfileComp << comparisons << endl; 
            outfileSwap << swaps << endl;
            //¿Es el elemento mayor al elemento siguiente?
            if(v[j] > v[j+1]){
                itemSwap(v, j, j+1);
                swaped = true;
                swaps++;
                //Insertando informacion actualizada a los archivos
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
        //Direccion de derecha a izquierda
        for(int k = upperLimit; k > lowerLimit; k--){
            comparisons++;
            //Insertando informacion actualizada a los archivos
            outfile << printSorting(v) << endl;
            outfileIndx << k-1 << endl;
            outfileComp << comparisons << endl;
            outfileSwap << swaps << endl;
            //¿Es el elemento menor que el elemento anterior?
            if(v[k] < v[k-1]){
                itemSwap(v,k,k-1);
                swaped = true;
                swaps++;
                //Insertando informacion actualizada a los archivos
                outfile << printSorting(v) << endl;
                outfileIndx << k-1 << endl;
                outfileComp << comparisons << endl;
                outfileSwap << swaps << endl;
            }
        }
        lowerLimit++;
    }
    //Cierre de archivos
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
    outfileInfo.close(); 
}

void BogoSort(vector<int>& v, minstd_rand0& rng){
    //Declaracion de variables
    int comparisons = 0;
    int swaps = 0;
    ofstream outfile;
    ofstream outfileIndx;
    ofstream outfileSwap;
    ofstream outfileComp;
    ofstream outfileInfo;
    //Preparacion de los archivos
    outfileInfo.open("Info.txt");
    outfile.open("Sorting.txt");
    outfileIndx.open("Index.txt");
    outfileSwap.open("Swaps.txt");
    outfileComp.open("Comparisons.txt");
    //Imprimiendo en los archivos informacion importante
    outfileInfo << "Bogo Sort" << endl;
    outfileInfo << "O(N*N!)" << endl;
    outfile << printSorting(v) << endl;
    outfileIndx << 0 << endl;
    outfileComp << comparisons << endl;
    outfileSwap << swaps << endl;
    //Ordenamiento
    //Mientras no este ordenado
    while(!isSorted(v)){
        //Intercambiar elementos aleatoriamente
        shuffle(v, rng);
        swaps++;
        //Insertando informacion actualizada a los archivos
        outfile << printSorting(v) << endl;
        outfileComp << 0 << endl;
        outfileIndx << -1 << endl;
        outfileSwap << swaps << endl;
    }
    //Cierre de archivos
    outfile.close();
    outfileIndx.close();
    outfileSwap.close();
    outfileComp.close();
    outfileInfo.close(); 
}

void MaxHeapSort(vector<int> &v){
  //Declaracion de variables
  int comparisons = 0;
  int swaps = 0;
  ofstream outfile;
  ofstream outfileIndx;
  ofstream outfileSwap;
  ofstream outfileComp;
  ofstream outfileInfo;
  //Abriendo archivos
  outfileInfo.open("Info.txt");
  outfile.open("Sorting.txt");
  outfileIndx.open("Index.txt");
  outfileSwap.open("Swaps.txt");
  outfileComp.open("Comparisons.txt");
  //Insertando informacion importante
  outfileInfo << "Max Heap Sort" << endl;
  outfileInfo << "O(N*logN)" << endl;
  outfile << printSorting(v) << endl;
  outfileIndx << 0 << endl;
  outfileComp << comparisons << endl;
  outfileSwap << swaps << endl;
  //Ordenamiento
  for(int i = v.size()/2-1; i >= 0; i--){
    outfileIndx  << -1 << endl;
    //Organizar la estructura en un heap con el elemento mas grande como raiz
    MaxHeapify(v, v.size(), i, swaps, comparisons, outfile, outfileSwap, outfileComp, outfileIndx);
  }
  //Intercambiando la raiz del heap con el ultimo elemento
  for(int j = v.size()-1; j >= 0; j--){
    itemSwap(v, 0, j);
    swaps++;
    //Insertando informacion actualizada a los archivos
    outfileSwap << swaps << endl;
    outfile << printSorting(v) << endl;
    outfileIndx << -1 << endl;
    //Hacer el proceso de heap nuevamente
    MaxHeapify(v, j, 0, swaps, comparisons, outfile, outfileSwap, outfileComp, outfileIndx);
  }
  //Cierre de archivos
  outfile.close();
  outfileIndx.close();
  outfileSwap.close();
  outfileComp.close();
  outfileInfo.close(); 
}

void MinHeapSort(vector<int> &v){
  //Declaracion de variables
  int comparisons = 0;
  int swaps = 0;
  ofstream outfile;
  ofstream outfileIndx;
  ofstream outfileSwap;
  ofstream outfileComp;
  ofstream outfileInfo;
  //Abriendo archivos
  outfileInfo.open("Info.txt");
  outfile.open("Sorting.txt");
  outfileIndx.open("Index.txt");
  outfileSwap.open("Swaps.txt");
  outfileComp.open("Comparisons.txt");
  //Imprimiendo informacion en los archivos
  outfileInfo << "Min Heap Sort" << endl;
  outfileInfo << "O(N*logN)" << endl;
  outfile << printSorting(v) << endl;
  outfileIndx << 0 << endl;
  outfileComp << comparisons << endl;
  outfileSwap << swaps << endl;
  //Ordenamiento
  for(int i = v.size()/2; i >= 0; i--){
    outfileIndx  << -1 << endl;
    //Ordenando la escturctura como un heap con el menor elemento como raiz
    MinHeapify(v, v.size(), i, swaps, comparisons, outfile, outfileSwap, outfileComp, outfileIndx);
  }
  //Intercambiar elemento de la raiz con el ultimo elemento
  for(int j = v.size()-1; j >= 0; j--){
    itemSwap(v, 0, j);
    swaps++;
    //Insertando informacion actualizada a los archivos
    outfileSwap << swaps << endl;
    outfile << printSorting(v) << endl;
    outfileIndx << -1 << endl;
    //Realizar el proceso de heap nuevamente
    MinHeapify(v, j, 0, swaps, comparisons, outfile, outfileSwap, outfileComp, outfileIndx);
  }
  //Invertir el orden de los elementos
  for(int k = 0; k < v.size()/2; k++){
    itemSwap(v, k, v.size()-1-k);
    swaps++;
    outfile << printSorting(v) << endl;
    outfileSwap << swaps << endl;
    outfileIndx << -1 << endl;
  }
  //Cierre de archivos
  outfile.close();
  outfileIndx.close();
  outfileSwap.close();
  outfileComp.close();
  outfileInfo.close(); 
}

void CountingSort(vector<int> &v){
  //Declaracion de variables
  int comparisons = 0;
  int swaps = 0;
  int count = 0;
  int auxIdx = 0;
  ofstream outfile;
  ofstream outfileIndx;
  ofstream outfileSwap;
  ofstream outfileComp;
  ofstream outfileInfo;
  //Abriendo archivos
  outfileInfo.open("Info.txt");
  outfile.open("Sorting.txt");
  outfileIndx.open("Index.txt");
  outfileSwap.open("Swaps.txt");
  outfileComp.open("Comparisons.txt");
  //Informacion importante en los archivos
  outfileInfo << "Counting Sort" << endl;
  outfileInfo << "O(N+K)" << endl;
  outfile << printSorting(v) << endl;
  outfileIndx << 0 << endl;
  outfileComp << comparisons << endl;
  outfileSwap << swaps << endl;
  //Ordenamiento
  int max;
  int min;
  min = max = v[0];
  //Primer barrido, busqueda de maximo y minimo elemento
  for(int i = 0; i < v.size(); i++){
    //Insertando informacion actualizada a los archivos
    outfile << printSorting(v) << endl;
    outfileIndx << i << endl;
    outfileSwap << 0 << endl;
    outfileComp << -1 << endl;
    if(v[i] < min)
      min = v[i];
    if(v[i] > max)
      max = v[i];
  }
  //Vector auxliar
  vector<int> aux(v.size()+1, 0);
  //Segundo barrido, conteo de elementos
  for(int j = 0; j < v.size(); j++){
    //Insertando informacion actualizada a los archivos
    outfile << printSorting(v) << endl;
    outfileIndx << j << endl;
    outfileSwap << 0 << endl;
    outfileComp << -1 << endl;
    aux[v[j]] += 1;
  }
  //Llenar el vector original con la cantidad de veces que esta cada elemento
  while(count < v.size()){
    while(aux[auxIdx] != 0){
      v[count] = auxIdx;
      count++;
      aux[auxIdx] -= 1;
      //Insertando informacion actualizada a los archivos
      outfile << printSorting(v) << endl;
      outfileIndx << count << endl;
      outfileSwap << 0 << endl;
      outfileComp << -1 << endl;
    }
    auxIdx++;
    outfileSwap << 0 << endl;
    outfileComp << -1 << endl;
  }
  //Cierre de archivos
  outfile.close();
  outfileIndx.close();
  outfileSwap.close();
  outfileComp.close();
  outfileInfo.close(); 
}

void OddEvenSort(vector<int> &v){
  //Declaracion de variables
  int comparisons = 0;
  int swaps = 0;
  bool sorted = false;
  ofstream outfile;
  ofstream outfileIndx;
  ofstream outfileSwap;
  ofstream outfileComp;
  ofstream outfileInfo;
  //Apertura de archivos
  outfileInfo.open("Info.txt");
  outfile.open("Sorting.txt");
  outfileIndx.open("Index.txt");
  outfileSwap.open("Swaps.txt");
  outfileComp.open("Comparisons.txt");
  //Informacion para los archivos
  outfileInfo << "Odd Even Sort" << endl;
  outfileInfo << "O(N^2)" << endl;
  outfile << printSorting(v) << endl;
  outfileIndx << 0 << endl;
  outfileComp << comparisons << endl;
  outfileSwap << swaps << endl;
  //Ordenamiento
  while(!sorted){
    sorted = true;
    //Fase Impar, solo se revisan los indices impares y su siguiente elemento
    for(int j = 1; j < v.size()-2; j += 2){
      comparisons++;
      //Insertando informacion actualizada a los archivos
      outfile << printSorting(v) << endl;
      outfileComp << comparisons << endl;
      outfileIndx << j+1 << endl;
      outfileSwap << swaps << endl;
      //Si el elemento es mayor al siguiente
      if(v[j] > v[j+1]){
        itemSwap(v, j, j+1);
        swaps++;
        sorted = false;
      }
      //Insertando informacion actualizada a los archivos
      outfile << printSorting(v) << endl;
      outfileComp << comparisons << endl;
      outfileIndx << j+1 << endl;
      outfileSwap << swaps << endl;
    }
    //Fase par, solo se revisan los indices pares junto a su siguiente elemento
    for(int k = 0; k < v.size()-2; k += 2){
      comparisons++;
      //Insertando informacion actualizada a los archivos
      outfile << printSorting(v) << endl;
      outfileComp << comparisons << endl;
      outfileIndx << k+1 << endl;
      outfileSwap << swaps << endl;
      //¿Es el elemento mayor al siguietne?
      if(v[k] > v[k+1]){
        itemSwap(v, k, k+1);
        swaps++;
        sorted = false;
      }
      //Insertando informacion actualizada a los archivos
      outfile << printSorting(v) << endl;
      outfileComp << comparisons << endl;
      outfileIndx << k+1 << endl;
      outfileSwap << swaps << endl;
    }
  }
  //Cierre de archivos
  outfile.close();
  outfileIndx.close();
  outfileSwap.close();
  outfileComp.close();
  outfileInfo.close();     
}


void GnomeSort(vector<int> &v){
  //Declaracion de variables
  int index = 0;
  int comparisons = 0;
  int swaps = 0;
  ofstream outfile;
  ofstream outfileIndx;
  ofstream outfileSwap;
  ofstream outfileComp;
  ofstream outfileInfo;
  //Abriendo archivos
  outfileInfo.open("Info.txt");
  outfile.open("Sorting.txt");
  outfileIndx.open("Index.txt");
  outfileSwap.open("Swaps.txt");
  outfileComp.open("Comparisons.txt");
  //Informacion importante
  outfileInfo << "Gnome Sort" << endl;
  outfileInfo << "O(N^2)" << endl;
  outfile << printSorting(v) << endl;
  outfileIndx << index-1 << endl;
  outfileComp << comparisons << endl;
  outfileSwap << swaps << endl;
  //Ordenamiento
  while(index < v.size()){ 
    //Comenzar a revisar los elementos
    if(index == 0){
      index++; 
      //Insertando informacion actualizada a los archivos
      outfile << printSorting(v) << endl;
      outfileComp << comparisons << endl;
      outfileIndx << index-1 << endl;
      outfileSwap << swaps << endl;
    }
    comparisons++;
    //Si el elemento es mayor al anterior, seguir avanzando 
    if(v[index] >= v[index - 1]){ 
      index++;
      //Insertando informacion actualizada a los archivos 
      outfile << printSorting(v) << endl;
      outfileComp << comparisons << endl;
      outfileIndx << index-1 << endl;
      outfileSwap << swaps << endl;
    //Si no lo es, intercambiar y revisar los indices anteriores
    }else{ 
      itemSwap(v, index, index - 1);
      swaps++; 
      index--;
      //Insertando informacion actualizada a los archivos
      outfile << printSorting(v) << endl;
      outfileComp << comparisons << endl;
      outfileIndx << index-1 << endl;
      outfileSwap << swaps << endl; 
    } 
  }
  //Cierre de archivos
  outfile.close();
  outfileIndx.close();
  outfileSwap.close();
  outfileComp.close();
  outfileInfo.close(); 
}

