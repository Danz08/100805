#include <iostream>
using namespace std;
int main ()
{
	int n[ 10 ];
	int i,j;
	
	for ( i = 0; i < 10; i++ )
	{
		n[ i ] = i + 100;
	}
	
	for (j = 0; j < 10; j++)
	{
		cout << "Element[" << j << "] = " << n[j] << endl;
	}
	
	return 0;
}
