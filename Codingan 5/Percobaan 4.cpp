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
};

int main() {
    list obj;
    int data;

    obj.tambahsimpul(2);
    obj.tambahsimpul(4);
    obj.tambahsimpul(6);
    obj.tambahsimpul(8);
    obj.tambahsimpul(10);

    cout << ">>>MENYISIPKAN SEBAGAI SIMPUL TERAKHIR DARI LINKED LIST<<<\n";
    cout << "\n";
    cout << "Tampilkan semua nilai : ";
    obj.display();
    cout << "\n----------------------------------" << endl;

    cout << "\nMasukkan nilai yang ingin disisipkan di akhir linked list : ";
    cin >> data;

    obj.insert_end(data);
    cout << "\nLinked list nilai setelah penyisipan di akhir : ";
    obj.display();

    return 0;
}
