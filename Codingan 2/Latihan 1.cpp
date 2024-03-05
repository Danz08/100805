#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> s;

    string input;
    cout << "Masukkan input : ";
    cin >> input;
    cout << "\nOutputnya yaitu : " ;
    for (int i = 0; i < input.length(); i++) 
	{
        if (isalpha(input[i])) 
        {
            s.push(input[i]);
        } 
        else if (input[i] == '*') 
        {
            if (!s.empty()) {
                cout << s.top();
                s.pop();
            }
        }
    } 
    cout << "\nTerimakasih, see you :)" << endl;
	   
    return 0;
}
