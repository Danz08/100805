#include <iostream>
#include <algorithm> 
#include <ctime>     
#define MAX 10
using namespace std;


int binary(int arr[], int x, int y, int z) {
    while (x <= y) {
        if (y >= x) {
            int m = x + (y - x) / 2;

            if (arr[m] == z)
                return m;
            else if (arr[m] > z)
                return binary(arr, x, m - 1, z);
            else
                return binary(arr, m + 1, y, z);
        }
    }

    return -1;
}

int main() {
    int Data[MAX];

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 10 + 1; 
    }

    
    random_shuffle(Data, Data + MAX);
    
    cout << "============================================================\n";
    cout << "|| IMPLEMENTASI METHOD BINARY SEARCH DENGAN CARA REKURSIF ||\n";
    cout << "============================================================\n";

    cout << "\nData : ";
    for (int i = 0; i < MAX; i++) {
        cout << " " << Data[i];
    }

    int length = sizeof(Data) / sizeof(Data[0]);
    int Kunci;
    cout << "\nKunci : ";
    cin >> Kunci;

    int ketemu = binary(Data, 0, length - 1, Kunci);

    if (ketemu == -1)
        cout << "Data tidak ditemukan";
    else
        cout << "Data ditemukan pada posisi " << ketemu << endl;

    return 0;
}

