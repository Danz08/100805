#include <iostream>

#define N 5
#define M 1000

using namespace std;

void inisialisasi(int a, int Q[]) {
    for (int i = 0; i < N; i++) {
        if ((i + 1) == a)
            Q[i] = 0;
        else
            Q[i] = M;
    }
}

void Tampil(int data[N], string judul) {
    cout << judul << " = " << " ";
    for (int i = 0; i < N; i++) {
        if (data[i] >= M)
            cout << "M ";
        else
            cout << data[i] << " ";
    }
    cout << endl;
}

int MinimumDistance(int distance[], bool Tset[]) {
    int minimum = M, ind;
    for (int k = 0; k < N; k++) {
        if (!Tset[k] && distance[k] <= minimum) {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void Djikstra(int graph[N][N], int Beban[N], int Rute[N], int asal, int tujuan) {
    int distance[N];
    bool Visited[N];

    for (int k = 0; k < N; k++) {
        distance[k] = M;
        Visited[k] = false;
    }

    distance[asal] = 0;

    for (int i = 0; i < N; i++) {
        int m = MinimumDistance(distance, Visited);
        Visited[m] = true;

        for (int j = 0; j < tujuan; j++) {
            if (!Visited[j] && graph[m][j] && distance[m] != M && distance[m] + graph[m][j] < distance[j]) {
                distance[j] = distance[m] + graph[m][j];
                Rute[j] = m;
            }
        }
    }

    for (int i = 0; i < tujuan; i++) {
        Beban[i] = distance[i];
    }
}

int main() {
    cout << "==============================================================" << endl;
    cout << "||                        LATIHAN 1                         ||\n";
    cout << "|| PROGRAM MENCARI RUTE TERPENDEK DENGAN ALGORITMA DIJKSTRA ||" << endl;
    cout << "==============================================================" << endl;

    int input[N][N] = {
        { M, 1, 3, M, M },
        { M, M, 1, M, 5 },
        { 3, M, M, 2, M },
        { M, M, M, M, 1 },
        { M, M, M, M, M }
    };

    int Beban[N], Rute[N] = { 0, 0, 0, 0, 0 };
    int asal, tujuan;

    cout << "\nMasukkan node asal : ";
    cin >> asal;
    cout << "Masukkan node tujuan : ";
    cin >> tujuan;

    cout << "\n=========================================================" << endl;
    cout << "Beban dan Rute awal" << endl;
    cout << "=========================================================" << endl;
    inisialisasi(asal, Beban);
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute ");
    cout << "\n=========================================================" << endl;

    Djikstra(input, Beban, Rute, asal - 1, tujuan);

    cout << "Beban dan Rute setelah Djikstra" << endl;
    cout << "=========================================================" << endl;
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute ");

    return 0;
}

