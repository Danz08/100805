#include <iostream>
#include <algorithm>
#include <cstdlib>

#define MAX_SIZE 50

using namespace std;

struct Mahasiswa {
    int nim;
    char nama[20];
    int kelas;
};

struct Mahasiswa data[MAX_SIZE];
int j = 0;

void tambah_data() {
    cout << "NIM: ";
    cin >> data[j].nim;
    cout << "Nama: ";
    cin >> data[j].nama;
    cout << "Kelas: ";
    cin >> data[j].kelas;
    j++;
}

void tampil() {
    cout << "======================================\n";
    cout << "Data Mahasiswa yang telah diinputkan :\n";
    cout << "======================================\n";
    cout << "NIM\tNama\tKelas\n";
    for (int i = 0; i < j; i++) {
        cout << data[i].nim << "\t" << data[i].nama << "\t" << data[i].kelas << endl;
    }
}

void AscShellSort(int arr[], int MAX) {
    for (int gap = MAX / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < MAX; i++) {
            int temp = arr[i];
            struct Mahasiswa temp_data = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap].nim > temp; j -= gap) {
                arr[j] = arr[j - gap];
                data[j] = data[j - gap];
            }
            arr[j] = temp;
            data[j] = temp_data;
        }
    }
}

void merge(struct Mahasiswa arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct Mahasiswa L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i].nim <= R[j].nim) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
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

void DescMergeSort(struct Mahasiswa arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    DescMergeSort(arr, l, m);
    DescMergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int MAX;
    cout << "============================================\n";
    cout << "Program Penerapan Shell & Merge Sort\n";
    cout << "Ascending & Descending Sort\n";
    cout << "============================================\n";
    cout << "Berapa banyak data yang ingin anda masukkan: ";
    cin >> MAX;
    cout << "============================================\n";
    cout << "\nMasukkan data mahasiswa: \n\n";
    for (int i = 0; i < MAX; i++) {
        tambah_data();
        cout << endl;
    }
    cout << "============================================\n";
    cout << "Data sebelum diurutkan:\n";
    tampil();
    cout << "============================================\n";

    int data_nim[MAX];
    for (int i = 0; i < MAX; i++) {
        data_nim[i] = data[i].nim;
    }

    int pil;
    cout << "Silahkan pilih aksi yang ingin anda lakukan selanjutnya!\n";
    cout << "1. Lakukan Pengurutan Ascending Shell Sort\n";
    cout << "2. Lakukan Pengurutan Descending Merge Sort\n";
    cout << "3. Keluar\n";
    cout << "============================================\n";
    while (true) {
        cout << "Pilihan Anda: ";
        cin >> pil;
        cout << "============================================\n";
        switch (pil) {
            case 1:
                AscShellSort(data_nim, MAX);
                cout << "Data setelah pengurutan ascending Shell Sort:\n";
                tampil();
                break;
            case 2:
                DescMergeSort(data, 0, MAX - 1);
                cout << "Data setelah pengurutan descending Merge Sort:\n";
                tampil();
                break;
            case 3:
                cout << "Terima kasih!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
        cout << "============================================\n";
    }
    return 0;
}

