#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 17

int Partition(int arr[], int p, int r) {
    int pivot = arr[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void QuickSort(int arr[], int p, int r) {
    if (p < r) {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}

int main() {
    int data_awal[MAX], data_urut[MAX];
    int i;

    srand(time(0));

    cout << ">>>>>>>>>>-----------------------------------------------------------"
            "------<<<<<<<<<<" << endl;
    cout << ">>>>>>>>>>           Program Pengurutan Quick Sort Secara Descending       "
            "<<<<<<<<<<" << endl;
    cout << ">>>>>>>>>>---------------------------------------------------------"
            "--------<<<<<<<<<<" << endl;
    cout << " \n";
    cout << "Data acak (sebelum pengurutan): \n"
         << endl;
    cout << " \n";
    cout << "-------------------------------------------------------------------"
            "------------------"
         << endl;
    cout << "|";
    for (i = 0; i < MAX; i++) {
        data_awal[i] = rand() % 100 + 1;
        cout << " " << data_awal[i] << " |";
    }
    cout << "\n-------------------------------------------------------------------"
            "------------------"
         << endl;

    cout << "\n\nData setelah pengurutan descending : \n\n"
         << endl;
    cout << "\n-------------------------------------------------------------------"
            "------------------"
         << endl;
    cout << "|";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    QuickSort(data_urut, 0, MAX - 1);
    for (i = 0; i < MAX; i++)
        cout << " " << data_urut[i] << " |";
    cout << "\n-------------------------------------------------------------------"
            "------------------"
         << endl;

    return 0;
}

