#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


ifstream f("shell.in");

int v[100000000];

void shellSort(int n){

int gap, i, j, k;

for(gap = n/2; gap > 0; gap /= 2){   // cand gap va fi 0, vectorul va fi sortat

        for(i = gap; i < n; i++){

            k = 0;

            for(j = i; j >= gap && k == 0; j -= gap){

                if(v[j - gap] > v[j])

                    swap(v[j - gap], v[j]);

                else

                    k = 1;            // daca se interschimba, trebuie sa verificam si mai departe

            }
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

        shellSort(n);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << j << ". N = " << n << " numere, Max = " << maxim << ". Shellsort time: " << duration.count() << " microseconds. ";

        verif(n);


    }


    return 0;
}
