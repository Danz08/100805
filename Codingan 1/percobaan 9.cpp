#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 20

int main()
{
    int *fibo;
    int i;
    fibo = new int [MAX + 1];
    *(fibo + 0) = 0;
    *(fibo + 1) = 1;
    *(fibo + 2) = 1;

    for (int i = 3; i <= MAX; i++)
        *(fibo + i) = (*(fibo + i - 2) + *(fibo + i - 1));

    cout << MAX << " Bilangan Fibonaci Pertama adalah : " << endl;
    for (int i = 0; i < MAX; i++)
        cout << *(fibo + i) << " ";
        
    delete[] fibo; // Menggunakan operator delete[] untuk dealokasi memori

    return 0;
}

