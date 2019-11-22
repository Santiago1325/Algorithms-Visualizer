#include "SortAlgo.hpp"

// ARG 1 = Algoritmo
// ARG 2 = Tipo de estructura -> Con Repeticion 1 / Sin Repeticion  2
// ARG 3 = Orden de estructura -> Ordenado 1 / Random 2 / Invertido 3
// ARG 4 = Elementos de la estructura -> 10 / 15 / 25 / 50 / 100 / 150 / 200 / 250 / 300 ... / 500


int main(int argc, char *argv[]){
	vector<int> v;
	unsigned seed = 1325;
    minstd_rand0 rng(seed);
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    cout << argv[3] << endl;
    cout << argv[4] << endl;
	if(stoi(argv[2]) == 1){
		if(stoi(argv[3]) == 1){
			generate_ordered_vector(v, stoi(argv[4]), rng, false);
		}else if(stoi(argv[3]) == 2){
			generate_vector(v, stoi(argv[4]), rng);
		}else if(stoi(argv[3]) == 3){
			generate_ordered_vector(v, stoi(argv[4]), rng, true);
		}
	}else if(stoi(argv[2]) == 2){
		if(stoi(argv[3]) == 1){
			generate_ordered_even_vector(v, stoi(argv[4]), false);
		}else if(stoi(argv[3]) == 2){
			generate_even_vector(v, stoi(argv[4]),rng);
		}else if(stoi(argv[3]) == 3){
			generate_ordered_even_vector(v, stoi(argv[4]), true);
		}
	}
	if(stoi(argv[1]) == 1){
		BubbleSort(v);
	}else if(stoi(argv[1]) == 2){
		InsertionSort(v);
	}else if(stoi(argv[1]) == 3){
		SelectionSort(v);
	}else if(stoi(argv[1]) == 4){
		CocktailSort(v);
	}else if(stoi(argv[1]) == 5){
		BogoSort(v,rng);
	}else if(stoi(argv[1]) == 6){
		MaxHeapSort(v);
	}else if(stoi(argv[1]) == 7){
		MinHeapSort(v);
	}else if(stoi(argv[1]) == 8){
		CountingSort(v);
	}else if(stoi(argv[1]) == 9){
		OddEvenSort(v);
	}else if(stoi(argv[1]) == 10){
		GnomeSort(v);
	}

    return 0;
}
