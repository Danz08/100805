#include <iostream>
#include <cstdlib>
#define MAX 10

int Data[MAX];
using namespace std;

int SequentialSearch(int x){
	int i = 0;
	bool ketemu;
	
	while((!ketemu) && (i < MAX)){
		if(Data[i] == x)
			ketemu = true;
		else
			i++;
	}
	if(ketemu)
		return i;
	else
		return -1;
}

int main(){
	int i;
	
	//pembangkit bilangan random
	srand(0);
	
	//membangkitkan bilangan 
	cout << "Data :";
	for(i = 0; i < MAX;i++){
		Data[i] = rand() / 1000 + 1;
			cout << Data[i] << " ";
	}
	int Kunci;
	
	cout << "\nKunci : ";
	cin >> Kunci;
	
	int ketemu = SequentialSearch(Kunci);
	if(ketemu > 0)
		cout << "Data ditemukan pada posisi " << ketemu;
	else
		cout << "Data tidak ditemukan";
	return 0;
}
