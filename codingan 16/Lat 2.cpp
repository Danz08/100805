#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

Node *pohon = NULL;

void tambah(Node **root, int databaru) {
    if (*root == NULL) {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
        cout << "Data Bertambah!" << endl;
    } else if (databaru < (*root)->data)
        tambah(&(*root)->kiri, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->kanan, databaru);
}

void tampil(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        tampil(root->kiri);
        tampil(root->kanan);
    }
}

int main() {
    char pil;
    int data;
    while (true) {
        cout << "========================================" << endl;
        cout << "|| PROGRAM MENAMPILKAN DATA DARI TREE ||" << endl;
        cout << "========================================" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "|1| Tambah Data" << endl;
        cout << "|2| Lihat" << endl;
        cout << "|3| Keluar" << endl;
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
                    cout << endl;
            	}
				else
                    cout << "Masih Kosong!!!" << endl;
                break;
            case '3':
            	exit(0);
            	
                return 0;
        }
    }
}

