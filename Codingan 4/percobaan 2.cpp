#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {

    int n,a,b,cek1,d,e,cek2,m;
    int *prima, *newprima;
    
    cout << "Masukan batasan suku ke-n prima = ";
    cin >> n;
	
	prima = (int*) malloc (n*sizeof(int));
	
	cout << "Deretan bilangan prima adalah	= ";
	
	if (n== NULL) {
		cout <<"Error on malloc\n";
		exit (0); } 
	else {
    	for (a = 2; a<=n; a++){
    	cek1 = 0;
    	for (b = 2; b < a; b++){
        	if (a % b == 0)
            	    {cek1 = 1;}
            }if (cek1 == 0)
                {cout<<a<<" ";}
        }
    cout << endl <<endl;
	}
	
	newprima =(int*) realloc(prima, m*sizeof(int));
	
	cout <<"Masukan batasan suku ke-m prima = ";
    cin >> m;
	
	
	cout <<"Deretan bilangan prima adalah	= ";
	
    if (m== NULL) {
		cout <<"Error on realloc\n";
		exit (0); } 
	else {
    	for (a = 2; a<=m; a++){
    	cek1 = 0;
    	for (b = 2; b < a; b++){
        	if (a % b == 0)
            	    {cek1 = 1;}
            }if (cek1 == 0)
                {cout<<a<<" ";}
        }
    cout << endl << endl;
	}
	free (prima);
	free (newprima);
	return 0;
}
	
