#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertNodeAtBeginning(struct Node** start, int value) {
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
    *start = new_node;
}

void displayList(struct Node* start) {
    struct Node *temp = start;
    if (start == NULL) {
        cout << "List kosong" << endl;
        return;
    }
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
}

int main() {
    struct Node* start = NULL;
    int numNodes, value;
    cout << "Masukkan jumlah simpul yang ingin dimasukkan: ";
    cin >> numNodes;
    cout << "Masukkan nilai simpul-simpul secara berurutan:\n";
    for (int i = 0; i < numNodes; ++i) {
        cin >> value;
        insertNodeAtBeginning(&start, value);
    }
    
    cout << "Data adalah: ";
    displayList(start);

    return 0;
}

