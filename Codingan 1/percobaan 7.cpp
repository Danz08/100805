#include <iostream>
using namespace std;

int main()
{
	int my_array[] = {1,23,17,4,-5,100};
	int *ptr;
	int i;
	ptr = &my_array[0]; /* var pointer ptr menunjuk ke elemen ke-
	0 dari myarray */
	cout << "";
	for (i = 0; i < 6; i++)
	{
		cout << "My_array[" << i << "] = " << my_array[i] << " ";
		cout << "ptr + = " << i << " = " << *ptr + i << endl;
	}
	
	return 0;
}
