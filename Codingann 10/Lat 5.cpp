#include <iostream>
#include <cstring>

using namespace std;

int main() {
    struct Data_Mahasiswa {
        char nama[20];
        int kelas;
    };

    Data_Mahasiswa DatMahasiswa[25];
    char Tempnama[20];
    int Tempkelas, i, j, k, N, y;

    cout << "Masukan banyaknya data yang akan diinput : ";
    cin >> N;
    cout << "\nSilahkan Input Data: \n";
    for (i = 0; i < N; i++) {
        cout << "Data ke-" << i + 1 << "\n";
        cout << "nama   : ";
        cin >> DatMahasiswa[i].nama;
        cout << "kelas  : ";
        cin >> DatMahasiswa[i].kelas;
        cout << "\n";
    }

    cout << "\nProses Insertion Sort Secara Ascending";
    for (k = 0; k < N; k++) {
        cout << "\n";
        strcpy(Tempnama, DatMahasiswa[k].nama);
        Tempkelas = DatMahasiswa[k].kelas;
        j = k;
        while (strcmp(Tempnama, DatMahasiswa[j - 1].nama) < 0 && j > 0) {
            strcpy(DatMahasiswa[j].nama, DatMahasiswa[j - 1].nama);
            DatMahasiswa[j].kelas = DatMahasiswa[j - 1].kelas;
            j--;
        }
        strcpy(DatMahasiswa[j].nama, Tempnama);
        DatMahasiswa[j].kelas = Tempkelas;
        for (y = 0; y < N; y++)
            cout << DatMahasiswa[y].nama << " ";
    }

    cout << "\n\nSetelah Disorting Secara Ascending\n";
    for (i = 0; i < N; i++) {
        cout << "\nData ke- " << i + 1;
        cout << "\nnama   : " << DatMahasiswa[i].nama;
        cout << "\nkelas  : " << DatMahasiswa[i].kelas << endl;
    }

    return 0;
}

