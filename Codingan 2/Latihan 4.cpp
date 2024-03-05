#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string jawab;
	
	while (true)
    {	
		string kata;
		string palindrome;
		stack<char>s;
		cout << "\nMasukkan kata sebelum dibalik : ";
		getline (cin , kata);
		
		for (int i = 0; i < kata.length(); i++)
		{
			s.push(kata[i]);
		}
		cout << "kata setelah dibalik : ";
		while(!s.empty())
		{
			palindrome += s.top();
			s.pop();
		}
		cout << palindrome;
		cout << "\n=================================" << endl;
			if (kata != palindrome)
			{
				cout << "kata tersebut bukan palindrom";
			}
			else if (kata == palindrome)
			{
				cout << "kata tersebut merupakan palindrom";
			}
			else 
			{
				cout << "Anda tidak memasukkan kata apapun" << endl;
			}
		cout << "\nmau mencoba lagi(y/t): ";
		cin >> jawab;
		cin.ignore();
		{
			if (jawab == "y")
	        {
	            continue;
	        }
	        else if (jawab == "t")
	        {
	            break;
		    }
		    else 
		    {
		    	cout << "input yang anda masukkan salah" << endl;
		    	break;
			}
		}
	}

	return 0;
}
