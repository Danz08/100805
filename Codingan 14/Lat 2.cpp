#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {
    char kata1, kata2, kata3, kata4, kata5, kata6;
    int hasil1, hasil2, hasil3, hasil4, hasil5, hasil6, hasil7, hasil8, hasil9, hasil10, hasil11, hasil12, hasil13, hasil14, hasil15, x;

    cout << "===================================================================================================\n";
    cout << "|| PROGRAM MEREPRESENTASIKAN MATRIKS MENGGUNAKAN ALGORITMA WARHSALL UNTUK MENCARI RUTE TERPENDEK ||\n";
    cout << "===================================================================================================\n";
    cout << "\n****Graf 6 simpul****\n";
    cout << "Simpul Pertama : "; cin >> kata1;
    cout << "Simpul Kedua : "; cin >> kata2;
    cout << "Simpul Ketiga : "; cin >> kata3;
    cout << "Simpul Keempat : "; cin >> kata4;
    cout << "Simpul Kelima : "; cin >> kata5;
    cout << "Simpul Keenam : "; cin >> kata6;

    cout << "Sisi-sisi simpulnya adalah : ";
    cout << kata1 << kata2 << ",";
    cout << kata1 << kata3 << ",";
    cout << kata1 << kata4 << ",";
    cout << kata1 << kata5 << ",";
    cout << kata1 << kata6 << ",";
    cout << kata2 << kata3 << ",";
    cout << kata2 << kata4 << ",";
    cout << kata2 << kata5 << ",";
    cout << kata2 << kata6 << ",";
    cout << kata3 << kata4 << ",";
    cout << kata3 << kata5 << ",";
    cout << kata3 << kata6 << ",";
    cout << kata4 << kata5 << ",";
    cout << kata4 << kata6 << ",";
    cout << kata5 << kata6 << endl;

    cout << "\n=====================================================" << endl;
    cout << "Jarak " << kata1 << " ke " << kata2 << " : "; cin >> hasil1;
    cout << "Jarak " << kata1 << " ke " << kata3 << " : "; cin >> hasil2;
    cout << "Jarak " << kata1 << " ke " << kata4 << " : "; cin >> hasil3;
    cout << "Jarak " << kata1 << " ke " << kata5 << " : "; cin >> hasil4;
    cout << "Jarak " << kata1 << " ke " << kata6 << " : "; cin >> hasil5;
    cout << "Jarak " << kata2 << " ke " << kata3 << " : "; cin >> hasil6;
    cout << "Jarak " << kata2 << " ke " << kata4 << " : "; cin >> hasil7;
    cout << "Jarak " << kata2 << " ke " << kata5 << " : "; cin >> hasil8;
    cout << "Jarak " << kata2 << " ke " << kata6 << " : "; cin >> hasil9;
    cout << "Jarak " << kata3 << " ke " << kata4 << " : "; cin >> hasil10;
    cout << "Jarak " << kata3 << " ke " << kata5 << " : "; cin >> hasil11;
    cout << "Jarak " << kata3 << " ke " << kata6 << " : "; cin >> hasil12;
    cout << "Jarak " << kata4 << " ke " << kata5 << " : "; cin >> hasil13;
    cout << "Jarak " << kata4 << " ke " << kata6 << " : "; cin >> hasil14;
    cout << "Jarak " << kata5 << " ke " << kata6 << " : "; cin >> hasil15;

    cout << "=====================================================" << endl;
    cout << "Maka, Panjang Jarak Pada Graf Totalnya = " << hasil1 + hasil2 + hasil3 + hasil4 + hasil5 + hasil6 + hasil7 + hasil8 + hasil9 + hasil10 + hasil11 + hasil12 + hasil13 + hasil14 + hasil15 << endl << endl;
    cout << "=====================================================" << endl;
    cout << "^^^^^Pilihan Cara alternatif^^^^^ \n";
    cout << "1. AD\n";
    cout << "2. CB\n";
    cout << "Silahkan Ketik Pilihan Cara Alternatif Anda = "; cin >> x;

    if (x == 1) {
        cout << "Alternatif ke-1: " << kata1 << kata2 << kata3 << kata4 << kata5 << kata6 << " = " << hasil1 + hasil2 + hasil3 + hasil4 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-2: " << kata1 << kata2 << kata4 << kata5 << kata6 << " = " << hasil1 + hasil2 + hasil4 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-3: " << kata1 << kata3 << kata4 << kata5 << kata6 << " = " << hasil1 + hasil3 + hasil4 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-4: " << kata1 << kata2 << kata4 << kata6 << " = " << hasil1 + hasil2 + hasil4 + hasil6 << endl;
        cout << "Alternatif ke-5: " << kata1 << kata3 << kata5 << kata6 << " = " << hasil1 + hasil3 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-6: " << kata1 << kata3 << kata2 << kata4 << kata5 << kata6 << " = " << hasil1 + hasil2 + hasil3 + hasil4 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-7: " << kata1 << kata4 << " = " << hasil1 + hasil4 << " ((ini merupakan jalur terpendek)) " << endl << endl;
    }
    else if (x == 2) {
        cout << "Alternatif ke-1: " << kata3 << kata6 << kata5 << kata4 << kata1 << kata2 << " = " << hasil1 + hasil2 + hasil3 + hasil4 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-2: " << kata3 << kata5 << kata6 << kata1 << kata2 << " = " << hasil1 + hasil2 + hasil3 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-3: " << kata3 << kata5 << kata6 << kata4 << kata2 << " = " << hasil5 + hasil2 + hasil3 + hasil4 + hasil6 << endl;
        cout << "Alternatif ke-4: " << kata3 << kata5 << kata4 << kata2 << " = " << hasil5 + hasil2 + hasil3 + hasil4 << endl;
        cout << "Alternatif ke-5: " << kata3 << kata4 << kata2 << " = " << hasil2 + hasil3 + hasil4 << endl;
        cout << "Alternatif ke-6: " << kata3 << kata1 << kata2 << " = " << hasil1 + hasil2 + hasil3 << endl;
        cout << "Alternatif ke-7: " << kata3 << kata2 << " = " << hasil3 + hasil2 << " ((ini merupakan jalur terpendek)) " << endl << endl;
    }

    getch();
    return 0;
}

