#include <iostream>
#define N 5
#define M 1000

using namespace std;

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
    cout << "Masukkan node tujuan :";
    cin >> tujuan;
    inisialisasi(asal, Beban);
    cout <<"Beban dan Rute awal\n";
    Tampil(Beban, "Beban");
    Tampil(Rute, "\nRute");
    
    return 0;
}
