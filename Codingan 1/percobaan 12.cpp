#include <iostream> 
#include <cstring>
using namespace std;

struct dtnilai
{
	char nrp[10]; 
	char nama[20]; 
	double nilai;
};

void tampil(dtnilai *p)
{
	cout << p->nrp << " ";
	cout << p->nama << " ";
	cout << p->nilai << endl;
}

int main()
{
	dtnilai my_struct;
	dtnilai *st_ptr; 
	st_ptr = &my_struct; 
	
	strcpy(my_struct.nrp,"01");
	cout << my_struct.nrp << endl;
	
	strcpy(my_struct.nama,"Arini"); 
	cout << my_struct.nama << endl;
	 
	my_struct.nilai = 63.6; 
	tampil(st_ptr);
	
	return 0;
}


