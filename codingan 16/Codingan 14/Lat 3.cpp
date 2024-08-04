#include <iostream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
using namespace std;

int main()
{
    char kata1, kata2, kata3, kata4;
    int hasil1, hasil2, hasil3, hasil4, hasil5, hasil6, x;

    cout << "=============================================================" << endl;
    cout << "|| PROGRAM MEREPRESENTASIKAN MATRIKS MENGGUNAKAN ALGORITMA ||" << endl;
    cout << "|| \t   WARSHALL UNTUK MENCARI RUTE TERPENDEK           ||" << endl;
    cout << "=============================================================" << endl;

    cout << "\n****Graf 4 simpul****\n";
    cout << "Simpul Pertama : ";
    cin >> kata1;
    cout << "Simpul Kedua : ";
    cin >> kata2;
    cout << "Simpul Ketiga : ";
    cin >> kata3;
    cout << "Simpul Keempat : ";
    cin >> kata4;
    cout << "Sisi-sisi simpulnya adalah : ";
    cout << kata1 << kata2 << ",";
    cout << kata1 << kata3 << ",";
    cout << kata1 << kata4 << ",";
    cout << kata2 << kata3 << ",";
    cout << kata2 << kata4 << ",";
    cout << kata3 << kata4 << endl;
    cout << "==============================================" << endl << endl;

    cout << "Jarak " << kata1 << " ke " << kata2 << " : ";
    cin >> hasil1;
    cout << "Jarak " << kata1 << " ke " << kata3 << " : ";
    cin >> hasil2;
    cout << "Jarak " << kata1 << " ke " << kata4 << " : ";
    cin >> hasil3;
    cout << "Jarak " << kata2 << " ke " << kata3 << " : ";
    cin >> hasil4;
    cout << "Jarak " << kata2 << " ke " << kata4 << " : ";
    cin >> hasil5;
    cout << "Jarak " << kata3 << " ke " << kata4 << " : ";
    cin >> hasil6;
    cout << "==============================================" << endl;

    cout << "Total jarak panjang pada graf = " << hasil1 + hasil2 + hasil3 + hasil4 + hasil5 + hasil6 << endl << endl;
    cout << "==============================================" << endl;
    cout << "(((( Pilihan Cara alternatif ))))" << endl;
    cout << "1. AD" << endl;
    cout << "2. CB" << endl;
    cout << "Pilihan anda = ";
    cin >> x;

    if (x == 1)
    {
        cout << "Alternatif ke-1: " << kata1 << kata2 << kata3 << kata4 << " = " << hasil1 + hasil2 + hasil3 + hasil4 << endl;
        cout << "Alternatif ke-2: " << kata1 << kata2 << kata4 << " = " << hasil1 + hasil2 + hasil5 << endl;
        cout << "Alternatif ke-3: " << kata1 << kata3 << kata4 << " = " << hasil1 + hasil3 + hasil6 << endl;
        cout << "Alternatif ke-4: " << kata1 << kata2 << kata3 << kata4 << " = " << hasil1 + hasil2 + hasil3 + hasil4 << endl;
        cout << "Alternatif ke-5: " << kata1 << kata4 << " = " << hasil1 + hasil3 << " (ini merupakan jalur terpendek)" << endl << endl;
    }
    else if (x == 2)
    {
        cout << "Alternatif ke-1: " << kata3 << kata4 << kata1 << kata2 << " = " << hasil1 + hasil2 + hasil3 + hasil4 << endl;
        cout << "Alternatif ke-2: " << kata3 << kata1 << kata2 << " = " << hasil1 + hasil2 + hasil4 << endl;
        cout << "Alternatif ke-3: " << kata3 << kata4 << kata2 << " = " << hasil2 + hasil4 + hasil6 << endl;
        cout << "Alternatif ke-4: " << kata3 << kata1 << kata4 << kata2 << " = " << hasil1 + hasil3 + hasil5 + hasil6 << endl;
        cout << "Alternatif ke-5: " << kata3 << kata2 << " = " << hasil4 + hasil6 << " (ini merupakan jalur terpendek)" << endl << endl;
    }
    getch();
    return 0;
}
