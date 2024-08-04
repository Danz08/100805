#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 20

using namespace std;

void SelectionSortAscending(int arr[]) {
    int i, j, temp, min, min_id;
    i = 0;
    while (i < MAX - 1) {
        min_id = i;
        min = arr[i];
        for (j = i + 1; j < MAX; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_id = j;
            }
        }
        temp = arr[min_id];
        arr[min_id] = arr[i];
        arr[i] = temp;
        i++;
    }
}

void SelectionSortDescending(int arr[]) {
    int i, j, temp, max, max_id;
    i = 0;
    while (i < MAX - 1) {
        max_id = i;
        max = arr[i];
        for (j = i + 1; j < MAX; j++) {
            if (arr[j] > max) {
                max = arr[j];
                max_id = j;
            }
        }
        temp = arr[max_id];
        arr[max_id] = arr[i];
        arr[i] = temp;
        i++;
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
    SelectionSortAscending(data_urut);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";

    cout << "\n\nSetelah pengurutan secara descending : \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    SelectionSortDescending(data_urut);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";

    return 0;
}

