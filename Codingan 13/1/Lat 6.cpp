#include <iostream>
#define MAX_SIZE 100
using namespace std;

int* insertX(int n, int arr[], int x, int pos) {
    n++;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    return arr;
}

int main() {
    cout << "=========================================\n";
    cout << "|| PROGRAM MENYISIP DAN MENGHAPUS DATA ||\n";
    cout << "=========================================\n";

    int data[MAX_SIZE];
    int size, key, found, elemen, pilihan, position, i;

    cout << "\nInput total array yang diinginkan : ";
    cin >> size;

    cout << "Masukkan elemen untuk array : " << endl;
    for (int x = 0; x < size; x++) {
        cout << "Elemen ke " << x + 1 << " : ";
		cin >> data[x];
    }
    cout << endl;

    cout << "MENU :" << endl;
    cout << "1. Sisipkan data sebelum data kunci" << endl;
    cout << "2. Sisipkan data sesudah data kunci" << endl;
    cout << "3. Hapus" << endl;

    cout << "\nPilihan : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "\nMasukkan data di sebelum : ";
            cin >> key;

            found = 0;
            for (i = 0; i < size; i++) {
                if (data[i] == key) {
                    found = 1;
                    elemen = i;
                    break;
                }
            }

            if (found == 1) {
                cout << "Data yang ingin dimasukkan : ";
                cin >> elemen;
                cout << endl;
                cout << "Hasil :" << endl;

                insertX(size, data, elemen, i + 1);

                for (int z = 0; z < size + 1; z++)
                    cout << data[z] << " ";
                cout << endl;
            } else {
                cout << "Data tidak ditemukan" << endl;
            }
            break;

        case 2:
            cout << "\nMasukkan data di setelah : ";
            cin >> key;

            found = 0;
            for (i = 0; i < size; i++) {
                if (data[i] == key) {
                    found = 1;
                    elemen = i;
                    break;
                }
            }

            if (found == 1) {
                cout << "Data yang ingin dimasukkan : ";
                cin >> elemen;
                cout << endl;
                cout << "Hasil :" << endl;

                insertX(size, data, elemen, i + 2);

                for (int z = 0; z < size + 1; z++)
                    cout << data[z] << " ";
                cout << endl;
            } else {
                cout << "Data tidak ditemukan" << endl;
            }
            break;

        case 3:
            cout << "Masukkan posisi elemen yang ingin kamu hapus: ";
            cin >> position;

            if (position >= size + 1) {
                cout << "Data tidak ditemukan." << endl;
            } else {
                for (int c = position - 1; c < size - 1; c++) {
                    data[c] = data[c + 1];
                }
                cout << "Data : ";
                for (int c = 0; c < size - 1; c++) {
                    cout << data[c] << " ";
                }
                cout << endl;
            }
            break;
    }
    return 0;
}

