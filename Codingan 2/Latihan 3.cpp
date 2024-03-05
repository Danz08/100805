#include<iostream>
#include<stack>

using namespace std;

int main()
{
	string kalimat;
	stack<char> s;
	
	cout << "Kalimat : ";
	getline(cin, kalimat);
	
	for(int i = 0; i < kalimat.length(); i++)
	{
		s.push(kalimat[i]);
	}
	cout << "\nHasil Sebelum Dibalik :" << kalimat << endl;
	cout << "Hasil setelah dibalik : ";
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
	
	return 0;
}
