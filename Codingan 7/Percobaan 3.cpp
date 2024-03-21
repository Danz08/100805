#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertNode(struct Node** start, int value) {
    if (*start == NULL) {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    Node *last = (*start)->prev;
    struct Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void displayList(struct Node* start) {
    struct Node *temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
}

int searchList(struct Node* start, int search) {
    struct Node *temp = start;
    int count = 0, position = 0;
    bool found = false;
    
    if (temp == NULL)
        return -1;
    else {
        do {
            count++;
            if (temp->data == search) {
                found = true;
                position = count;
                break;
            }
            temp = temp->next;
        } while (temp != start);
    }
    
    if (found)
        return position;
    else
        return -1;
}

int main() {
    struct Node* start = NULL;
    insertNode(&start, 4);
    insertNode(&start, 5);
    insertNode(&start, 7);
    insertNode(&start, 8);
    insertNode(&start, 6);
    cout << "Data adalah: ";
    displayList(start);

    int searchData;
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> searchData;
    int position = searchList(start, searchData);
    if (position != -1)
        cout << "\nNilai " << searchData << " ditemukan pada posisi " << position << endl;
    else
        cout << "\nNilai " << searchData << " tidak ditemukan" << endl;

    return 0;
}

