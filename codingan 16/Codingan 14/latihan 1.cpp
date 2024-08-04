#include <iostream>
#define N 5
#define M 1000
#define MAXSTACK 5

using namespace std;

struct Stack {
    int Item[MAXSTACK];
    int Count;
};

void InitializeStack(Stack *S) {
    S->Count = 0;
}

bool Empty(Stack *S) {
    return (S->Count == 0);
}

bool Full(Stack *S) {
    return (S->Count == MAXSTACK);
}

void Push(int x, Stack *S) {
    if (S->Count == MAXSTACK) {
        cout << "Stack penuh! Data tidak dapat dimasukkan!" << endl;
    } else {
        S->Item[S->Count] = x;
        ++(S->Count);
    }
}

int Pop(Stack *S) {
    if (S->Count == 0) {
        cout << "Stack masih kosong!" << endl;
        return 0;
    } else {
        --(S->Count);
        return (S->Item[S->Count]);
    }
}

void Tampil(int data[N][N], const char *judul) {
    cout << endl << judul << " = " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (data[i][j] >= M)
                cout << "M ";
            else
                cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void Warshall(int Q[N][N], int P[N][N], int R[N][N]) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
                if ((Q[i][k] + Q[k][j]) < Q[i][j]) {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    if (R[k][j] == 0)
                        R[i][j] = k + 1;
                    else
                        R[i][j] = R[k][j];
                }
            }
        }
    }
}

void tampilrute(int Q[N][N], int P[N][N], int R[N][N]) {
    Stack stack;
    InitializeStack(&stack);
    int n, m;
    cout << "\nRute n sampai m" << endl;
    cout << "Input n : ";
    cin >> n;
    cout << "Input m : ";
    cin >> m;
    for (int j = m - 1, i = n - 1; j >= 0; j--) {
        if (R[i][j] == 0)
            break;
        else
            Push(R[i][j], &stack);
    }
    cout << "\nRute " << n << "-" << m << " : " << n << "-";
    for (int i = 0; i < MAXSTACK; i++) {
        if (Empty(&stack)) {
            cout << m << " ";
            break;
        } else
            cout << Pop(&stack) << "-";
    }
    cout << "dengan beban minimal " << Q[n - 1][m - 1];
}

int main() {
    int Beban[N][N] = {{M, 1, 3, M, M},
                       {M, M, 1, M, 5},
                       {3, M, M, 2, M},
                       {M, M, M, M, 1},
                       {M, M, M, M, M}};

    int Jalur[N][N] = {{0, 1, 1, 0, 0},
                       {0, 0, 1, 0, 1},
                       {1, 0, 0, 1, 0},
                       {0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0}};

    int Rute[N][N] = {{M, 0, 0, M, M},
                      {M, M, 0, M, 0},
                      {0, M, M, 0, M},
                      {M, M, M, M, 0},
                      {M, M, M, M, M}};

    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");
    Warshall(Beban, Jalur, Rute);
    cout << "\nMatriks setelah Algoritma Warshall :";
    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");
    tampilrute(Beban, Jalur, Rute);
    cout << endl;

    return 0;
}

