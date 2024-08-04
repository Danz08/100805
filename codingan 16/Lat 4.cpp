#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

Node *pohon = NULL;

void tambah(Node **root, int databaru) {
    if ((*root) == NULL) {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        cout << "Data Bertambah!\n\n";
    } else if (databaru < (*root)->data) {
        tambah(&(*root)->kiri, databaru);
    } else if (databaru > (*root)->data) {
        tambah(&(*root)->kanan, databaru);
    } else if (databaru == (*root)->data) {
        cout << "Data Sudah ada!";
    }
}

void tampil(Node *root) {
    if (root != NULL) {
        if (root->data != NULL) {
            cout << root->data << " ";
        }
        tampil(root->kiri);
        tampil(root->kanan);
    }
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
    char pil;
    int del, cari;
    int data;
    while (true) {
        cout << "======================================================" << endl;
        cout << "|| PROGRAM MENAMPILKAN KEDALAMAN MAKSIMUM DARI TREE ||" << endl;
        cout << "======================================================" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "|1| Tambah Data" << endl;
        cout << "|2| Lihat" << endl;
        cout << "|3| Kedalaman" << endl;
        cout << "|4| Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilihan Anda : ";
        cin >> pil;
        switch (pil) {
            case '1':
                cout << "\nINPUT : " << endl;
                cout << "-------" << endl;
                cout << "Masukkan data: ";
                cin >> data;
                tambah(&pohon, data);
                break;
            case '2':
                cout << "\nOUTPUT : " << endl;
                cout << "------------------" << endl;
                if (pohon != NULL){
                    tampil(pohon);
                	cout << "\n\n";
				}    
                else
                    cout << "Masih Kosong!!!";
                break;
            case '3':
                cout << "\nKEDALAMAN TREE(LEVEL-> DIMULAI DARI 0)" << endl;
                cout << "----------------------------------------" << endl;
                cout << "Kedalaman tree : " << height(pohon) << endl;
                break;
            case '4':
            	exit(0);
                return 0;
        }
    }
}

