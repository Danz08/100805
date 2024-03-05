//implementasi algoritma untuk mengubah infix menjadi postfix
#include <iostream>
#include <cstring>
#define MAXSTACK 100
using namespace std;

typedef char ItemType;
typedef struct 
{
	char Item[MAXSTACK]; //Array yang berisi data tumpukan
	int Count; //menunjukkan indeks data paling atas dari stack
}Stack;

Stack tumpukan;

void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop (Stack *);
int drjt(char);
void konversi_cetak(char []);

int main()
{
	char tampung [MAXSTACK], jawab;
	
	cout << "MENGUBAH NOTASI INFIX MENJADI POSTFIX" << endl;
	cout << "DENGAN MEMANFAATKAN STRUKTUR STACK" << endl;
	do 
	{
		InitializeStack(&tumpukan);
		cout << endl;
		cout << "Masukkan ekspresi dalam notasi infix : ";
		cin.getline(tampung, sizeof(tampung));
		cout << "Ungkapan postfix = ";
		konversi_cetak(tampung);
		cout << endl;
		cout << "Mau mencoba lagi (y/t) ? " << endl;
		cin >> jawab;
	} while ((jawab == 'y') || (jawab == 'Y'));
	return 0;
}

void InitializeStack(Stack *S)
{
	S->Count = 0;
}

int Empty(Stack *S)
{
	return (S->Count == 0);
}

int Full(Stack *S)
{
	return (S->Count == MAXSTACK);
}

void Push(ItemType x, Stack *S)
{
	if (Full (S)) //stack penuh
	cout << "Stack sudah penuh! Data tidak dapat dimasukkan!";
	else
	{
		++(S->Count);
		S->Item[S->Count] = x;
	}
}

ItemType Pop(Stack *S)
{
	ItemType x;
	if (Empty (S)) // Stack kosong
	{
	
		cout << "Stack Kosong!" << endl;
	}
	else
	{
		x = (S->Item[S->Count]);
		--(S->Count);
		return x;
	}
}

int drjt(char x) //menentukan derajat operator
{
	if(x == '(')
		return 0;
	else if ((x == '+') || (x == '-'))
		return 1;
	else if ((x == '*') || (x == '/'))
		return 2;
	else if ((x == '^'))
		return 3;
	else
		return -1; //invalid operator
}

void konversi_cetak(char temp[]) {
    int i, pjg, valid = 1;
    char kar, smtr;
    
    pjg = strlen(temp);
    for (i=0; i<pjg; i++) {
        kar = temp[i]; //membaca input per karakter
        switch(kar) {
            case '(' :
                Push(kar, &tumpukan);
                break;
            case '0': case '1': case '2': case '3': case '4': case '5' : case '6': case '7': case '8': case'9':
                cout << kar;
                break;
            case '+': case '-': case '*': case '/': case '^':
                if((Empty(&tumpukan)) || (drjt(kar) > drjt(tumpukan.Item[tumpukan.Count])))
                    Push(kar, &tumpukan);
                else {
                    do {
                        smtr = Pop(&tumpukan);
                        cout << smtr;
                    } while (drjt(kar) < drjt(tumpukan.Item[tumpukan.Count]));
                    Push(kar, &tumpukan);
                }
                break;
            case ')' :
                while(tumpukan.Item[tumpukan.Count] != '(') {
                    smtr = Pop(&tumpukan);
                    cout << smtr;
                }
                Pop(&tumpukan);
                break;
            default :
                valid = 0;
                cout << "INVALID STATEMENT" << endl;
                break;
        }
    }
    if((valid != 0) && (!Empty(&tumpukan))) {
        smtr = Pop(&tumpukan);
        cout << smtr;
    }
}
