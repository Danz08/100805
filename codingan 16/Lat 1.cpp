#include <iostream>
#include <conio.h>
using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

Node *pohon = NULL;

void tambah(Node **root, int databaru) {
    if ((*root) == NULL) {
        Node *baru;
        baru = new Node;
        baru->kiri = NULL;
        baru->kanan = NULL;
        baru->data = databaru;
        (*root) = baru;
        cout << "Data Anda Sudah Bertambah!\n" << endl;
    } else if (databaru < (*root)->data)
        tambah(&((*root)->kiri), databaru);
    else if (databaru > (*root)->data)
        tambah(&((*root)->kanan), databaru);
    else if (databaru == (*root)->data)
        cout << "Data Tersebut Sudah Ada!\n" << endl;
}

void preOrder(Node *root) {
    if (root != NULL) {
        if (root->data != NULL) {
            cout << root->data << " ";
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->kiri);
        if (root->data != NULL) {
            cout << root->data << " ";
        }
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        if (root->data != NULL) {
            cout << root->data << " ";
        }
    }
}

void search(Node **root, int cari) {
    if ((*root) == NULL) {
        cout << "Data Anda tidak dapat ditemukan!\n" << endl;
    } else if (cari < (*root)->data)
        search(&((*root)->kiri), cari);
    else if (cari > (*root)->data)
        search(&((*root)->kanan), cari);
    else if (cari == (*root)->data)
        cout << "Data Anda Sudah Ditemukan!\n" << endl;
}

int count(Node *root) {
    if (root == NULL)
        return 0;
    else
        return count(root->kiri) + count(root->kanan) + 1;
}

int height(Node *root) {
    if (root == NULL)
        return -1;
    else {
        int u = height(root->kiri);
        int v = height(root->kanan);
        if (u > v)
            return u + 1;
        else
            return v + 1;
    }
}

int main() {
    int pilihan, data;
    while (true) {
        cout << "=====================================================" << endl;
        cout << "|| IMPLEMENTASIKAN TREE UNTUK PERSAMAAN MATEMATIKA ||" << endl;
        cout << "=====================================================" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "|1| Tambah Data\n";
        cout << "|2| Pre-order Traversal\n";
        cout << "|3| In-order Traversal\n";
        cout << "|4| Post-order Traversal\n";
        cout << "|5| Search\n";
        cout << "|6| Hitung Jumlah Node\n";
        cout << "|7| Hitung Tinggi Pohon\n";
        cout << "|8| Keluar\n";
        cout << "========================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                tambah(&pohon, data);
                break;
            case 2:
                cout << "Pre-order Traversal: ";
                preOrder(pohon);
                cout << "\n\n";
                break;
            case 3:
                cout << "In-order Traversal: ";
                inOrder(pohon);
                cout << "\n\n";
                break;
            case 4:
                cout << "Post-order Traversal: ";
                postOrder(pohon);
                cout << "\n\n";
                break;
            case 5:
                cout << "Masukkan data yang ingin dicari: ";
                cin >> data;
                search(&pohon, data);
                break;
            case 6:
                cout << "Jumlah Node: " << count(pohon) << "\n\n";
                break;
            case 7:
                cout << "Tinggi Pohon: " << height(pohon) << "\n\n";
                break;
            case 8:
                exit(0);
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}

