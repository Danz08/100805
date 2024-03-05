#include <iostream>
using namespace std;

int fn_Cn(int);
int fn_Sn(int);

int fn_Cn(int angka)
{
    int hasil = 1;
    for (int i = 0; i < angka; i++)
    {
        hasil = 2 * hasil + 1;
    }
    return hasil;
}

int fn_Sn(int angka)
{
    int hasil = 0;
    for (int i = 0; i < angka; i++)
    {
        hasil = hasil + angka - 1;
    }
    return hasil;
}

int main()
{
    int bil, hasil_Cn, hasil_Sn;
    int urutan_Cn[bil], urutan_Sn[bil];

    cout << "Masukkan batas n untuk Cn = ";
    cin >> bil;
    
    for (int i = 0; i < bil; i++)
    {
        urutan_Cn[i] = fn_Cn(i + 1);
    }

   
    cout << "\nUrutan C" << bil << " = 2 * Cn-1 + 1 adalah: " << endl;
    for (int i = 0; i < bil; i++)
    {
        cout << urutan_Cn[i] << " ";
    }

	cout << endl;
    cout << "---------------------------------------\n" << endl;
    cout << "Masukkan batas n untuk Sn = ";
    cin >> bil;

    for (int i = 0; i < bil; i++)
    {
        urutan_Sn[i] = fn_Sn(i + 1);
    }

    
    cout << "\nUrutan S" << bil << " = Sn-1 + n - 1 adalah: " << endl;
    for (int i = 0; i < bil; i++)
    {
        cout << urutan_Sn[i] << " ";
    }

    return 0;
}
