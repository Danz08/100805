#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 20

using namespace std;

void InsertionSortAscending(int arr[]) {
    int i, j, key;
    for (i = 1; i < MAX; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSortDescending(int arr[]) {
    int i, j, key;
    for (i = 1; i < MAX; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int data_awal[MAX], data_urut[MAX];
    int i;

    cout << "Sebelum pengurutan : \n";
    srand(time(NULL));
    for (i = 0; i < MAX; i++) {
        data_awal[i] = rand() % 100 + 1;
        cout << data_awal[i] << " ";
    }
    cout << endl;

    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];

    cout << "\nSetelah pengurutan secara Ascending: \n";
    InsertionSortAscending(data_urut);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";

    cout << "\n\nSetelah pengurutan secara Descending: \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    InsertionSortDescending(data_urut);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";

    return 0;
}

