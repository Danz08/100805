#include <iostream>
#include <cstring>
using namespace std;

const int N = 3;

void tambah(int A[N][N], int B[N][N], int C[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void kurang(int A[N][N], int B[N][N], int C[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void kali(int A[N][N], int B[N][N], int C[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int jumlah = 0;
            for (int k = 0; k < N; k++)
            {
                jumlah += A[i][k] * B[k][j];
            }
            C[i][j] = jumlah;
        }
    }
}

int main()
{
    int M1[N][N];
    int M2[N][N];
    int hasil[N][N];

    cout << "Selamat datang di penjumlahan, pengurangan, dan perkalian matriks :)" << endl;
    cout << "====================================================================" << endl;

    cout << endl;
    cout << "Masukkan elemen-elemen Matriks pertama:" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masukkan elemen untuk :" << endl;
    for (int i = 0; i < N; i++)
    {
		cout << "baris " << i + 1 << endl;
		for (int j = 0; j < N; j++)
        {
			cout << "kolom " << j + 1 << ":";
            cin >> M1[i][j];
        }
        cout << "=========" << endl;
    }
    system("cls"); 
    
    cout << "Masukkan elemen-elemen Matriks kedua:" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Masukkan elemen untuk :" << endl;
    for (int i = 0; i < N; i++)
    {
		cout << "baris " << i + 1 << endl;
		for (int j = 0; j < N; j++)
        {
			cout << "kolom " << j + 1 << ":";
            cin >> M2[i][j];
        }
        cout << "========" << endl;
    }
    system("cls"); 
    
	cout << "Matrix 1" << endl;
	for(int i = 0; i < N; i++){
		cout << " ";
		for(int j = 0; j < N; j++){
			cout << M1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Matrikx 2" << endl;
	for(int i = 0; i < N; i++){
		cout << " ";
		for(int j = 0; j < N; j++){
			cout << M2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

    cout << "Hasil Penjumlahan = " << endl;
    tambah(M1, M2, hasil);
    for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < N; j++)
        {
            cout << " ";
			cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan = " << endl;
    kurang(M1, M2, hasil);
    for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < N; j++)
        {
            cout << " ";
			cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian = " << endl;
    kali(M1, M2, hasil);
    for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < N; j++)
        {
            cout << " ";
			cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

