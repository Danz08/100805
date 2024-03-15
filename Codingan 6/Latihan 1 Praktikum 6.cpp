#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct simpul tsimpul;
struct simpul {
    int info;
    tsimpul *next;
};
tsimpul *awal = NULL, *akhir = NULL, *data, *hapus, *b1, *b2;

void muncul() {
    b1 = awal;
    cout << "\nDATA ==>  ";
    while (b1 != NULL) {
        cout << b1->info << "  ";
        b1 = b1->next;
    }
}

void tambah_awal(string input) {
    stringstream ss(input);
    int angka;
    while (ss >> angka) {
        data = new simpul;
        data->info = angka;
        data->next = NULL;
        if (awal == NULL) {
            awal = akhir = data;
        } else {
            data->next = awal;
            awal = data;
        }
    }
}

void tambah_akhir(int x) {
    data = new simpul;
    data->info = x;
    data->next = NULL;
    if (awal == NULL) {
        awal = akhir = data;
    } else {
        akhir->next = data;
        akhir = data;
    }
}

void hapus_awal() {
    if (awal == NULL) {
        cout << "Maaf....List Kosong!!!\n";
    } else if (awal == akhir) {
        hapus = awal;
        awal = NULL;
        akhir = NULL;
        delete hapus;
    } else {
        hapus = awal;
        awal = awal->next;
        delete hapus;
    }
}

int main() {
    int pilih, n;
    string input;
    char lagi;
    do {
        cout << "==============================================\n";
        cout << "||         PROGRAM SINGLE LINKED LIST        ||\n";
        cout << "==============================================\n";
        muncul();
        cout << "\n\n1. Tambah Data di Awal";
        cout << "\n2. Tambah Data di Akhir";
        cout << "\n3. Hapus Data dari Awal";
        cout << "\n==============================================";
        cout << "\nPilihan Anda : ";
        cin >> pilih;
        cout << "==============================================\n";
        switch (pilih) {
            case 1:
                cout << "Masukkan Data (pisahkan angka dengan spasi): ";
                cin.ignore(); // Menggunakan ignore untuk membersihkan newline character
                getline(cin, input);
                tambah_awal(input);
                break;
            case 2:
                cout << "Masukkan Data: ";
                cin >> n;
                tambah_akhir(n);
                break;
            case 3:
                hapus_awal();
                break;
        }
        cout << "Lagi (y/t)? ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');
    return 0;
}

