#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int element) {
    Node* newItem = new Node{element, NULL};
    if (rear == NULL) {
        front = rear = newItem;
        return;
    }
    rear->next = newItem;
    rear = newItem;
}

void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong." << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete temp;
}

void printQueue() {
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;
    int element;
    while (true) {
        cout << "=== Program Implementasi Single Linked List (FIFO) ===" << endl;
        cout << "\t1. Enqueue (Tambahkan ke Antrian)" << endl;
        cout << "\t2. Dequeue (Hapus dari Antrian)" << endl;
        cout << "\t3. Lihat Antrian" << endl;
        cout << "\t4. Keluar" << endl;
        cout << "Masukkan pilihan = ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Masukkan nilai node = ";
                cin >> element;
                enqueue(element);
                printQueue();
                break;
            case 2:
                dequeue();
                printQueue();
                break;
            case 3:
                cout << "Isi Antrian: ";
                printQueue();
                break;
            case 4:
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    }
    return 0;
}

