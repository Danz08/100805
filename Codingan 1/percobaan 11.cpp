#include <iostream>
#include <string> 
using namespace std;

struct dtnilai
{
    string nrp; 
    string nama;
    double nilai;
};

dtnilai data[10]; 
int j = 0;

void tambah_data()
{
    string jawab;
    while (true)
    {
        cout << "NRP: ";
        cin >> data[j].nrp;
        cout << "Nama: ";
        cin >> data[j].nama;
        cout << "Nilai Test: ";
        cin >> data[j].nilai;
        cout << "Ada data lagi(y/t): ";
        cin >> jawab;
        
        if (jawab == "Y" || jawab == "y")
        {
            j++;
            continue;
        }
        else if (jawab == "T" || jawab == "t")
        {
            break;
        }
    }
}

void tampil()
{
    cout << "Data Mahasiswa yang telah diinputkan : " << endl;
    cout << "NRP\tNama\tNilai" << endl;

    for (int i = 0; i <= j; i++)
    {
        cout << data[i].nrp << "\t" << data[i].nama << "\t" << data[i].nilai << endl;
    }
}

int main()
{
    tambah_data();
    tampil();

    return 0;
}
