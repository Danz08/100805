#include <iostream>
using namespace std;

const int MAX_VALUE = 100;
const int MIN_VALUE = 1;

int guess;
int high = MAX_VALUE;
int low = MIN_VALUE;
char choice;

int main() {
    cout << "Think about a number between " << MIN_VALUE << " and " << MAX_VALUE << ".\n\n";
    guess = (high + low) / 2;

    while ((high - low) != 1) {
        cout << "Is your number less than or equal to " << guess << "?\nEnter 'y' for yes or 'n' for no.\n\n";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            high = guess;
            guess = (high + low) / 2;
        } else if (choice == 'n' || choice == 'N') {
            low = guess;
            guess = (high + low) / 2;
        } else {
            cout << "Incorrect choice." << endl;
        }
    }

    cout << "Your number is: " << high << ".\n";

    return 0;
}

