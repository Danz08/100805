#include <iostream>
#include <cstdlib>
#define N 5
#define M 1000
using namespace std;

typedef struct{
	int item[N];
	int front;
	int rear;
	int count;
} Queue;

void inisialisasi_queue(Queue *q){
	q->front = q->rear = q->count = 0;
}

int Kosong(Queue *q){
	return q->count == 0;
}

int Penuh(Queue *q){
	return q->count == N;
}

void inisialisasi(int a, int Q[]){
	for(int i = 0; i < N; i++)
		if((i + 1) == a)
			Q[i] = 0;
		else
			Q[i] = M;
}

void Tampil(int data[N], const char *judul){
	cout << judul << " = " << " " << endl;
	for(int i = 0; i < N; i++)
		if(data[i] >= M)
			cout << "M ";
		else
			cout << data[i] << " "; 
}

void Enqueue(Queue *q, int x){
	if(Penuh(q)){
		cout << "\nQueue telah Penuh!!!";
		exit(1);
	}
	else {
		q->item[q->rear] = x;
		q->rear = (q->rear + 1) % N;
		q->count++;
	}
}

int Dequeue(Queue *q){
	int temp;
	if(Kosong(q)){
		cout << "\nQueue Masih Kosong!!!";
		temp = -1;
	}
	else{
		temp = q->item[q->front];
		q->front = (q->front + 1) % N;
		q->count--;
	}
	return temp;
}

int main(){
	int input[N][N] = {{M, 1, 3, M, M},
                       {M, M, 1, M, 5},
                       {3, M, M, 2, M},
                       {M, M, M, M, 1},
                       {M, M, M, M, M}};
    int Beban[N], Rute[N] = {0, 0, 0, 0, 0};
    int asal, tujuan;
    
    cout << "Masukkan node asal : ";
    cin >> asal;
    cout << "\nMasukkan node tujuan :";
    cin >> tujuan;
    inisialisasi(asal, Beban);
    cout <<"\nBeban dan Rute awal\n";
    Tampil(Beban, "Beban");
    Tampil(Rute, "\nRute");
    
    return 0;
}
