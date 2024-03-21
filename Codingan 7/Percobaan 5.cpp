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
    while (temp->next != start) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}

void searchList(struct Node* start, int search) {
    struct Node *temp = start;
    int count = 0, flag = 0;
    if (temp == NULL) {
        cout << "List kosong" << endl;
        return;
    }
    while (temp->next != start) {
        count++;
        if (temp->data == search) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (temp->data == search) {
        count++;
        flag = 1;
    }
    if (flag == 1)
        cout << "\nNilai " << search << " ditemukan pada posisi " << count << endl;
    else
        cout << "\nNilai " << search << " tidak ditemukan" << endl;
}

void deleteNode(struct Node** start, int key) {
    if (*start == NULL)
        return;
    struct Node *curr = *start, *prev_ = NULL;
    while (curr->data != key) {
        if (curr->next == *start) {
            cout << "Nilai " << key << " tidak ditemukan dalam list." << endl;
            return;
        }
        prev_ = curr;
        curr = curr->next;
    }
    if (curr->next == curr) {
        *start = NULL;
        delete curr;
        return;
    }
    if (curr == *start) {
        prev_ = (*start)->prev;
        *start = (*start)->next;
        prev_->next = *start;
        (*start)->prev = prev_;
    } else if (curr->next == *start) {
        prev_->next = *start;
        (*start)->prev = prev_;
        delete curr;
    } else {
        struct Node *temp = curr->next;
        prev_->next = temp;
        temp->prev = prev_;
        delete curr;
    }
    cout << "\nNilai " << key << " berhasil dihapus dari list." << endl;
}

int main() {
    struct Node* start = NULL;
    int numNodes, value, searchData, deleteData, choice;
    
    cout << "Masukkan jumlah simpul yang ingin dimasukkan: ";
    cin >> numNodes;
    cout << "Masukkan nilai simpul-simpul secara berurutan:\n";
    for (int i = 0; i < numNodes; ++i) {
        cin >> value;
        insertNodeAtBeginning(&start, value);
    }
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Menyisipkan nilai simpul awal\n";
        cout << "2. Menampilkan nilai\n";
        cout << "3. Mencari nilai tertentu\n";
        cout << "4. Menghapus nilai\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai yang ingin disisipkan di awal: ";
                cin >> value;
                insertNodeAtBeginning(&start, value);
                break;
            case 2:
                cout << "Data adalah: ";
                displayList(start);
                break;
            case 3:
                cout << "\nMasukkan nilai yang ingin dicari: ";
                cin >> searchData;
                searchList(start, searchData);
                break;
            case 4:
                cout << "\nMasukkan nilai yang ingin dihapus: ";
                cin >> deleteData;
                deleteNode(&start, deleteData);
                break;
            case 5:
                cout << "Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}

