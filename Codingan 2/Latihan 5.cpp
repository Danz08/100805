#include <iostream>
#include <cstring>
#define MAXSTACK 100

using namespace std;

typedef char itemType;
typedef struct {
    char item[MAXSTACK];
    int count;
} Stack;

Stack tumpukan;

void initializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(itemType, Stack *);
itemType Pop(Stack *);
int drjt(char);
void konversi_cetak(char[]);
bool infixValid = false;
bool hasil = false;

int main() {
    char tampung[MAXSTACK], jawab = 'y';

    cout << "MENGUBAH NOTASI INFIX MENJADI POSTFIX" << endl;
    cout << "DENGAN MEMANFAATKAN STRUKTUR STACK" << endl;
    do {
        initializeStack(&tumpukan);
        cout << "\nMasukan ekspresi dalam notasi infix : ";
        cin.getline(tampung, sizeof(tampung)); 
        int bukaKurung = 0;
        int tutupKurung = 0;
        int jumlahOperator = 0;
        int jumlahOperand = 0;
        for (int i = 0; i < strlen(tampung); i++) {
            if (tampung[i] == '(')
                bukaKurung++;
            else if (tampung[i] == ')')
                tutupKurung++;
            else if (tampung[i] == '+' || tampung[i] == '-' || tampung[i] == '*' || tampung[i] == '/' || tampung[i] == '^')
                jumlahOperator++;
            else if (tampung[i] >= '0' && tampung[i] <= '9')
                jumlahOperand++;
        }
        if (bukaKurung == tutupKurung && jumlahOperator == jumlahOperand - 1) {
            infixValid = true;
            hasil = true;
            if (hasil == true && infixValid == true) {
            	cout << "Ungkapan postfixnya : ";
                konversi_cetak(tampung);
            } else {
                cout << "notasi infix salah" << endl;
            }
        } else {
            infixValid = false;
            hasil = false;
            if (bukaKurung != tutupKurung)
                cout << "Notasi Infix Salah, Input tanda kurung Tidak Lengkap" << endl;
            else if (jumlahOperator -1)
                cout << "Notasi Infix Salah, Input Operand Tidak Lengkap" << endl;
            else if (jumlahOperand -1)
            	cout << "Notasi Infix Salah, Input Operator Tidak Lengkap" << endl;
        }
        cout << "\nMau mencoba lagi ? (y/t)" << endl;
        cin >> jawab;
        cin.ignore(); 
    } while (jawab == 'y' || jawab == 'Y');

    return 0;
}

void initializeStack(Stack *S) {
    S->count = 0;
}
int Empty(Stack *S) {
    return (S->count == 0);
}
int Full(Stack *S) {
    return (S->count == MAXSTACK);
}

void Push(itemType x, Stack *S) {
    if (Full(S)) {
        cout << "Stack penuh! Data tidak dapat masuk!" << endl;
    } else {
        ++(S->count);
        S->item[S->count] = x;
    }
}

itemType Pop(Stack *S) {
    itemType x;

    if (Empty(S)) {
        cout << "STACK KOSONG!" << endl;
        return -1;
    } else {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}

int drjt(char x) {
    if (x == '(') {
        return 0;
    } else if ((x == '+') || (x == '-')) {
        return 1;
    } else if ((x == '*') || (x == '/')) {
        return 2;
    } else if (x == '^') {
        return 3;
    } else {
        return -1;
    }
}

void konversi_cetak(char temp[]) {
    int i, pjg;
    char kar, smtr;

    pjg = strlen(temp) - 1;
    
    for (i = 0; i < pjg; i++) {
        kar = temp[i];
        switch (kar) {
            case '(':
                Push(kar, &tumpukan);
                break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                cout << kar;
                break;
            case '+': case '-': case '*': case '/': case '^':
                if ((Empty(&tumpukan)) || ((drjt(kar) > drjt(tumpukan.item[tumpukan.count])))) {
                    Push(kar, &tumpukan);
                } else {
                    do {
                        smtr = Pop(&tumpukan);
                        if (smtr != '(') 
                            cout << smtr;
                    } while (drjt(kar) < drjt(tumpukan.item[tumpukan.count]));
                    Push(kar, &tumpukan);
                }
                break;
            case ')':
                while (tumpukan.item[tumpukan.count] != '(') {
                    smtr = Pop(&tumpukan);
                    cout << smtr;
                }
                Pop(&tumpukan);
                break;
            default:
                break;
        }
    }
    while (!Empty(&tumpukan)) {
        smtr = Pop(&tumpukan);
        if (smtr != '(')
        cout << smtr;
    }
    cout << endl;
}
