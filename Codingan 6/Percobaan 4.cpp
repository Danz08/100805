#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *insert(Node *p, int n)
{
    Node *temp;
    if (p == NULL)
    {
        p = new Node;
        p->data = n;
        p->link = NULL;
    }
    else
    {
        temp = p;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = new Node;
        temp = temp->link;
        temp->data = n;
        temp->link = NULL;
    }
    return p;
}

Node *insertAfter(Node *p, int nilai_sisip, int nilai_baru)
{
    Node *temp, *newNode;
    temp = p;

    // Cari simpul dengan nilai tertentu
    while (temp != NULL && temp->data != nilai_sisip)
    {
        temp = temp->link;
    }

    // Jika simpul dengan nilai tertentu tidak ditemukan
    if (temp == NULL)
    {
        cout << "Simpul dengan nilai " << nilai_sisip << " tidak ditemukan dalam list." << endl;
        exit(0);
    }

    // Buat simpul baru
    newNode = new Node;
    newNode->data = nilai_baru;
    newNode->link = temp->link;
    temp->link = newNode;

    return p;
}

Node *insertBefore(Node *p, int nilai_sisip, int nilai_baru)
{
    Node *temp, *newNode;
    temp = p;

    // Jika simpul yang ingin disisipkan adalah simpul pertama
    if (temp != NULL && temp->data == nilai_sisip)
    {
        newNode = new Node;
        newNode->data = nilai_baru;
        newNode->link = temp;
        return newNode;
    }

    // Cari simpul dengan nilai tertentu
    while (temp != NULL && temp->link != NULL && temp->link->data != nilai_sisip)
    {
        temp = temp->link;
    }

    // Jika simpul dengan nilai tertentu tidak ditemukan
    if (temp == NULL || temp->link == NULL)
    {
        cout << "Simpul dengan nilai " << nilai_sisip << " tidak ditemukan dalam list." << endl;
        exit(0);
    }

    // Buat simpul baru
    newNode = new Node;
    newNode->data = nilai_baru;
    newNode->link = temp->link;
    temp->link = newNode;

    return p;
}

Node *hapus(Node *p, int nilai)
{
    Node *temp, *prev;
    temp = p;
    prev = NULL;

    while (temp != NULL && temp->data != nilai)
    {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL)
    {
        cout << "Simpul dengan nilai " << nilai << " tidak ditemukan dalam list." << endl;
        exit(0);
    }

    if (prev == NULL)
    {
        p = p->link;
        delete temp;
        return p;
    }

    if (temp->link == NULL)
    {
        prev->link = NULL;
        delete temp;
        return p;
    }

    prev->link = temp->link;
    delete temp;
    return p;
}

void display(Node *p)
{
    if (p == NULL)
    {
        cout << "List kosong" << endl;
        return;
    }
    while (p != NULL)
    {
        cout << p->data;
        if (p->link != NULL)
            cout << " -> ";
        p = p->link;
    }
    cout << endl;
}

int main()
{
    int n, x;
    Node *start = NULL;
    cout << "Masukkan jumlah simpul yang akan dibuat: ";
    cin >> n;
    while (n-- > 0)
    {
        cout << "Masukkan nilai data untuk simpul: ";
        cin >> x;
        start = insert(start, x);
    }

    cout << "\nList yang terbuat adalah: ";
    display(start);

    int pilih, nilai_sisip, nilai_baru;
    cout << "\nPilih operasi yang ingin dilakukan:\n";
    cout << "1. Menghapus simpul tertentu\n";
    cout << "2. Menyisipkan setelah simpul tertentu\n";
    cout << "3. Menyisipkan sebelum simpul tertentu\n";
    cout << "Pilihan Anda: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        cout << "Masukkan nilai simpul yang ingin dihapus: ";
        cin >> nilai_sisip;
        start = hapus(start, nilai_sisip);
        cout << "List setelah menghapus simpul dengan nilai " << nilai_sisip << " adalah: ";
        display(start);
        break;
    case 2:
        cout << "Masukkan nilai simpul setelahnya: ";
        cin >> nilai_sisip;
        cout << "Masukkan nilai data yang akan disisipkan: ";
        cin >> nilai_baru;
        start = insertAfter(start, nilai_sisip, nilai_baru);
        cout << "List setelah menyisipkan nilai " << nilai_baru << " setelah nilai " << nilai_sisip << " adalah: ";
        display(start);
        break;
    case 3:
        cout << "Masukkan nilai simpul sebelumnya: ";
        cin >> nilai_sisip;
        cout << "Masukkan nilai data yang akan disisipkan: ";
        cin >> nilai_baru;
        start = insertBefore(start, nilai_sisip, nilai_baru);
        cout << "List setelah menyisipkan nilai " << nilai_baru << " sebelum nilai " << nilai_sisip << " adalah: ";
        display(start);
        break;
    default:
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}

