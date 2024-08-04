#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

#define MAX 10

vector<int> Data(MAX);
int count1 = 0;
int count2 = 0;

int Partition(vector<int>& arr, int p, int r) {
    int pivot = arr[p];
    int i = p;
    int j = r;
    while (i <= j) {
        while (arr[j] > pivot)
            j--;
        while (arr[i] < pivot)
            i++;
        if (i < j) {
            swap(arr[i], arr[j]);
            j--;
            i++;
        } else
            return j;
    }
    return j;
}

void QuickSort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q);
        QuickSort(arr, q + 1, r);
    }
}

int BinarySearch(int x) {
    int L = 0, R = MAX - 1, m;
    bool found = false;
    QuickSort(Data, 0, MAX - 1);
    while ((L <= R) && (!found)) {
        m = (L + R) / 2;
        if (Data[m] == x)
            found = true;
        else if (x < Data[m]) {
            R = m - 1;
            count2++;
        } else {
            L = m + 1;
            count2++;
        }
    }
    if (found)
        return m;
    else
        return -1;
}

int SequentialSearch(int x) {
    bool found = false;
    int i = 0;
    while ((!found) && (i < MAX)) {
        if (Data[i] == x)
            found = true;
        else
            i++;
        count1++;
    }
    if (found)
        return i;
    else
        return -1;
}

int main() {
    clock_t start, end;
    srand(time(NULL));

    cout << "\nDATA : ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % MAX;
        cout << " " << Data[i];
    }

    int Kunci;
    cout << "\nKunci : ";
    cin >> Kunci;

    start = clock();
    int indexS = SequentialSearch(Kunci);
    end = clock();
    double durationS = double(end - start) / CLOCKS_PER_SEC * 1000000; // Microseconds

    cout << "\n-> Sequential search" << endl;
    if (indexS >= MAX)
        cout << "Data tidak ditemukan" << endl;
    else {
        cout << "Data ditemukan pada indeks: " << indexS << endl;
        cout << "Time: " << durationS << " microseconds" << endl;
        cout << "Jumlah perbandingan: " << count1 << endl;
    }

    start = clock();
    int indexB = BinarySearch(Kunci);
    end = clock();
    double durationB = double(end - start) / CLOCKS_PER_SEC * 1000000; // Microseconds

    cout << "\n-> Binary search" << endl;
    if (indexB >= MAX || indexB == -1)
        cout << "Data tidak ditemukan" << endl;
    else {
        cout << "Data ditemukan pada indeks: " << indexB << endl;
        cout << "Time: " << durationB << " microseconds" << endl;
        cout << "Jumlah perbandingan: " << count2 << endl;
    }

    return 0;
}
