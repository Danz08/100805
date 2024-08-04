#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 500000;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int size, bool ascending) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        if (ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (ascending) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            } else {
                if (arr[j] > arr[minIndex]) {
                    minIndex = j;
                }
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void bubbleSort(int arr[], int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (ascending) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            } else {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void bubbleSortFlag(int arr[], int size) {
    int i = 0, temp;
    bool did_swap = true;
    while (i < size - 1 && did_swap) {
        did_swap = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                did_swap = true;
            }
        }
        i++;
        if (did_swap == false) break;
    }
}

void shellSort(int arr[], int size, bool ascending) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            if (ascending) {
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            } else {
                for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (ascending) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } else {
            if (arr[j] > pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pivot = partition(arr, low, high, ascending);
        quickSort(arr, low, pivot - 1, ascending);
        quickSort(arr, pivot + 1, high, ascending);
    }
}

void merge(int arr[], int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    if (ascending) {
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    } else {
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, bool ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

int main() {
    const int SIZE = 10000;
    int arr[SIZE];
    time_t k1, k2;
    generateRandomArray(arr, SIZE);
    cout << "ALGORITMA SORTING\n";
    cout << "1. Insertion\n";
    cout << "2. Selection\n";
    cout << "3. Bubble\n";
    cout << "4. Bubble dengan Flag\n";
    cout << "5. Shell\n";
    cout << "6. Quick\n";
    cout << "7. Merge\n";
    cout << "Pilihan: ";
    int algorithm;
    cin >> algorithm;
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Pilihan: ";
    int order;
    cin >> order;
    bool ascending;
    if (order == 1) {
        ascending = true;
    } else {
        ascending = false;
    }
    cout << "\nData sebelum diurutkan:\n";
    printArray(arr, SIZE);
    time(&k1);
    switch (algorithm) {
        case 1:
            cout << "\nPengurutan menggunakan Insertion Sort\n";
            insertionSort(arr, SIZE, ascending);
            break;
        case 2:
            cout << "\nPengurutan menggunakan Selection Sort\n";
            selectionSort(arr, SIZE, ascending);
            break;
        case 3:
            cout << "\nPengurutan menggunakan Bubble Sort\n";
            bubbleSort(arr, SIZE, ascending);
            break;
        case 4:
            cout << "\nPengurutan menggunakan Bubble Sort dengan Flag\n";
            bubbleSortFlag(arr, SIZE);
            break;
        case 5:
            cout << "\nPengurutan menggunakan Shell Sort\n";
            shellSort(arr, SIZE, ascending);
            break;
        case 6:
            cout << "\nPengurutan menggunakan Quick Sort\n";
            quickSort(arr, 0, SIZE - 1, ascending);
            break;
        case 7:
            cout << "\nPengurutan menggunakan Merge Sort\n";
            mergeSort(arr, 0, SIZE - 1, ascending);
            break;
        default:
            cout << "\nPilihan tidak valid\n";
            return 0;
    }
    cout << "Data setelah diurutkan:\n";
    printArray(arr, SIZE);
    time(&k2);
    printf("\nWaktu = %ld\n", (k2 - k1) * 1000);
    return 0;
}

