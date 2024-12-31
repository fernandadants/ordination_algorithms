#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

int *selection_sort(int *arr, int n){

    for(int i = 0; i < n-1; i++){

        int min = i;

        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        
    }

    return arr;
}


int main(int argc, char **argv){

    // Lendo dados da instância 
    ifstream arquivo(argv[1]);
    vector <int> data;
    int n;
    while(arquivo >> n){
        data.push_back(n);
    }

    auto start = chrono::high_resolution_clock::now();

    // Ordenando os dados com o insertion sort
    selection_sort(&data[0], data.size());

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    
    cout << "Tempo de execucao: " << duration << " ms" << endl;
    /* cout << "Dados ordenados: " << endl;

    // Imprimindo os dados ordenados
    for (int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    } */
}