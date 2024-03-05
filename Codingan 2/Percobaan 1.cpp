#include <iostream>
#define MAXSTACK 5
using namespace std;

typedef int ItemType;
//Definisi struktur stack

typedef struct
{
	int Item[MAXSTACK]; //Array yang berisi data tumpukan 
	int Count; //menunjukkan indeks data paling atas dari stack
}Stack;

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

void push(ItemType x, Stack *S)
{
	if (S->Count == MAXSTACK)
		cout << "Stack penuh! Data tidak dapat masuk!" << " ";
	else
	{
		S->Item[S->Count] = x;
		++(S->Count);
	}
}

int Pop(Stack *S)
{
	if (S->Count == 0) //stack kosong
		cout << "Stack masih kosong!" << " ";
	else
	{
		--(S->Count);
		return (S->Item[S->Count]);
	}
}

int main()
{
	int i, input;
	Stack tumpukan;
	
	InitializeStack(&tumpukan);
	
	for ( i = 0; i < MAXSTACK; i++)
	{
		cout << "Masukkan isi Stack ke " << i + 1 << " Adalah :" << " ";
		cin >> input;
		push(input, &tumpukan);
	}
	
	cout << "-----------------------------------" << endl;
	
	for (i = MAXSTACK; i > 0; i--)
	{
		cout << "Isi stack ke " << i << " Adalah : " << " ";
		cout << Pop(&tumpukan) << endl;
	}
}
