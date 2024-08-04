#include <iostream>

using namespace std;

void MenaraHanoi(int n, char dariTiang, char keTiang, char tiangBantu) {
    if (n == 0) {
        return;
    }
    MenaraHanoi(n - 1, dariTiang, tiangBantu, keTiang);
    cout << "Pindahkan disc " << n << " dari tiang " << dariTiang << " ke tiang " << keTiang << endl;
    MenaraHanoi(n - 1, tiangBantu, keTiang, dariTiang);
}

int main() {
    cout << "Masukkan jumlah disc yang ingin anda jadikan tantangan dalam puzzle ini\n";
    int m;
    cout << "Jumlah disc: ";
    cin >> m;
    cout << endl;
    int n = m;
    MenaraHanoi(n, 'A', 'C', 'B');
    return 0;
}

