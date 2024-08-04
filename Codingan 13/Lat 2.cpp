#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 10

using namespace std;

int Data[MAX];
int count1 = 0;
int count2 = 0;

int Partition(int arr[], int p, int r) {
    int i, j;
    int pivot, temp;
    pivot = arr[p];
    i = p;
    j = r;
    while (i <= j) {
        while (pivot < arr[j]) j--;
        while (pivot > arr[i]) i++;
        if (i < j) {
            temp = arr[i];
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

int BinarySearch(int x) {
    int L = 0, R = MAX - 1, m;
    bool ketemu = false;
    QuickSort(Data, 0, MAX - 1);
    while ((L <= R) && (!ketemu)) {
        m = (L + R) / 2;
        if (Data[m] == x)
            ketemu = true;
        else if (x < Data[m]) {
            R = m - 1;
            count2++;
        } else {
            L = m + 1;
            count2++;
        }
    }
    if (ketemu) return m;
    else return -1;
}

int SequentialSearch(int x) {
    int i = 0;
    bool ketemu = false;
    while ((!ketemu) && (i < MAX)) {
        if (Data[i] == x)
            ketemu = true;
        else
            i++;
        count1++;
    }
    if (ketemu) return i;
    else return -1;
}

void printTime(clock_t t) {
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    int hours = time_taken / 3600;
    int minutes = (int(time_taken) % 3600) / 60;
    int seconds = int(time_taken) % 60;
    cout << hours << " jam " << minutes << " menit " << seconds << " detik";
}

int main(int argc, char const *argv[]) {
    cout << "============================================================================================\n";
    cout << "|| BANDINGKAN KINERJA PENCARIAN SEQUENTIAL SEARCH DAN BINARY SEARCH BERDASARKAN LATIHAN 1 ||\n";
    cout << "============================================================================================\n";

    clock_t t, p;
    int i, indexS, indexB; 
    cout << "Data :";
    for (int i = 0; i < MAX; i++) {
        srand(time(NULL) * (i + 1));
        Data[i] = rand() % MAX;
        cout << " " << Data[i];
    }

    int length = sizeof(Data) / sizeof(Data[0]);
    int Kunci;
    cout << "\nKunci : "; 
    cin >> Kunci;

    t = clock();
    indexS = SequentialSearch(Kunci); 
    t = clock() - t;

    p = clock();
    indexB = BinarySearch(Kunci); 
    p = clock() - p;

    cout << "\n";
    cout << "=======================\n";
    cout << "|| SEQUENTIAL SEARCH ||\n";
    cout << "=======================\n";

    if (indexS >= MAX || indexB == -1)
        cout << "Maaf, Data Tidak Ditemukan!" << endl;
    else
        cout << "Data Ditemukan Pada Indeks Ke-" << indexS << endl;
    cout << "Waktu : ";
    printTime(t);
    cout << endl;
    cout << "Jumlah Perbandingan : " << count1 << endl;
    cout << "\n";
    cout << "===================\n";
    cout << "|| BINARY SEARCH ||\n";
    cout << "===================\n";

    if (indexB >= MAX || indexB == -1)
        cout << "Maaf, Data Tidak Ditemukan!" << endl;
    else
        cout << "Data Ditemukan Pada Indeks Ke-" << indexB << endl;
    cout << "Waktu : ";
    printTime(p);
    cout << endl;
    cout << "Jumlah Perbandingan : " << count2;
    
    return 0;
}

