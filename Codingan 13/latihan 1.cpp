#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 10

using namespace std;

int Data[MAX];
int count = 0;

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Perbandingan tersebut dilakukan sebanyak : " << count << " kali";
            return i;
        } else 
            count++;
    }
}

int main() {
    clock_t t;
    int i, index;

    cout << "======================================================\n";
    cout << "|| PROGRAM MENGHITUNG JUMLAH PERBANDINGAN METODE SEQUENTIAL SEARCH DAN BINARY SEARCH ||\n";
    cout << "======================================================\n";

    cout << "Input Data Anda :";
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % MAX;
        cout << " " << Data[i];
    }

    int length = sizeof(Data) / sizeof(Data[0]);
    int Kunci;

    cout << "\nKunci : ";
    cin >> Kunci;

    cout << "======================================================\n";
    t = clock();
    index = search(Data, length, Kunci);
    t = clock() - t;

    if (index >= MAX)
        cout << "Maaf, data yang anda inginkan tidak ditemukan!";
    else
        cout << "\nData Ditemukan Pada Indeks Ke-" << index << endl;

    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    cout << "Waktu : " << time_taken << endl;
}

