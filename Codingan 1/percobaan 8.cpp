#include <iostream>
using namespace std;

char strA[80] = "ABCDE";
char strB[80];

int main()
{

	char *pA; 
	char *pB; 
	cout << strA << endl;
	pA = strA; 
	cout << pA << endl; 
	pB = strB;
	cout << endl;
	while(*pA != '\0')
	{
		*pB++ = *pA++;
	}
	
	*pB = '\0'; 
	cout << strB << endl;
	
	return 0;
}

