#include <iostream>
#include <queue>

#define jumlahMahasiswa 6

using namespace std;

struct Mahasiswa {
    string nrp, nama;
    int nilai;
};

struct compare {
    bool operator()(Mahasiswa const& m1, Mahasiswa const& m2) {
        return m1.nilai < m2.nilai;
    }
};

Mahasiswa set(string nrp, string nama, int nilai) {
    Mahasiswa m;
    m.nama = nama;
    m.nrp = nrp;
    m.nilai = nilai;
    return m;
}

void Tampil(priority_queue<Mahasiswa, vector<Mahasiswa>, compare> &pq, int &j) {
    Mahasiswa m = pq.top();
    cout << (j++) << ". NRP: " << m.nrp << "\t| Nama: " << m.nama << "\t| Nilai: " << m.nilai << endl;
    pq.pop();
}

int main() {
    priority_queue<Mahasiswa, vector<Mahasiswa>, compare> pq;
    Mahasiswa ms[jumlahMahasiswa];
    system("cls");
    Mahasiswa m = set("01", "Andi", 70);
    ms[0] = m;
    m = set("02", "Budi", 85);
    ms[1] = m;
    m = set("03", "Candra", 80);
    ms[2] = m;
    m = set("04", "Didik", 90);
    ms[3] = m;
    m = set("05", "Edi", 85);
    ms[4] = m;
    m = set("06", "Fanda", 75);
    ms[5] = m;
    cout << "=================\nPriority Queue\n==================\n";
    cout << ">> Queue Awal :\n";
    for (int i = 0; i < jumlahMahasiswa; i++)
        cout << (i + 1) << ". NRP: " << ms[i].nrp << "\t| Nama: " << ms[i].nama << "\t| Nilai: " << ms[i].nilai << endl;
    cout << "\n>> Priority Queue :\n";
    int j = 1;
    for (int i = 0; i < 6; i++) {
        pq.push(ms[i]);
        if (i == 2 || i == 5)
            Tampil(pq, j);
        if (i == 4) {
            Tampil(pq, j);
            Tampil(pq, j);
        }
    }
    cout << endl;
    system("pause");
    return 0;
}

