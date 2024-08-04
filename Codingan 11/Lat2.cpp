#include <iostream>
#include <cstdlib>
#define MAX 18

using namespace std;

void DescBubbleSortFlag(int arr[])
{
  int i = 0, j, temp;
  bool did_swap = true;
  while (i < MAX - 1 && did_swap)
  {
    did_swap = false;
    for (j = 0; j < MAX - i - 1; j++)
    {
      if (arr[j] < arr[j + 1])
      {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        did_swap = true;
      }
    }
    i++;
  }
}

int main()
{
  int data_awal[MAX], data_urut[MAX];
  int i;

  cout << "	       LATIHAN 2" << endl;
  cout << "	    ~~~~~~~~~~~~~~\n";
  cout << "  Pengurutan Bubble Sort Dengan Flag" << endl;
  cout << "	  Secara Descending\n"
       << endl;

  cout << "Data acak (sebelum pengurutan):" << endl;
  for (i = 0; i < MAX; i++)
  {
    data_awal[i] = rand() % 100 + 1;
    cout << data_awal[i] << " ";
  }

  cout << "\n\nData setelah pengurutan descending:" << endl;
  for (i = 0; i < MAX; i++)
  {
    data_urut[i] = data_awal[i];
  }
  DescBubbleSortFlag(data_urut);
  for (i = 0; i < MAX; i++)
  {
    cout << data_urut[i] << " ";
  }
  cout << endl;

  return 0;
}
