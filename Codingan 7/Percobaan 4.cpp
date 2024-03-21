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
    while (temp->next != start) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}

void deleteFirstNode(struct Node** start) {
    if (*start == NULL)
        return;
    struct Node *temp = *start;
    if ((*start)->next == *start) {
        *start = NULL;
    } else {
        (*start)->prev->next = (*start)->next;
        (*start)->next->prev = (*start)->prev;
        *start = (*start)->next;
    }
    delete temp;
}

void deleteMiddleNode(struct Node** start) {
    if (*start == NULL)
        return;
    struct Node *curr = *start, *prev_ = NULL;
    // Cari simpul tengah
    struct Node *slow_ptr = *start;
    struct Node *fast_ptr = *start;
    while (fast_ptr->next != *start && fast_ptr->next->next != *start) {
        fast_ptr = fast_ptr->next->next;
        prev_ = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    // Hapus simpul tengah
    if (slow_ptr == *start) {
        *start = (*start)->next;
    }
    prev_->next = slow_ptr->next;
    slow_ptr->next->prev = prev_;
    delete slow_ptr;
}

void deleteLastNode(struct Node** start) {
    if (*start == NULL)
        return;
    struct Node *temp = *start;
    if ((*start)->next == *start) {
        *start = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete temp;
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

    int choice;
    cout << "\nPilihan menu penghapusan simpul:\n";
    cout << "1. Hapus simpul awal\n";
    cout << "2. Hapus simpul tengah\n";
    cout << "3. Hapus simpul akhir\n";
    cout << "Masukkan pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            deleteFirstNode(&start);
            cout << "\nData setelah penghapusan simpul awal: ";
            break;
        case 2:
            deleteMiddleNode(&start);
            cout << "\nData setelah penghapusan simpul tengah: ";
            break;
        case 3:
            deleteLastNode(&start);
            cout << "\nData setelah penghapusan simpul akhir: ";
            break;
        default:
            cout << "\nPilihan tidak valid!";
            return 0;
    }

    displayList(start);

    return 0;
}

