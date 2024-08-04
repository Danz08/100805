#include <iostream>
using namespace std;

struct node
{
  int value;
  struct node *next;
  struct node *prev;
};

struct node *head;
struct node *tail;

void init()
{
  head = NULL;
  tail = NULL;
}

void insertFirst(int element)
{
  struct node *newItem = new node;

  if (head == NULL)
  {
    head = newItem;
    newItem->prev = NULL;
    newItem->value = element;
    newItem->next = NULL;
    tail = newItem;
  }
  else
  {
    newItem->next = head;
    newItem->value = element;
    newItem->prev = NULL;
    head->prev = newItem;
    head = newItem;
  }
}

void insertBefore(int old, int element)
{
  if (head == NULL)
  {
    cout << "Tidak bisa di insert" << endl;
    return;
  }

  struct node *newItem = new node;
  struct node *temp = head;

  // Jika data pertama adalah simpul yang akan disisipkan sebelumnya
  if (head->value == old)
  {
    insertFirst(element);
    return;
  }

  if (head == tail)
  {
    if (head->value != old)
    {
      cout << "Tidak bisa di insert" << endl;
      return;
    }
    newItem->value = element;
    head->next = newItem;
    newItem->next = NULL;
    head->prev = NULL;
    newItem->prev = head;
    tail = newItem;
    return;
  }

  if (tail->value == element)
  {
    newItem->next = tail;
    newItem->prev = NULL;
    tail->next = newItem;
    tail = newItem;
    return;
  }

  while (temp->value != old)
  {
    temp = temp->next;
    if (temp == NULL)
    {
      cout << "Tidak bisa di insert" << endl;
      cout << "Element tidak ditemukan" << endl;
      return;
    }
  }

  newItem->prev = temp->prev;
  newItem->next = temp;
  newItem->value = element;
  temp->prev->next = newItem;
  temp->prev = newItem;
}

void printList()
{
  struct node *temp = head;

  while (temp != NULL)
  {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  cout << endl;
  init();
  int choice;

  while (true)
  {
    cout << "\t>>>Menyisipkan sebelum simpul tertentu<<<" << endl;
    cout << "=========================================================" << endl;
    cout << "\t1. Tambah data di awal" << endl;
    cout << "\t2. Insert sebelum" << endl;
    cout << "\t3. Lihat node" << endl;
    cout << "\t4. Keluar" << endl;
    cout << "Masukkan pilihan = ";
    cin >> choice;

    if (choice == 1)
    {
      int numElements;
      cout << "Masukkan jumlah angka yang ingin dimasukkan: ";
      cin >> numElements;
      cout << "Masukkan angka-angka: ";
      for (int i = 0; i < numElements; ++i)
      {
        int element;
        cin >> element;
        insertFirst(element);
      }
      printList();
    }
    else if (choice == 2)
    {
      int old, newitem;
      cout << "Node sebelum item = ";
      cin >> old;
      cout << "Masukkan node baru = ";
      cin >> newitem;
      insertBefore(old, newitem);
      printList();
    }
    else if (choice == 3)
    {
      printList();
    }
    else if (choice == 4)
    {
      cout << "Terima kasih, program selesai." << endl;
      break;
    }
  }

  return 0;
}
