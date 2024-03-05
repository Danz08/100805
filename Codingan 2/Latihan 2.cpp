#include<iostream>
#include<stack>

using namespace std;

void desimalKeBiner(int n)
{
	stack<int> s;
	while (n > 0)
	{
		int rem = n%2;
		s.push(rem);
		n= n/2;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

void desimalKeOktal(int n)
{
	stack<int>s;
	while (n > 0)
	{
		int rem = n%8;
		s.push(rem);
		n = n/8;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

void desimalKeHeksa(int n)
{
	stack<int>s;
	while(n>0)
	{
		int rem = n%16;
		if(rem < 10)
		{
			s.push(rem);
		}
		else
		{
			s.push(rem);
		}
		n = n/16;
	}
	while (!s.empty())
	{
		int digit = s.top();
		if (digit < 10)
		{
			cout << digit;
		}
		else
		{
			cout << (char)('A' + digit - 10);
		}
		s.pop();
	}
	cout << endl;
}

int main()
{
	string jawab;
	while (true)
    {
		int n;
		cout << "Masukkan bilangan desimal : ";
		cin >> n;
		cout <<"\nBilangan Biner	: ";
		desimalKeBiner(n);
		cout <<"Bilangan Oktal	: ";
		desimalKeOktal(n);
		cout << "Bilangan Heksadesimal : ";
		desimalKeHeksa(n);
		if (!n)
        {
            cout << "\nInput tidak valid. Mengakhiri program." << endl;
            break;
        }
        
	    
		cout << "mau mencoba lagi(y/t): ";
		cin >> jawab;
		{
			if (jawab == "y")
	        {
	            continue;
	        }
	        else if (jawab == "t")
	        {
	            break;
		    }
		}
		if (n)
	    {
	       	cout << "input salah, mengakhiri program..." << endl;
	       	break;
		}
        
	}
    return 0;
}
