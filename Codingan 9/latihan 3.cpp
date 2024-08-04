#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int data[13] = {2, 5, 8, 10, 14, 32, 35, 41, 67, 88, 90, 101, 109};

void selection_sort() {
    int temp, min, i, j;

    for(i = 0; i < 13; i++) {
        min = i;
        for(j = i + 1; j < 13; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binary_search(int cari) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 12;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if(b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}

int main() {
    cout << "\t   'BINARY SEARCH'" << endl;
    cout << "\t=====================" << endl;
    cout << "\nData           : ";
    
    for(int x = 0; x < 13; x++)
        cout << data[x] << " ";
    cout << endl;

    int cari;
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> cari;

    cout << "\nData diurutkan : ";
    
    selection_sort();
    
    for(int x = 0; x < 13; x++)
        cout << setw(3) << data[x] << " ";

    cout << endl;
    
    binary_search(cari);

    return 0;
}

