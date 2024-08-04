#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 10

int Data[MAX];
int count = 0;

int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "\nPerbandingan yang dilakukan sebanyak " << count << " kali";
            return i;
        } else
            count++;
    }
    return -1; // Return -1 if not found
}

int main() {
    clock_t t;

    int index;
    cout << "=======================================================================================\n";
    cout << "|| PROGRAM MENGHITUNG JUMLAH PERBANDINGAN METODE SEQUENTIAL SEARCH DAN BINARY SEARCH ||\n";
    cout << "=======================================================================================\n";
    
    cout << "\nDATA : ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % MAX;
        cout << " " << Data[i];
    }

    int length = sizeof(Data) / sizeof(Data[0]);
    int Kunci;
    cout << "\nKunci : ";
    cin >> Kunci;

    t = clock();
    index = search(Data, length, Kunci);
    t = clock() - t;

    if (index == -1)
        cout << "Data tidak ditemukan";
    else
        cout << "\nData ditemukan pada indeks " << index << endl;

    double time_taken = double(t) / CLOCKS_PER_SEC;
    cout << "Time : " << time_taken << " seconds" << endl;

    return 0;
}

