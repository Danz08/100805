#include <iostream>
using namespace std;

int main() {
    int P1[11] = {15, 0, 0, 1, 0, 5, 0, 8, 6, 0, 0};
    int P2[11] = {10, 0, 2, 2, 3, 0, 0, 4, 0, 3, 0};
    int P3[11] = {5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int bil[12] = {0};

    cout << "------------------Aritmatika Polinomial-------------------" << endl;
    cout << "Diketahui : " << endl;
    cout << "P1 = 6x^8 + 8x^7 + 5x^5 + x^3 + 15" << endl;
    cout << "P2 = 3x^9 + 4x^7 + 3x^4 + 2x^3 + 10" << endl;
    cout << "P3 = x^2 + 5" << endl;
    cout << "==========================================================" << endl;
    
    cout << "\nPenjumlahan = " << endl;
    cout << "P1 + P2 = (6x^8 + 8x^7 + 5x^5 + x^3 + 15) + (3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10)" << endl;
    cout << "P1 + P2 = ";
    for (int a = 0; a < 10; a++) {
        bil[a] += P1[a] + P2[a];
    }
    for (int a = 11; a >= 0; a--) {
        if (bil[a] != 0) {
            if (a > 1)
                cout << bil[a] << "x^" << a << " + ";
            else if (a == 1)
                cout << bil[a] << "x" << " + ";
            else if (a >= 0)
                cout << bil[a] << endl;
        }
    }
    
    cout << "\nPengurangan = " << endl;
    cout << "P1 - P2 = (6x^8 + 8x^7 + 5x^5 + x^3 + 15) - (3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10)" << endl;
    cout << "P1 - P2 = ";
    for (int a = 0; a < 10; a++) {
        bil[a] = P1[a] - P2[a];
    }
    for (int a = 11; a >= 0; a--) {
        if (bil[a] != 0) {
            if (a > 1) {
                if (bil[a] > 1)
                    cout << " + " << bil[a] << "x^" << a;
                else if (bil[a] < 0)
                    cout << " " << bil[a] << "x^" << a;
            } else if (a == 1)
                cout << bil[a] << "x" << " ";
            else if (a >= 0)
                cout << " + " << bil[a] << endl;
        }
    }
    
    int bil2[12] = {0};
    cout << "\nPerkalian = " << endl;
    cout << "P1 * P3 = (6x^8 + 8x^7 + 5x^5 + x^3 + 15) * (x^2 + 5)" << endl;
    cout << "P1 * P3 = ";
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 4; b++) {
            bil2[a + b] += P1[a] * P3[b];
        }
    }
    for (int a = 11; a >= 0; a--) {
        if (bil2[a] != 0) {
            if (a > 1)
                cout << bil2[a] << "x^" << a << " + ";
            else if (a == 1)
                cout << bil2[a] << "x" << " + ";
            else if (a == 0)
                cout << bil2[a] << endl;
        }
    }

    int bil3[12] = {0};
    cout << "\nTurunan = " << endl;
    cout << "P2 = (3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10)" << endl;
    cout << "P2 = ";
    for(int a = 11; a >= 0 ; a--) {
        bil3[a] = P2[a] * a ;
        if(bil3[a] != 0) {
        	if (a > 0) {
            cout << bil3[a] << "x^" << (a - 1) << " + ";
        	}
        	else {
        	cout << bil3[a - 1];
			}
        }
        else if(a==0){
        	cout << "0" << endl;
		}
    }
    
    return 0;
}

