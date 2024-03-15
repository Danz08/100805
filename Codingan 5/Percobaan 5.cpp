#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class list {
private:
    node *head, *tail;

public:
    list() {
        head = NULL;
        tail = NULL;
    }

    void tambahsimpul(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insert_start(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insert_end(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void delete_first() {
        if (head == NULL) {
            cout << "Linked list kosong" << endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    void delete_last() {
        if (head == NULL) {
            cout << "Linked list kosong" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        node *current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = NULL;
    }

    void delete_position(int pos) {
        if (head == NULL) {
            cout << "Linked list kosong" << endl;
            return;
        }
        if (pos == 1) {
            delete_first();
            return;
        }
        node *prev = NULL;
        node *current = head;
        int count = 1;
        while (current != NULL && count < pos) {
            prev = current;
            current = current->next;
            count++;
        }
        if (current == NULL) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        prev->next = current->next;
        delete current;
    }

    int cari_node(int value) {
        node *temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1; // Jika tidak ditemukan, kembalikan -1
    }
};

int main() {
    list obj;
    int jumlah_node, data, pilihan, posisi;

    cout << "Masukkan jumlah node yang ingin dimasukkan: ";
    cin >> jumlah_node;

    cout << "Masukkan nilai node:\n";
    for (int i = 0; i < jumlah_node; ++i) {
        cin >> data;
        obj.tambahsimpul(data);
    }

    cout << "\nMenu Operasi Linked List:\n";
    cout << "1. Menyisipkan sebagai simpul ujung (awal) dari linked list.\n";
    cout << "2. Membaca atau menampilkan Linked List.\n";
    cout << "3. Mencari sebuah simpul tertentu.\n";
    cout << "4. Menyisipkan sebagai simpul terakhir.\n";
    cout << "Pilih operasi (1/2/3/4): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "\nMasukkan nilai yang ingin disisipkan di awal linked list: ";
            cin >> data;
            obj.insert_start(data);
            break;
        case 2:
            cout << "\nLinked List:\n";
            obj.display();
            break;
        case 3:
            cout << "\nMasukkan nilai yang ingin dicari: ";
            cin >> data;
            posisi = obj.cari_node(data);
            if (posisi != -1) {
                cout << "Data ditemukan pada simpul ke-" << posisi << "." << endl;
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
            break;
        case 4:
            cout << "\nMasukkan nilai yang ingin disisipkan di akhir linked list: ";
            cin >> data;
            obj.insert_end(data);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    cout << "\nLinked List setelah operasi:\n";
    obj.display();
    cout << endl;

    return 0;
}

