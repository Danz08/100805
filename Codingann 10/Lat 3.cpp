#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 15

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
    for (i = 0; i < MAX; i++) {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 - 2;
        cout << data_awal[i] << " ";
    }

    cout << "\n\nSetelah pengurutan secara ascending : \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    InsertionSortAscending(data_urut);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";

    cout << "\n\nSetelah pengurutan secara descending : \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    InsertionSortDescending(data_urut);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";

    return 0;
}

