#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void insertValues(string input) {
    stringstream ss(input);
    int value;
    while (ss >> value) {
        Node* newItem = new Node{value, NULL, tail};
        if (tail != NULL) tail->next = newItem;
        tail = newItem;
        if (head == NULL) head = newItem;
    }
}

void insertFirst(int element) {
    Node* newItem = new Node{element, head, NULL};
    if (head != NULL) head->prev = newItem;
    head = newItem;
    if (tail == NULL) tail = newItem;
}

void insertLast(int element) {
    Node* newItem = new Node{element, NULL, tail};
    if (tail != NULL) tail->next = newItem;
    tail = newItem;
    if (head == NULL) head = newItem;
}

void insertAfter(int old, int element) {
    Node* temp = head;
    while (temp != NULL && temp->value != old) temp = temp->next;
    if (temp == NULL) {
        cout << "Element tidak ditemukan." << endl;
        return;
    }
    Node* newItem = new Node{element, temp->next, temp};
    if (temp->next != NULL) temp->next->prev = newItem;
    temp->next = newItem;
    if (temp == tail) tail = newItem;
}

void insertBefore(int old, int element) {
    Node* temp = head;
    while (temp != NULL && temp->value != old) temp = temp->next;
    if (temp == NULL) {
        cout << "Element tidak ditemukan." << endl;
        return;
    }
    Node* newItem = new Node{element, temp, temp->prev};
    if (temp->prev != NULL) temp->prev->next = newItem;
    temp->prev = newItem;
    if (temp == head) head = newItem;
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
}

void deleteLast() {
    if (tail == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    delete temp;
}

void deleteItem(int element) {
    Node* temp = head;
    while (temp != NULL && temp->value != element) temp = temp->next;
    if (temp == NULL) {
        cout << "Element tidak ditemukan." << endl;
        return;
    }
    if (temp == head) {
        deleteFirst();
    } else if (temp == tail) {
        deleteLast();
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;
    string input;
    int element;
    int old, newitem;
    cout << "Masukkan nilai node : ";
    getline(cin, input);
    while (true) {
        insertValues(input);
        cout << "=== Program Implementasi Double Linked List ===" << endl;
        cout << "\t1. Insert di awal" << endl;
        cout << "\t2. Insert di akhir" << endl;
        cout << "\t3. Insert setelah" << endl;
        cout << "\t4. Insert sebelum" << endl;
        cout << "\t5. Hapus awal" << endl;
        cout << "\t6. Hapus akhir" << endl;
        cout << "\t7. Hapus Node" << endl;
        cout << "\t8. Lihat node" << endl;
        cout << "Masukkan pilihan = ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Masukkan node = ";
                cin >> element;
                insertFirst(element);
                printList();
                break;
            case 2:
                cout << "Masukkan node = ";
                cin >> element;
                insertLast(element);
                printList();
                break;
            case 3:
                cout << "Node setelah item = ";
                cin >> old;
                cout << "Masukkan node baru = ";
                cin >> newitem;
                insertAfter(old, newitem);
                printList();
                break;
            case 4:
                cout << "Node sebelum item = ";
                cin >> old;
                cout << "Masukkan node baru = ";
                cin >> newitem;
                insertBefore(old, newitem);
                printList();
                break;
            case 5:
                deleteFirst();
                printList();
                break;
            case 6:
                deleteLast();
                printList();
                break;
            case 7:
                cout << "Masukkan node yang akan dihapus = ";
                cin >> element;
                deleteItem(element);
                printList();
                break;
            case 8:
                printList();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        head = NULL;
        tail = NULL;
        cin.ignore();
    }
    return 0;
}

