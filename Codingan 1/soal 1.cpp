#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	char kata[] = {'p', 'e', 'n', 's', 'i', 't'};
	{
		cout << " Kata sebelum dibalik = " << kata << endl;
		cout << " Kata setelah dibalik =" << " ";
		
		for (int i = strlen(kata) - 1; i >= 0; i--)
		{
			cout << kata[i] << "";
		}
	}
	
	return 0;
}
