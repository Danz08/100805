#include <iostream>
#include <cstdlib>
#define MAX 18

using namespace std;

void DescBubbleSort(int arr[])
{
  for (int i = 0; i < MAX - 1; i++)
  {
    for (int j = 0; j < MAX - i - 1; j++)
    {
      if (arr[j] < arr[j + 1])
      {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main()
{
  int data_awal[MAX], data_urut[MAX];

  cout << "	       LATIHAN 1" << endl;
  cout << "	    ~~~~~~~~~~~~~~\n";
  cout << "	Pengurutan Bubble Sort" << endl;
  cout << "	  Secara Descending\n"<< endl;

  cout << "Data acak (sebelum pengurutan):" << endl;
  for (int i = 0; i < MAX; i++)
  {
    data_awal[i] = rand() % 100 + 1;
    cout << data_awal[i] << " ";
  }
  cout << endl
       << endl;

  cout << "Data setelah pengurutan descending:" << endl;
  for (int i = 0; i < MAX; i++)
    data_urut[i] = data_awal[i];
  DescBubbleSort(data_urut);
  for (int i = 0; i < MAX; i++)
    cout << data_urut[i] << " ";
  cout << endl;

  return 0;
}
