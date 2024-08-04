#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *tree = NULL;

// Fungsi untuk menambahkan node baru
void insert(Node **root, int newData) {
    if ((*root) == NULL) {
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->left = NULL;
        newNode->right = NULL;
        (*root) = newNode;
        cout << "Data Bertambah!\n" << endl;
    } else if (newData < (*root)->data)
        insert(&(*root)->left, newData);
    else if (newData > (*root)->data)
        insert(&(*root)->right, newData);
    else
        cout << "Data Sudah ada!" << endl;
}

// Fungsi untuk mencetak tree secara preOrder
void printPreOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Fungsi untuk menghitung jumlah simpul dalam tree
int countNodes(Node *root) {
    if (root == NULL)
        return 0;
    else
        return countNodes(root->left) + countNodes(root->right) + 1;
}

int main() {
    char choice;
    int data;
    while (true) {
        cout << "============================================" << endl;
        cout << "|| PROGRAM MENAMPILKAN JUMLAH SIMPUL TREE ||" << endl;
        cout << "============================================" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "|1| Tambah Data" << endl;
        cout << "|2| Lihat" << endl;
        cout << "|3| Hitung Simpul pada Tree" << endl;
        cout << "|4| Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilihan Anda : ";
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "\nINPUT : " << endl;
                cout << "-------" << endl;
                cout << "Masukkan data: ";
                cin >> data;
                insert(&tree, data);
                break;
            case '2':
                cout << "\nOUTPUT : " << endl;
                cout << "------------------" << endl;
                if (tree != NULL){
                    printPreOrder(tree);
                    cout << "\n\n";
                }
                else
                    cout << "Masih Kosong!!!" << endl;
                break;
            case '3':
                cout << "\nJUMLAH NODE DI DALAM TREE" << endl;
                cout << "-------------------------" << endl;
                cout << "Jumlah Simpul : " << countNodes(tree) << "\n\n";
                break;
            case '4':
            	exit(0);
            	
                return 0;
        }
    }
}

