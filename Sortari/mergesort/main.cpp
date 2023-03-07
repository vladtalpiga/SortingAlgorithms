#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

ifstream f("merge.in");

unsigned long long v[100000000], rez[100000000];

void mmerge(int st, int dr){

    int mij = (st + dr)/2, i = st, j = mij + 1, k = 0;

    while(i <= mij && j <= dr){

        if(v[i] < v[j]){

            rez[k] = v[i];
            i++;

        }else{

            rez[k] = v[j];
            j++;

        }

        k++;

    }


    while(i <= mij){

        rez[k] = v[i];
        i++;
        k++;

    }

    while(j <= dr){

        rez[k] = v[j];
        j++;
        k++;

    }

    for(i = st; i <= dr; i++)
        v[i] = rez[i - st];

}

void mergeSort(int st, int dr){

    int mij = (st + dr)/2;

    if(st < dr){

    mergeSort(st, mij);
    mergeSort(mij + 1, dr);

    mmerge(st, dr);

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
{unsigned long long n, i, maxim, nrTeste, j;

    f>>nrTeste;

    for(j = 1; j <= nrTeste; j++){

        f>>n>>maxim;

        for(i = 0; i < n; i++)
            v[i]=rand()%maxim;


        auto start = high_resolution_clock::now();

        mergeSort(0, n - 1);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << j << ". N = " << n << " numere, Max = " << maxim << ". Mergesort time: " << duration.count() << " microseconds. ";

        verif(n);

    }

    return 0;
}
