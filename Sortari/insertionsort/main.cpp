#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


ifstream f("teste.in");

int v[100000000];

void insertionSort(int n){

    int i, j, k;

    for(i = 1; i < n; i++){

        k = 0;

        for(j = i; j > 0 && k == 0; j--){

            if(v[j - 1] > v[j])

                swap(v[j - 1], v[j]);

            else

                k = 1;

            }

}
}

void verif(unsigned long long n){

unsigned long long i;

for(i = 0; i < n-1; i++){
    if(v[i] > v[i+1]){
        cout<<"Vectorul este sortat gresit."<<'\n';
        return;
}
}

cout<<"Vectorul este sortat corect."<<'\n';

}

int main()
{int n, i, maxim, nrTeste, j;

    f>>nrTeste;

    for(j = 1; j <= nrTeste; j++){

        f >> n >> maxim;

        for(i = 0; i < n; i++)
            v[i]=rand()%maxim;


        auto start = high_resolution_clock::now();

        insertionSort(n);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << j << ". N = " << n << " numere, Max = " << maxim << ". Insertion sort time: " << duration.count() << " microseconds. ";

        verif(n);


    }


    return 0;
}
