#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


ifstream f("teste.in");

int v[100000000], aux[100000000];

int nrMaxim(int n){

    int maxim = v[0], i;

    for(i = 1; i < n; i++)
        if (v[i] > maxim)
            maxim = v[i];

    return maxim;
}


void countingSort(int n, int poz) {

    int vfr[10] = {0}, i;

    for(i = 0; i < n; i++)
        vfr[(v[i] / poz) % 10] ++;

    for(i = 1; i < 10; i++)
        vfr[i] += vfr[i-1];

    for(i = n-1; i >= 0; i--){
        aux[vfr[(v[i] / poz) % 10] - 1] = v[i];
        vfr[(v[i] / poz) % 10] --;
    }

    for (i = 0; i < n; i++)
        v[i] = aux[i];

}

void radixSort(int n){

    int m, poz;

    m = nrMaxim(n);

    for (poz = 1; m / poz > 0; poz *= 10)
        countingSort(n, poz);

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

        radixSort(n);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << j << ". N = " << n << " numere, maxim = " << maxim << ". Radixsort time: " << duration.count() << " microseconds. ";

        verif(n);


    }


    return 0;
}
