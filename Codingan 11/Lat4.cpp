#include <iostream>
#include <algorithm>
#include <cstdlib>

#define MAX_SIZE 50

using namespace std;

struct Mahasiswa
{
  int nim;
  char nama[20];
  int kelas;
};

struct Mahasiswa data[MAX_SIZE];
int j = 0;

void tambah_data()
{
  cout << "NIM: ";
  cin >> data[j].nim;
  cout << "Nama: ";
  cin >> data[j].nama;
  cout << "Kelas: ";
  cin >> data[j].kelas;
  j++;
}

void tampil()
{
  cout << "======================================\n";
  cout << "Data Mahasiswa yang telah diinputkan :\n";
  cout << "======================================\n";
  cout << "NIM\tNama\tKelas\n";
  for (int i = 0; i < j; i++)
  {
    cout << data[i].nim << "\t" << data[i].nama << "\t" << data[i].kelas << endl;
  }
}

void AscBubbleSort(int arr[], int MAX)
{
  for (int i = 0; i < MAX - 1; i++)
  {
    for (int j = 0; j < MAX - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swap(data[j], data[j + 1]);
      }
    }
  }
}

void DescBubbleSort(int arr[], int MAX)
{
  for (int i = 0; i < MAX - 1; i++)
  {
    for (int j = 0; j < MAX - i - 1; j++)
    {
      if (arr[j] < arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swap(data[j], data[j + 1]);
      }
    }
  }
}

void AscShellSort(int arr[], int MAX)
{
  for (int gap = MAX / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < MAX; i++)
    {
      int temp = arr[i];
      struct Mahasiswa temp_data = data[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
      {
        arr[j] = arr[j - gap];
        data[j] = data[j - gap];
      }
      arr[j] = temp;
      data[j] = temp_data;
    }
  }
}

int main()
{
  int MAX;
  cout << "============================================\n";
  cout << "Program Penerapan Bubble & Shell Sort\n";
  cout << "Ascending & Descending Sort\n";
  cout << "============================================\n";
  cout << "Berapa banyak data yang ingin anda masukkan: ";
  cin >> MAX;
  cout << "============================================\n";
  cout << "\nMasukkan data mahasiswa: \n\n";
  for (int i = 0; i < MAX; i++)
  {
    tambah_data();
    cout << endl;
  }
  cout << "============================================\n";
  cout << "Data sebelum diurutkan:\n";
  tampil();
  cout << "============================================\n";

  int data_nim[MAX];
  for (int i = 0; i < MAX; i++)
  {
    data_nim[i] = data[i].nim;
  }

  int pil;
  cout << "Silahkan pilih aksi yang ingin anda lakukan selanjutnya!\n";
  cout << "1. Lakukan Pengurutan Ascending Bubble Sort\n";
  cout << "2. Lakukan Pengurutan Descending Bubble Sort\n";
  cout << "3. Lakukan Pengurutan Ascending Shell Sort\n";
  cout << "4. Keluar\n";
  cout << "============================================\n";
  while (true)
  {
    cout << "Pilihan Anda: ";
    cin >> pil;
    cout << "============================================\n";
    switch (pil)
    {
    case 1:
      AscBubbleSort(data_nim, MAX);
      cout << "Data setelah pengurutan ascending:\n";
      tampil();
      break;
    case 2:
      DescBubbleSort(data_nim, MAX);
      cout << "Data setelah pengurutan descending:\n";
      tampil();
      break;
    case 3:
      AscShellSort(data_nim, MAX);
      cout << "Data setelah pengurutan ascending:\n";
      tampil();
      break;
    case 4:
      cout << "Terima kasih!\n";
      return 0;
    default:
      cout << "Pilihan tidak valid. Silakan coba lagi.\n";
    }
    cout << "============================================\n";
  }
  return 0;
}
