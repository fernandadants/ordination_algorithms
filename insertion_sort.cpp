#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

int *insertion_sort(int *arr, int n){

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertion_sort(&data[0], data.size());

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    
    cout << "Tempo de execucao: " << duration << " ms" << endl;
    /* cout << "Dados ordenados: " << endl;

    // Imprimindo os dados ordenados
    for (int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    } */
}