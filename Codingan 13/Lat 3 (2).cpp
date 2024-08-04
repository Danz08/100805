#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 10

int Data[MAX];

int search(int arr[], int l, int n, int x) {
    if (n < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[n] == x)
        return n;
    return search(arr, l + 1, n - 1, x);
}

int main() {
	cout << "================================================================\n";
    cout << "|| IMPLEMENTASI METHOD SEQUENTIAL SEARCH DENGAN CARA REKURSIF ||\n";
    cout << "================================================================\n";
    cout << "\nDATA : ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % MAX;
        cout << " " << Data[i];
    }

    int length = sizeof(Data) / sizeof(Data[0]);
    int Kunci;
    cout << "\nKunci : ";
    cin >> Kunci;

    int ketemu = search(Data, 0, length - 1, Kunci);

    if (ketemu == -1)
        cout << "Data tidak ditemukan";
    else
        cout << "Data ditemukan pada posisi " << ketemu << endl;

    return 0;
}

