#include<iostream>
#define MAX 15

using namespace std;

typedef struct 
{
    int Item[MAX];
    int Front;
    int Rear;
    int Count;
}Queue;

void Inisialisasi(Queue *q)
{
    q->Front = q->Rear = -1;
    q->Count = 0;
}

void Tambah(Queue *q, int item)
{
    if ((q->Rear == MAX - 1 && q->Front == 0) || (q->Rear + 1 == q->Front))
    {
	    if (item == 12)
	    {
		    cout << "Antrian penuh";
	        return;
    	}
	}
    if (q->Front == -1)
    {
        q->Front = q->Rear = 0;
    }
    else if (q->Rear == MAX - 1)
    {
        q->Rear = 0;
    }
    else
    {
        q->Rear++;
    }
    q->Item[q->Rear] = item;
    q->Count++;
}

int Hapus(Queue *q)
{
    int data;
    if (q->Front == -1)
    {
        cout << "Antrian kosong";
    }
    else
    {
        data = q->Item[q->Front];
        q->Count--;
        if (q->Front == q->Rear)
        {
            q->Front = q->Rear = -1;
        }
        else
        {
            if (q->Front == MAX - 1)
                q->Front = 0;
            else
                q->Front++;
        }
    }
    return data;
}

void Tampil(Queue *q)
{
    cout << "Data  : ";
    if (q->Front <= q->Rear)
    {
        for (int i = q->Front; i <= q->Rear; i++)
        {
            cout << q->Item[i] << " |";
        }
    }
    else
    {
        for (int i = q->Front; i < MAX; i++)
        {
            cout << q->Item[i] << " ";
        }
        for (int i = 0; i <= q->Rear; i++)
        {
            cout << q->Item[i] << " ";
        }
    }
    cout << endl;
}

void trackdata(Queue *q)
{
    cout << "Front : " << q->Front << " |";
    cout << "Rear : " << q->Rear << " |";
    cout << "Count : " << q->Count << endl << endl;
}

int main()
{
    Queue q;
    int data;
    Inisialisasi(&q);
    Tambah(&q, 5);
    Tampil(&q);
    trackdata(&q);
    Tambah(&q, 6);
    Tampil(&q);
    trackdata(&q);
    Tambah(&q, 7);
    Tampil(&q);
    trackdata(&q);
    data = Hapus(&q);
    Tampil(&q);
    trackdata(&q);
    Tambah(&q, 8);
    Tampil(&q);
    trackdata(&q);
    Tambah(&q, 9);
    Tampil(&q);
    trackdata(&q);
    data = Hapus(&q);
    Tampil(&q);
    trackdata(&q);
    Tambah(&q, 10);
    Tampil(&q);
    trackdata(&q);
    Tambah(&q, 11);
    Tampil(&q);
    trackdata(&q);
    Tambah(&q, 12);
    return 0;
}
