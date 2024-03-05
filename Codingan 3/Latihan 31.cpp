#include <iostream>
#include <cstdlib>
#define MAX 500

using namespace std;

struct Queue {
    int plat[MAX];
    int front;
    int rear;
    int count;
};

struct Stack {
    int plat[MAX];
    int count;
};

void InitializeQueue(Queue *q) {
    q->front = q->rear = -1;
    q->count = 0;
}

void InitializeStack(Stack *s) {
    s->count = 0;
}

void Push(int plt, Stack *s) {
    s->count++;
    s->plat[s->count] = plt;
}

int Pop(Stack *s) {
    int plt;
    plt = s->plat[s->count];
    s->count--;
    return plt;
}

void Enqueue(int plt, Queue *q) {
    if (q->rear == MAX - 1) {
        cout << "\nAntrian Penuh !\n";
        return;
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->plat[q->rear] = plt;
        q->count++;
    }
}

int CheckCar(int plt, Queue *q) {
    int i, result;
    for (i = q->front; i <= q->rear; i++) {
        if (q->plat[i] == plt) {
            result = i;
            break;
        }
    }
    if (i == q->rear + 1)
        result = -1;
    return result;
}

void NormalizeQueue(int x, Queue *q, Stack *s) {
    int i;
    for (i = q->front; i <= x; i++) {
        q->plat[i] = q->plat[i + 1];
    }
    q->rear--;
    q->count--;
    while (s->count != 0) {
        Enqueue(Pop(s), q);
    }
}

void Dequeue(int plt, Queue *q, Stack *s) {
    int x;
    x = CheckCar(plt, q);
    if (x == -1) {
        cout << "\nPlat mobil yang anda masukkan tidak ada dalam antrian !\n";
        return;
    } else {
        if (x == q->front && q->count > 1) {
            q->front++;
            q->count--;
            return;
        } else if (x == q->front && q->count == 1) {
            InitializeQueue(q);
            return;
        } else {
            cout << "\nMobil yang keluar sementara : \n";
            for (int i = q->front; i < x; i++) {
                cout << "- Mobil plat nomor " << q->plat[i] << endl;
                Push(q->plat[i], s);
                q->front++;
                q->count--;
            }
            NormalizeQueue(x, q, s);
        }
    }
}

void DisplayQueue(Queue *q) {
    int i;
    cout << "------------------------------------------\n";
    cout << "Data antrian mobil yang parkir : \n";
    cout << "------------------------------------------\n";
    if (q->count == 0) {
        cout << "\nTidak ada mobil yang sedang parkir\n";
    } else {
        for (i = q->front; i <= q->rear; i++) {
            cout << i + 1 << ". Mobil plat nomor " << q->plat[i] << endl;
        }
        cout << "\nJumlah mobil yang parkir : " << q->count << endl;
    }
    cout << "\n\n**Tekan sebarang tombol untuk kembali ke pilihan**";
    cin.ignore();
    cin.get();
    return;
}

int main() {
    Queue q;
    Stack s;
    int choice;
    int plt;
    InitializeQueue(&q);
    InitializeStack(&s);
    do {
        system("cls");
        cout << "-------------------------------\n";
        cout << "PROGRAM ANTRIAN MOBIL\n";
        cout << "-------------------------------\n";
        cout << "1. Masukkan mobil\n2. Keluarkan mobil\n3. Tampilkan antrian\n";
        cout << "4. Keluar\n";
        cout << "-------------------------------\n";
        cout << "Pilihan anda : ";
        cin >> choice;
        cout << "-------------------------------\n";
        switch (choice) {
            case 1:
                cout << "Masukkan nomor plat mobil masuk (tanpa huruf) : ";
                cin >> plt;
                Enqueue(plt, &q);
                DisplayQueue(&q);
                break;
            case 2:
                cout << "Masukkan plat nomor mobil keluar (tanpa huruf) : ";
                cin >> plt;
                Dequeue(plt, &q, &s);
                DisplayQueue(&q);
                break;
            case 3:
                DisplayQueue(&q);
                break;
            case 4:
                cout << "............";
                break;
            default:
                cout << "\n\nPilihan tidak valid. Silahkan ulangi!\n";
                cin.ignore();
                cin.get();
        }
    } while (choice != 4);
    return 0;
}
