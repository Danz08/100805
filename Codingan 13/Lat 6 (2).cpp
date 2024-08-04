#include <iostream>
using namespace std;

#define MAX_SIZE 100

int* insertX(int n, int arr[], int x, int pos) {
    n++;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    return arr;
}

int main() {
    int data[MAX_SIZE];
    int size, key, found, elemen, pilihan, position;
    int i; // Declare i here

    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter elements in array: ";
    for (int x = 0; x < size; x++) {
        cin >> data[x];
    }
    cout << "------------------" << endl;
    cout << "1. Insert Before" << endl;
    cout << "2. Insert After" << endl;
    cout << "3. Delete" << endl;

    cout << "Masukkan Pilihan : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "\nInsert Before : ";
            cin >> key;

            found = 0;
            for (i = 0; i < size; i++) { // Use the previously declared i
                if (data[i] == key) {
                    found = 1;
                    break;
                }
            }

            if (found == 1) {
                cout << "Insert Element :";
                cin >> elemen;

                insertX(size, data, elemen, i + 1);

                for (int z = 0; z < size + 1; z++)
                    cout << data[z] << " ";
                cout << endl;
            } else {
                cout << "Key not found" << endl;
            }
            break;

        case 2:
            cout << "\nInsert After : ";
            cin >> key;

            found = 0;
            for (i = 0; i < size; i++) { // Use the previously declared i
                if (data[i] == key) {
                    found = 1;
                    break;
                }
            }

            if (found == 1) {
                cout << "Insert Element :";
                cin >> elemen;

                insertX(size, data, elemen, i + 2);

                for (int z = 0; z < size + 1; z++)
                    cout << data[z] << " ";
                cout << endl;
            } else {
                cout << "Key not found" << endl;
            }
            break;

        case 3:
            cout << "Enter the location where you wish to delete element: ";
            cin >> position;

            if (position >= size + 1) {
                cout << "Deletion not possible." << endl;
            } else {
                for (int c = position - 1; c < size - 1; c++)
                    data[c] = data[c + 1];

                cout << "Data : ";
                for (int c = 0; c < size - 1; c++)
                    cout << " " << data[c];
            }
            break;
    }

    return 0;
}

