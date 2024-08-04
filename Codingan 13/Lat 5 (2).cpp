#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node *link;
};

node *head = NULL;

void insert(int x) {
    node *temp = new node;
    temp->data = x;
    temp->link = head;
    head = temp;
}

void search() {
    if (head == NULL) {
        cout << "Linked list kosong" << endl;
        return;
    }

    int indeks;
    cout << "Masukkan Indeks: ";
    cin >> indeks;

    node *temp = head;
    int count = 0;

    while (temp != NULL) {
        if (count == indeks) {
            cout << "Elemen (" << indeks << ") Terdapat pada indeks Ke : " << temp->data << endl;
            return;
        }
        count++;
        temp = temp->link;
    }

    cout << "Indeks tidak ditemukan" << endl;
}

int main() {
    int n, x;
    
    cout << "===================================================================\n";
    cout << "|| IMPLEMENTASI METHOD SEQUENTIAL SEARCH DENGAN CARA LINKED LIST ||\n";
    cout << "===================================================================\n";

    cout << "\nMasukkan Jumlah Angka Yang Diinginkan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan Angka ke " << i + 1 << " = ";
        cin >> x;
        insert(x);
    }

    cout << endl;

    search();

    return 0;
}

