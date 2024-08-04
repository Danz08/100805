#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 10

int Data[MAX];

int SequentialRekursif(int a[], int size, int value) {
    if (size == 0)
        return -1;
    else if (value == a[size - 1])
        return size - 1;
    else
        return SequentialRekursif(a, size - 1, value);
}

int main() {
    srand(time(NULL));

    int index;
    cout << "~~ ~~" << endl;
    cout << "Method Sequential Search secara Rekursif " << endl;
    cout << "~~ ~~" << endl;
    cout << "DATA : ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % MAX;
        cout << " " << Data[i];
    }

    int Kunci;
    cout << "\nKunci : ";
    cin >> Kunci;

    index = SequentialRekursif(Data, MAX, Kunci);

    if (index == -1 || index >= MAX)
        cout << "\nData tidak ditemukan" << endl;
    else
        cout << "Data ditemukan pada indeks " << index << endl;

    return 0;
}

