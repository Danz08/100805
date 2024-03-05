#include <iostream>
#define MAX 10 

using namespace std;

typedef struct 
{
	int Item[MAX];
	int Front;
	int Rear;
	int Count;
}Queue;

void inisialisasi (Queue *q)
{
	q->Front = q->Rear = -1;
	q->Count = 0;
}

void Tambah (Queue *q, int item)
{
	if (q->Rear == MAX-1)
	{
		cout << "Antrian penuh" << endl;
		return;
	}
	q->Rear++;
	q->Item[q->Rear] = item;
	q->Count++;
	if (q->Front == -1) q->Front=0;
}

int Hapus(Queue *q)
{
	int data;
	if (q->Front == -1)
	{
		cout << "Antrian Kosong" << endl;
		return NULL;
	}
	data = q->Item[q->Front];
	q->Count--;
	if (q->Front == q->Rear)
	{
		q->Front = q->Rear = -1;
	}
	else 
	{
		q->Front++;
	}
	return data;
}

void Tampil (Queue *q)
{
	int i =0;
	int f = q->Front;
	while (i<q->Count)
	{
		cout <<"Data : "<< q->Item[f] <<" " << endl;
		f = (f+1)%MAX;
		i++;
	}
}
int main()
{
	Queue q;
	int data;
	inisialisasi (&q);
	Tambah(&q, 11);
	Tambah(&q, 12);
	Tambah(&q, 13);
	Tambah(&q, 14);
	Tambah(&q, 15);
	Tambah(&q, 16);
	Tambah(&q, 17);
	Tambah(&q, 18);
	Tambah(&q, 19);
	Tambah(&q, 20);
	Tambah(&q, 21);
	Tampil(&q);
	cout << " " << endl;
	
	data = Hapus(&q);
	cout << "Hapus item = " << data << endl;
	
	data = Hapus(&q);
	cout << "Hapus item = " << data << endl;
	
	data = Hapus(&q);
	cout << "Hapus item = " << data << endl;
	cout << " " << endl;
	Tampil(&q);
	return 0;
}
