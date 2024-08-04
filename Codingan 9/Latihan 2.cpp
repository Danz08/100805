#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int compare(const void *a, const void *b);

void RecursiveCombination(char *str, char *data, int length, int index) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        data[index] = str[i];
        if (index == length) {
            cout << data << " ";
        } else {
            RecursiveCombination(str, data, length, index + 1);
        }
    }
}

void Combination(char *str, int length) {
    int len = strlen(str);
    char *data = (char *)malloc(sizeof(char) * (len + 1));
    data[len] = '\0';
    qsort(str, len, sizeof(char), compare);
    RecursiveCombination(str, data, length - 1, 0);
    free(data);
}

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    int N;
    cout << "Masukkan jumlah karakter: ";
    cin >> N;

    char str[N+1];
    cout << "Masukkan karakter-karakter (tanpa spasi): ";
    cin >> str;

    cout << "Semua kombinasi dari " << str << " adalah: " << endl;
    Combination(str, N);
    return 0;
}

