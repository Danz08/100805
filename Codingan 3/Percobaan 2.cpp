#include <iostream>
using namespace std;

#define MAX 10

class Queue {
private:
    int Item[MAX];
    int Front;
    int Rear;
    int Count;
public:
    Queue() {
        Front = Rear = -1;
        Count = 0;
    }

    void Tambah(int item) {
        if (Rear == MAX - 1) {
            cout << "Antrian Penuh" << endl;
            cout << "------------------------" << endl;
            return;
        }
        Rear++;
        Item[Rear] = item;
        Count++;
        if (Front == -1)
            Front = 0;
    }

    int Hapus() {
        int data;
        if (Front == -1) {
            cout << "Antrian Kosong" << endl;
            return -1;
        }
        data = Item[Front];
        Count--;
        if (Front == Rear)
            Front = Rear = -1;
        else
            Front++;
        return data;
    }

    void Tampil() {
        for (int i = 0; i < Count; i++)
            cout << "Data : " << Item[i] << endl;
    }
};

int main() {
    Queue q;
    int data;

    q.Tambah(11);
    q.Tambah(12);
    q.Tambah(13);
    q.Tambah(14);
    q.Tambah(15);
    q.Tambah(16);
    q.Tambah(17);
    q.Tambah(18);
    q.Tambah(19);
    q.Tambah(20);
    q.Tambah(21);

    q.Tampil();

    data = q.Hapus();
    cout << "------------------------" << endl;
    cout << "Hapus Item = " << data << endl;

    data = q.Hapus();
    cout << "Hapus Item = " << data << endl;

    data = q.Hapus();
    cout << "Hapus Item = " << data << endl;

    cout << "------------------------" << endl;

    q.Tampil();

    return 0;
}

