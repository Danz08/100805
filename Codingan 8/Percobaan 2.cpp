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

void insertAfter(int old, int element)
{
	if (head == NULL)
	{
		cout << "Tidak bisa di insert" << endl;
		return;
	}

	struct node *newItem = new node;
	struct node *temp = head;

	if (tail->value == old)
	{
		newItem->next = NULL;
		newItem->prev = tail;
		newItem->value = element;
		tail->next = newItem;
		tail = newItem;
		return;
	}

	while (temp != NULL)
	{
		if (temp->value == old)
		{
			newItem->next = temp->next;
			newItem->prev = temp;
			newItem->value = element;
			temp->next->prev = newItem;
			temp->next = newItem;
			return;
		}
		temp = temp->next;
	}

	cout << "Element tidak ditemukan" << endl;
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
		cout << "\t>>>Menyisipkan setelah simpul tertentu<<<" << endl;
		cout << "=========================================================" << endl;
		cout << "\t1. Tambah data di awal" << endl;
		cout << "\t2. Insert sesudah" << endl;
		cout << "\t3. Lihat node" << endl;
		cout << "\t4. Keluar" << endl;
		cout << "Masukkan pilihan = ";
		cin >> choice;

		if (choice == 1)
		{
			system("cls");
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
			system("cls");
			int old, newitem;
			cout << "Node setelah item = ";
			cin >> old;
			cout << "Masukkan node baru = ";
			cin >> newitem;
			insertAfter(old, newitem);
			printList();
		}
		else if (choice == 3)
		{
			system("cls");
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
