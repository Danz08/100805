#include <iostream>

using namespace std;

struct Kompleks {
    double real;
    double imag;
};

Kompleks tambah(Kompleks a, Kompleks b) {
    Kompleks hasil;
    hasil.real = a.real + b.real;
    hasil.imag = a.imag + b.imag;
    return hasil;
}

Kompleks kurang(Kompleks a, Kompleks b) {
    Kompleks hasil;
    hasil.real = a.real - b.real;
    hasil.imag = a.imag - b.imag;
    return hasil;
}

Kompleks kali(Kompleks a, Kompleks b) {
    Kompleks hasil;
    hasil.real = (a.real * b.real) - (a.imag * b.imag);
    hasil.imag = (a.real * b.imag) + (a.imag * b.real);
    return hasil;
}

Kompleks bagi(Kompleks a, Kompleks b) {
    Kompleks hasil;
    hasil.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    hasil.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
    return hasil;
}

int main() {
    Kompleks bil1, bil2, hasil;
    char operasi;

    cout << "Masukkan dua bilangan kompleks : " << endl;
    cout << "---------------------------------" << endl;
    cout << "Pertama (a) : ";
	cin >> bil1.real;
	cout << "Pertama (bi) : ";
	cin >> bil1.imag;

    cout << "\nMasukkan operasi aritmatika" << endl;
	cout << "-----------------------------" << endl;
	cout << "Pilih salah satu (+, -, *, /): ";
    cin >> operasi;

    cout << "\nMasukkan dua bilangan kompleks : " << endl;
    cout << "---------------------------------" << endl;
    cout << "Kedua (c) : ";
    cin >> bil2.real;
	cout << "Kedua (di) : "; 
	cin >> bil2.imag;

    switch (operasi) {
        case '+':
            hasil = tambah(bil1, bil2);
            break;
        case '-':
            hasil = kurang(bil1, bil2);
            break;
        case '*':
            hasil = kali(bil1, bil2);
            break;
        case '/':
            hasil = bagi(bil1, bil2);
            break;
        default:
            cerr << "Operasi tidak valid" << endl;
            return 1;
    }

	cout << "\nHasil operasi : " << hasil.real << " + " << hasil.imag << "i" << endl;
	
    return 0;
}

