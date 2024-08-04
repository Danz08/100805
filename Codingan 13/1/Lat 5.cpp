#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *link;
};

node *head = NULL;

void insert(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->link = head;
    head = temp;
}

void search()
{
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    int index;
    cout << "Silahkan input indeks angka yang ingin dicari: ";
    cin >> index;

    node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        if (count == index)
        {
            cout << "Angka yang dicari yaitu angka " << index << " berada di indeks ke-" << temp->data << endl;
            return;
        }
        count++;
        temp = temp->link;
    }

    cout << "Indeks tidak ditemukan" << endl;
}

int main()
{
    cout << "~~ ~~\n";
    cout << " METHOD SEQUENTIAL SEARCH (LINKED LIST)\n";
    cout << "~~ ~~\n\n";

    int n, x;
    cout << "Silahkan input total angka yang diinginkan: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Silahkan input angka: ";
        cin >> x;
        insert(x);
    }

    cout << endl;
    search();

    return 0;
}

