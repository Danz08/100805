#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 20

using namespace std;

void Merge(int arr[], int left, int median, int right){
	int temp[MAX];
	int kiri1, kanan1, kiri2, kanan2, i, j;
	kiri1 = left;
	kanan1 = median;
	kiri2 = median + 1;
	kanan2 = right;
	i = left;
	
	while ((kiri1 <= kanan1) && (kiri2 <= kanan2)){
		if (arr[kiri1] <= arr[kiri2]){
			temp[i] = arr[kiri1];
			kiri1++;
		}else{
			temp[i] = arr[kiri2];
			kiri2++;
		}
		i++;
	}
	while(kiri1 <= kanan1){
		temp[i] = arr[kiri1];
		kiri1++;
		i++;
	}
	while(kiri2 <= kanan2){
		temp[i] = arr[kiri2];
		kiri2++;
		i++;
	}
	j = left;
	while (j <= right){
		arr[j] = temp[j];
		j++;
	}
}

void MergeSort(int arr[], int l, int r){
	int med;
	if(l < r){
		med = (l + r) / 2;
		MergeSort(arr, l, med);
		MergeSort(arr, med + 1, r );
		Merge(arr, l, med, r);
	}
}

int main(){
	int data_awal[MAX], data_urut[MAX];
	int i;
	time_t k1, k2;
	
	cout << "Sebelum Pengurutan : ";
	for(i = 0; i < MAX; i++){
		srand(time(NULL) * (i + 1));
		data_awal[i] = rand() % 100 + 1;
		cout << data_awal[i] << " ";
	}
	
	cout << "\nSetelah Pengurutan : ";
	for(i = 0; i < MAX; i++)
		data_urut[i] = data_awal[i];
		
	time(&k1);
	MergeSort(data_urut, 0, MAX - 1);
	time(&k2);
	for(i = 0; i < MAX; i++)
		cout << data_urut[i] << " ";
	cout << "\nWaktu : " << k2-k1;
	
	return 0;
}
