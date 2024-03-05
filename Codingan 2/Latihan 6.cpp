#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;
const int MAXSTACK = 100;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    
    for (int i = 0; i < infix.length(); i++) {
        if (isdigit(infix[i])) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Hapus '(' dari stack
        } else { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(infix[i])) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int hasilPostfix(string postfix) {
    stack<int> s;
    
    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            s.push(postfix[i] - '0');
        } else {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            switch (postfix[i]) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }
    
    return s.top();
}

int main() 
{
    char MAXSTACK, jawab;
	
	cout << "MENGUBAH NOTASI INFIX MENJADI POSTFIX" << endl;
	cout << "DENGAN MEMANFAATKAN STRUKTUR STACK" << endl;
	do 
	{
		string infix;
	    cout << "\nMasukkan ekspresi dalam notasi infix: ";
	    getline(cin, infix);
	    
	    string postfix = infixToPostfix(infix);
	    cout << "Ekspresi postfix: " << postfix << endl;
	    
	    int hasil = hasilPostfix(postfix);
	    cout << "Hasil: " << hasil << endl;
    
		cout << "Mau mencoba lagi (y/t) ? " << endl;
		cin >> jawab;
		cin.ignore();
	} while ((jawab == 'y') || (jawab == 'Y'));
	return 0;
}
