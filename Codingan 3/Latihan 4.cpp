#include <iostream>
#include <malloc.h>
#include <iomanip>

using namespace std;

typedef struct node
{
  int Item;
  struct node *link;
} Node;

typedef struct
{
  Node *Front;
  Node *Rear;
} Queue;

void displayQueue(Node *N)
{
  cout << "\nFront -> ";
  while (N != NULL)
  {
    if (N->link == NULL)
    {
      cout << N->Item << " ";
      cout << " <- Rear";
      
    }
    else
      cout << N->Item << " ";
    N = N->link;
  }
  
}

void Tambah(Queue *Q, int y)
{
  Node *ptr;
  ptr = (Node *)malloc(sizeof(Node));
  ptr->Item = y;
  ptr->link = NULL;
  if (Q->Front == NULL)
  {
    Q->Front = Q->Rear = ptr;
  }
  else
  {
    Q->Rear->link = ptr;
    Q->Rear = ptr;
  }
}

int Hapus(Queue *Q)
{
  int num;
  if (Q->Front == NULL)
  {
    cout << "\n\t\tAntrian Kosong\n";
    return (0);
  }
  else
  {
    num = Q->Front->Item;
    Q->Front = Q->Front->link;
    if (Q->Front == NULL)
      Q->Rear = NULL;
    return (num);
  }
}

int main()
{
  Queue q;

  for (int i = 5; i <= 7; i++)
  {
    Tambah(&q, i);
    displayQueue(q.Front);
  }

  Hapus(&q);
  displayQueue(q.Front);
  Tambah(&q, 8);
  displayQueue(q.Front);
  Hapus(&q);
  displayQueue(q.Front);

  for (int i = 9; i <= 12; i++)
  {
    Tambah(&q, i);
    displayQueue(q.Front);
  }
}
