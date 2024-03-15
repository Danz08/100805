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
        exit (0);
    }

    // Buat simpul baru
    newNode = new Node;
    newNode->data = nilai_baru;
    newNode->link = temp->link;
    temp->link = newNode;

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

    int nilai_sisip, nilai_baru;
    cout << "\nMasukkan nilai simpul setelahnya: ";
    cin >> nilai_sisip;
    cout << "Masukkan nilai data yang akan disisipkan: ";
    cin >> nilai_baru;

    start = insertAfter(start, nilai_sisip, nilai_baru);
    cout << "List setelah menyisipkan nilai " << nilai_baru << " setelah nilai " << nilai_sisip << " adalah: ";
    display(start);

    return 0;
}

