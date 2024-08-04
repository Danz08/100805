#include <iostream>

using namespace std;

int fibo(int x) {
    if (x <= 0 || x <= 1)
        return x;
    else
        return fibo(x - 2) + fibo(x - 1);
}

int main() {
    int n;
    cout << "Masukkan jumlah deret = ";
    cin >> n;
    cout << "Deret Fibonacci dari " << n << " = ";
    for (int i = 0; i < n; i++)
        cout << fibo(i) << " ";
    cout << endl;
    return 0;
}
