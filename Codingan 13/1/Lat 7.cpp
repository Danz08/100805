#include <iostream>
#include <string>

#define MAX_SIZE 100

using namespace std;

struct Karyawan {
    int nip;
    string nama;
    string alamat;
    char goldar[3];
};

Karyawan* insertX(int n, Karyawan arr[], int nip, string nama, string alamat, const char goldar[], int pos) {
    n++;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1].nip = nip;
    arr[pos - 1].nama = nama;
    arr[pos - 1].alamat = alamat;
    arr[pos - 1].goldar[0] = goldar[0]; 
    arr[pos - 1].goldar[1] = goldar[1]; 
    arr[pos - 1].goldar[2] = '\0'; 

    return arr;
}

int findData(int size, Karyawan arr[], int searchNIP) {
    for (int i = 0; i < size; i++) {
        if (arr[i].nip == searchNIP) {
            return i; 
        }
    }
    return -1;
}

void displayData(int size, Karyawan arr[]) {
    cout << "Data yang dimasukkan:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "NIP: " << arr[i].nip << endl;
        cout << "Nama: " << arr[i].nama << endl;
        cout << "Alamat: " << arr[i].alamat << endl;
        cout << "Golongan Darah: " << arr[i].goldar << endl << endl;
    }
}

int main() {
    Karyawan data[MAX_SIZE];
    int size, choice;
    
    cout << "=========================================\n";
    cout << "|| IMPLEMENTASI PENCARIAN DATA PEGAWAI ||\n";
    cout << "=========================================";
    cout << "\nMasukkan jumlah array yang diinginkan: ";
    cin >> size;

    cout << "\nMasukkan data dalam urutan ascending\n";
    for (int i = 0; i < size; i++) {
        cout << "Masukkan NIP: ";
        cin >> data[i].nip;
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, data[i].nama);
        cout << "Masukkan alamat: ";
        getline(cin, data[i].alamat);
        cout << "Masukkan golongan darah: ";
        cin >> data[i].goldar;
        cout << endl;
    }

    displayData(size, data);

    while (true) {
        cout << "~~~ MENU ~~~" << endl;
        cout << "1. Cari data" << endl;
        cout << "2. Masukkan data di sebelum data tertentu" << endl;
        cout << "3. Masukkan data di setelah data tertentu" << endl;
        cout << "4. Hapus data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int searchNIP;
                cout << "Masukkan NIP yang ingin dicari: ";
                cin >> searchNIP;
                int index = findData(size, data, searchNIP);
                if (index != -1) {
                    cout << "Data ditemukan pada indeks: " << index << endl;
                    cout << "Detail Data:" << endl;
                    cout << "NIP: " << data[index].nip << endl;
                    cout << "Nama: " << data[index].nama << endl;
                    cout << "Alamat: " << data[index].alamat << endl;
                    cout << "Golongan Darah: " << data[index].goldar << endl << endl;
                } else {
                    cout << "Data tidak ditemukan." << endl;
                }
                break;
            }
            case 2: {
                int before;
                cout << "Masukkan data baru yang diinginkan!" << endl;
                cout << "NIP: ";
                cin >> data[size].nip;
                cout << "Nama: ";
                cin.ignore();
                getline(cin, data[size].nama);
                cout << "Alamat: ";
                getline(cin, data[size].alamat);
                cout << "Golongan Darah: ";
                cin >> data[size].goldar;
                cout << "Masukkan NIP sebelum data baru: ";
                cin >> before;
                int i;
                for (i = 0; i < size; i++) {
                    if (data[i].nip == before) {
                        break;
                    }
                }
                insertX(size, data, data[size].nip, data[size].nama, data[size].alamat, data[size].goldar, i + 1);
                size++;
                displayData(size, data);
                break;
            }
            case 3: {
                int after;
                cout << "Masukkan data baru yang diinginkan!" << endl;
                cout << "NIP: ";
                cin >> data[size].nip;
                cout << "Nama: ";
                cin.ignore();
                getline(cin, data[size].nama);
                cout << "Alamat: ";
                getline(cin, data[size].alamat);
                cout << "Golongan Darah: ";
                cin >> data[size].goldar;
                cout << "Masukkan NIP setelah data baru: ";
                cin >> after;
                int i;
                for (i = 0; i < size; i++) {
                    if (data[i].nip == after) {
                        break;
                    }
                }
                insertX(size, data, data[size].nip, data[size].nama, data[size].alamat, data[size].goldar, i + 2);
                size++;
                displayData(size, data);
                break;
            }
            case 4: {
                int pos;
                cout << "Masukkan indeks data yang ingin anda hapus: ";
                cin >> pos;
                if (pos >= size + 1 || pos <= 0) {
                    cout << "Gagal dihapus." << endl;
                } else {
                    for (int c = pos - 1; c < size - 1; c++) {
                        data[c] = data[c + 1];
                    }
                    size--;
                    cout << "Data yang tersisa setelah penghapusan:" << endl;
                    displayData(size, data);
                }
                break;
            }
            case 5: {
                cout << "Keluar dari program." << endl;
                return 0;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    }

    return 0;
}

