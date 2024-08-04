#include <iostream>
using namespace std;

const int MAX_VALUE = 100;
const int MIN_VALUE = 1;

int guess;
int high = MAX_VALUE;
int low = MIN_VALUE;
char choice;

int main() {
    cout << "===========================================\n";
    cout << "||             GUESSING GAME             ||\n";
    cout << "===========================================\n";
    cout << "Pikirkan sebuah angka dari " << MIN_VALUE << " sampai " << MAX_VALUE << "!\n";

    guess = (high + low) / 2;

    while ((high - low) != 1) {
        cout << "\nApakah nomor yang kamu pikirkan kurang dari " << guess << "?\nJawab: y (ya) atau t (tidak)? ";
        cin >> choice;

        if (choice == 'yes' || choice == 'y') {
            high = guess;
            guess = (high + low) / 2;
        } else if (choice == 'no' || choice == 't') {
            low = guess;
            guess = (high + low) / 2;
        } else {
            cout << "Jawaban Salah" << endl;
        }
    }

    cout << "\nNomor yang kamu pikirkan pasti ini " << high << " :D.\n\n";

    return 0;
}

