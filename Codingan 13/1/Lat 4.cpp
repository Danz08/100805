#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX 10

int Data[MAX];

int Partition(int arr[], int p, int r) {
    int pivot = arr[p];
    int i = p;
    int j = r;
    while (i <= j) {
        while (pivot < arr[j])
            j--;
        while (pivot > arr[i])
            i++;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
            i++;
        } else
            return j;
    }
    return j;
}

void QuickSort(int arr[], int p, int r) {
    int q;
    if (p < r) {
        q = Partition(arr, p, r);
        QuickSort(arr, p, q);
        QuickSort(arr, q + 1, r);
    }
}

int BinarySearchRecursive(int arr[], int num, int first, int last) {
    if (first > last)
        return -1;
    else {
        int mid = (first + last) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            return BinarySearchRecursive(arr, num, first, mid - 1);
        else
            return BinarySearchRecursive(arr, num, mid + 1, last);
    }
}

int main() {
    srand(time(NULL));

    int index;
    cout << "~~ ~~" << endl;
    cout << "Metode Binary Search secara Rekursif " << endl;
    cout << "~~ ~~" << endl;
    cout << "DATA : ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % MAX;
    }
    QuickSort(Data, 0, MAX - 1);
    for (int i = 0; i < MAX; i++) {
        cout << " " << Data[i];
    }

    int Kunci;
    cout << "\nKunci : ";
    cin >> Kunci;

    index = BinarySearchRecursive(Data, Kunci, 0, MAX - 1);

    if (index == -1 || index >= MAX)
        cout << "\nData tidak ditemukan" << endl;
    else
        cout << "Data ditemukan pada indeks " << index << endl;

    return 0;
}

