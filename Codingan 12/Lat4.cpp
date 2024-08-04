#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void insertionSort(int arr[], int n, bool ascending) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
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

void selectionSort(int arr[], int n, bool ascending) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (ascending) {
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            } else {
                if (arr[j] > arr[min_idx])
                    min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void bubbleSort(int arr[], int n, bool ascending) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ascending) {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            } else {
                if (arr[j] < arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortFlag(int arr[], int n, bool ascending) {
    int i, j;
    bool did_swap = true;
    for (i = 0; i < n - 1 && did_swap; i++) {
        did_swap = false;
        for (j = 0; j < n - i - 1; j++) {
            if (ascending) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    did_swap = true;
                }
            } else {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    did_swap = true;
                }
            }
        }
    }
}

void shellSort(int arr[], int n, bool ascending) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            if (ascending) {
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
            } else {
                for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                    arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (ascending) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        } else {
            if (arr[j] > pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

void merge(int arr[], int left, int median, int right, bool ascending) {
    int temp[right - left + 1];
    int i = left, j = median + 1, k = 0;
    if (ascending) {
        while (i <= median && j <= right) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
    } else {
        while (i <= median && j <= right) {
            if (arr[i] >= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
    }
    while (i <= median)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

void mergeSort(int arr[], int left, int right, bool ascending) {
    if (left < right) {
        int median = left + (right - left) / 2;
        mergeSort(arr, left, median, ascending);
        mergeSort(arr, median + 1, right, ascending);
        merge(arr, left, median, right, ascending);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    const int SIZE = 20;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100 + 1;
    int choice, order;
    cout << ">>>>>>>>>>-----------------------------------------------------------"
            "------<<<<<<<<<<" << endl;
    cout << ">>>>>>>>>>           Program Pengurutan Algoritma Sorting                  "
            "<<<<<<<<<<" << endl;
    cout << ">>>>>>>>>>---------------------------------------------------------"
            "--------<<<<<<<<<<" << endl;
  cout << " \n";
    cout << "1. Insertion" << endl;
    cout << "2. Selection" << endl;
    cout << "3. Bubble" << endl;
    cout << "4. Bubble dengan Flag" << endl;
    cout << "5. Shell" << endl;
    cout << "6. Quick" << endl;
    cout << "7. Merge" << endl;
    cout << "Pilihan: ";
    cin >> choice;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "Pilihan: ";
    cin >> order;
    bool ascending = (order == 1);
    cout << "\nData sebelum pengurutan:" << endl;
    printArray(arr, SIZE);
    switch (choice) {
        case 1:
            insertionSort(arr, SIZE, ascending);
            break;
        case 2:
            selectionSort(arr, SIZE, ascending);
            break;
        case 3:
            bubbleSort(arr, SIZE, ascending);
            break;
        case 4:
            bubbleSortFlag(arr, SIZE, ascending);
            break;
        case 5:
            shellSort(arr, SIZE, ascending);
            break;
        case 6:
            quickSort(arr, 0, SIZE - 1, ascending);
            break;
        case 7:
            mergeSort(arr, 0, SIZE - 1, ascending);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return 0;
    }
    cout << "\nData setelah pengurutan:" << endl;
    printArray(arr, SIZE);
    return 0;
}

