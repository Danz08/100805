#include <iostream>
#include <cstdlib>

#define MAX 18

using namespace std;

void DescShellSort(int arr[])
{
  int jarak, temp;
  bool did_swap = true;
  jarak = MAX;
  while (jarak > 1)
  {
    jarak = jarak / 2;
    did_swap = true;
    while (did_swap)
    {
      did_swap = false;
      for (int i = 0; i < (MAX - jarak); i++)
      {
        if (arr[i] < arr[i + jarak])
        {
          temp = arr[i];
          arr[i] = arr[i + jarak];
          arr[i + jarak] = temp;
          did_swap = true;
        }
      }
    }
  }
}

int main()
{
  int data_awal[MAX], data_urut[MAX];

  cout << "	      LATIHAN 3" << endl;
  cout << "	   ~~~~~~~~~~~~~~\n";
  cout << "  Pengurutan Shell Sort Dengan Flag" << endl;
  cout << "	  Secara Descending\n"
       << endl;

  cout << "Data acak (sebelum pengurutan):" << endl;
  for (int i = 0; i < MAX; i++)
  {
    data_awal[i] = rand() % 100 + 1;
    cout << data_awal[i] << " ";
  }

  cout << "\n\nData setelah pengurutan descending:" << endl;

  for (int i = 0; i < MAX; i++)
    data_urut[i] = data_awal[i];
  DescShellSort(data_urut);
  for (int i = 0; i < MAX; i++)
    cout << data_urut[i] << " ";

  return 0;
}
