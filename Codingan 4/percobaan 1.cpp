#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, f1 = 0, f2 = 1, next = 0;
    int *fibo;
    
	cout << "Masukan Batas Deret Bilangan Fibonacci :  ";
    cin >> n;
    fibo=(int*)malloc(n*sizeof(int));
    
	cout<<endl;
    cout << "Deret Fibonacci		: ";
    
	if (n== NULL) {
		cout<<"Error on malloc\n";
		exit(0); } 
	else {
    	for (int i = 1; i <= n; ++i)
    	{
       		if(i == 1)
    		{
            	cout << " " << f1<<" ";
            	continue;
        	}
        	if(i == 2)
        	{
            	cout << f2 << " ";
            	continue;
        	}
        	next = f1 + f2;
        	f1 = f2;
        	f2 = next;
        	cout << next << " ";
    	}
    	return 0;
	}
	free (fibo);
}

