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

void display(Node *p)
{
    if (p == NULL)
    {
        cout << "List kosong" << endl;
        return;
    }
    while (p != NULL)
    {
        while (p != NULL)
        if (p->link != NULL)
            cout << " -> ";
        p = p->link;
    }
    cout << endl;
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

    int nilai_hapus;
    cout << "\nMasukkan nilai yang ingin dihapus: ";
    cin >> nilai_hapus;
    start = hapus(start, nilai_hapus);
    cout << "List setelah menghapus nilai " << nilai_hapus << " adalah: ";
    display(start);

    return 0;
}

