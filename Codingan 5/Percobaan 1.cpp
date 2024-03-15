#include <iostream>
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

    void createnode(int value) {
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
};

int main() {
    list obj;
    int data;

    obj.createnode(2);
    obj.createnode(4);
    obj.createnode(6);
    obj.createnode(8);
    obj.createnode(10);

    cout << ">>>MENYISIPKAN SEBAGAI SIMPUL UJUNG(AWAL) DARI LINKED LIST<<<\n";
    cout << "\n";
    cout << "Tampilkan semua nilai : ";
    obj.display();
    cout << "\n----------------------------------" << endl;

    cout << "\nMasukkan nilai yang ingin disisipkan di awal linked list : ";
    cin >> data;

    obj.insert_start(data);
    cout << "\nLinked list nilai setelah penyisipan di awal : ";
    obj.display();

    return 0;
}
