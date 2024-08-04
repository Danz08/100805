#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 17

void Merge(int arr[], int left, int median, int right)
{
  int temp[right - left + 1];
  int i = left, j = median + 1, k = 0;
  while (i <= median && j <= right)
  {
    if (arr[i] >= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= median)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  for (int p = 0; p < k; p++)
    arr[left + p] = temp[p];
}

void MergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int median = left + (right - left) / 2;
    MergeSort(arr, left, median);
    MergeSort(arr, median + 1, right);
    Merge(arr, left, median, right);
  }
}

int main()
{
  int data_awal[MAX], data_urut[MAX];
  int i;

  srand(time(0));

  cout << ">>>>>>>>>>-----------------------------------------------------------"
          "------<<<<<<<<<<"
       << endl;
  cout << ">>>>>>>>>>           Program Pengurutan Merge Sort Secara Descending       "
          "<<<<<<<<<<"
       << endl;
  cout << ">>>>>>>>>>---------------------------------------------------------"
          "--------<<<<<<<<<<"
       << endl;
  cout << " \n";
  cout << "Data acak (sebelum pengurutan): \n"
       << endl;
  cout << " \n";
  cout << "-------------------------------------------------------------------"
          "------------------"
       << endl;
  cout << "|";
  for (i = 0; i < MAX; i++)
  {
    data_awal[i] = rand() % 100 + 1;
    cout << " " << data_awal[i] << " |";
  }
  cout << "\n-------------------------------------------------------------------"
          "------------------"
       << endl;

  cout << "\n\nData setelah pengurutan descending : \n\n"
       << endl;
  cout << "\n-------------------------------------------------------------------"
          "------------------"
       << endl;
  cout << "|";
  for (i = 0; i < MAX; i++)
    data_urut[i] = data_awal[i];
  MergeSort(data_urut, 0, MAX - 1);
  for (i = MAX - 1; i >= 0; i--)
    cout << " " << data_urut[i] << " |";
  cout << "\n-------------------------------------------------------------------"
          "------------------"
       << endl;

  return 0;
}

