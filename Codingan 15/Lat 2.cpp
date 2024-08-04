#include <iostream>
#include <limits>
using namespace std;

#define N 5
#define M 1000

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
            printf("M ");
        else
            cout << data[i] << " ";
    }
    cout << endl;
}

int MinimumDistance(int distance[], bool Tset[]) {
    int minimum = M, ind;
    for (int k = 0; k < N; k++) {
        if (Tset[k] == false && distance[k] <= minimum) {
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
    for (int k = 0; k < N; k++) {
        int m = MinimumDistance(distance, Visited);
        Visited[m] = true;
        for (int k = 0; k < tujuan; k++) {
            if (!Visited[k] && graph[m][k] && distance[m] != M && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
        if (distance[k] != M)
            Rute[k] = m;
        else
            Rute[k] = 0;
    }
    for (int i = 0; i < tujuan; i++)
        Beban[i] = distance[i];
}

void Minimum(int Beban[N], int Rute[N]) {
    int minBeban = M;
    for (int i = 0; i < N; i++) {
        if (minBeban > Beban[i] && Beban[i] != 0) {
            if (Beban[i] == 0)
                continue;
            else
                minBeban = Beban[i];
        }
    }
    if (minBeban != M) {
        cout << "\nRute Minimum: ";
        bool first = true;
        for (int i = 0; i < N; i++) {
            if (Rute[i] != 0 && Beban[i] != M) {
                if (!first) {
                    cout << "->";
                } else {
                    first = false;
                }
                cout << Rute[i];
            }
        }
        cout << " dengan beban Minimum " << minBeban << endl;
    } else {
        cout << "\nTidak ada rute minimum...\n";
    }
}


int main() {
    
    cout << "================================================================" << endl;
    cout << "||                         LATIHAN 2                          ||\n";
    cout << "|| PROGRAM UNTUK MENAMPILKAN RUTE TERPENDEK DARI VEKTOR RUTE  ||" << endl;
    cout << "||          DAN BEBAN TERKECIL DARI VEKTOR BEBAN.             ||" << endl;
    cout << "================================================================" << endl;

	
	int input[N][N] = {
        {M, 1, 3, M, M},
        {M, M, 1, M, 5},
        {3, M, M, 2, M},
        {M, M, M, M, 1},
        {M, M, M, M, M}
    };
    int Beban[N], Rute[N] = {0, 0, 0, 0, 0};
    int asal, tujuan;

    cout << "Masukkan node asal : ";
    cin >> asal;
    cout << "Masukkan node tujuan : ";
    cin >> tujuan;

    inisialisasi(asal, Beban);

    cout << "\n=============================================\n";
    cout << "Beban dan Rute awal \n";
    cout << "=============================================\n";
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute");

    Djikstra(input, Beban, Rute, asal - 1, tujuan);

    cout << "\n=============================================\n";
    cout << "Beban dan Rute setelah Djikstra \n";
    cout << "=============================================\n";
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute");

    Minimum(Beban, Rute);

    return 0;
}

