#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;


ifstream f("teste.in");

int v[100000000];

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

        sort(v, v+n);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << j << ". N = " << n << " numere, Max = " << maxim << ". Timp sortare implicita: " << duration.count() << " microseconds. ";

        verif(n);


    }


    return 0;
}
