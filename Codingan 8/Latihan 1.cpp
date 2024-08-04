#include <iostream>
using namespace std;

struct Node {
    int bilPokok;
    int pangkat;
    Node *before;
    Node *next;
};

Node *head, *tail;

void init();
int isEmpty();
void Hapus(int bilP);
void sisipAwal(int BilP, int Pangkat);
void sisipTA(int BilP, int Pangkat);
void cekSisip(int BilP, int Pangkat);
void tampil();

void init() {
    head = NULL;
    tail = NULL;
    
    // Menyisipkan nilai polinomial P1
    cekSisip(6, 8); // Bilangan pokok 6, pangkat 8
    cekSisip(8, 7); // Bilangan pokok 8, pangkat 7
    cekSisip(5, 5); // Bilangan pokok 5, pangkat 5
    cekSisip(1, 3); // Bilangan pokok 1, pangkat 3
    cekSisip(15, 0); // Bilangan pokok 15, pangkat 0
    
    // Menyisipkan nilai polinomial P2
    cekSisip(3, 9); // Bilangan pokok 3, pangkat 9
    cekSisip(4, 7); // Bilangan pokok 4, pangkat 7
    cekSisip(3, 4); // Bilangan pokok 3, pangkat 4
    cekSisip(2, 3); // Bilangan pokok 2, pangkat 3
    cekSisip(2, 2); // Bilangan pokok 2, pangkat 2
    cekSisip(10, 0); // Bilangan pokok 10, pangkat 0
}

int isEmpty() {
    if (tail == NULL)
        return 1;
    else
        return 0;
}

void Hapus(int bilP) {
    Node *hapus = head;
    Node *cur;

    if (hapus->bilPokok == bilP) {
        head = hapus->next;
        hapus->before = NULL;
    } else {
        while (hapus->bilPokok != bilP) {
            cur = hapus;
            hapus = hapus->next;
        }
        cur->next = hapus->next;
        cur->before = hapus->before;
    }
}

void sisipAwal(int BilP, int Pangkat) {
    Node *baru = new Node;
    Node *cari = head;

    if (cari->pangkat < Pangkat) {
        baru->next = head;
        baru->before = NULL;
        head = baru;
    }

    baru->bilPokok = BilP;
    baru->pangkat = Pangkat;
    
}

void sisipTA(int BilP, int Pangkat) {
    Node *baru, *stl;
    Node *cari = head;
    baru = new Node;
    stl = new Node;

    baru->bilPokok = BilP;
    baru->pangkat = Pangkat;

    while (cari->pangkat > Pangkat) {
        stl = cari;
        cari = cari->next;
        if (cari == NULL) {
            break;
        }
    }

    baru->next = cari;
    stl->next = baru;
    baru->before = stl;
    
}

void cekSisip(int BilP, int Pangkat) {
    Node *bantu = head;
    Node *baru;
    baru = new Node;

    if (tail == NULL) {
        baru->bilPokok = BilP;
        baru->pangkat = Pangkat;
        baru->next = NULL;

        if (isEmpty() == 1) {
            head = tail = baru;
            tail->next = NULL;
            tail->before = baru;
        } else {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = baru;
            baru->before = temp;
        }
        
    } else {
        while (bantu != NULL) {
            if (bantu->pangkat > Pangkat) {
                sisipTA(BilP, Pangkat);
                break;
            } else {
                sisipAwal(BilP, Pangkat);
                break;
            }
        }
    }
}

void tampil() {
    cout << "\nData yang ada di list saat ini :\n";
    Node *bantu = head;

    if (isEmpty() == 0) {
        while (bantu != NULL) {
            if (bantu->bilPokok != 1)
                cout << bantu->bilPokok;
            if (bantu->pangkat != 0)
                cout << "x^" << bantu->pangkat;
            if (bantu->next != NULL)
                cout << " + ";
            bantu = bantu->next;
        }
        cout << endl;
    } else
        cout << "Data Kosong...\n"
             << endl;
}

int main() {
    init();
    int pil, BilP, Pangkat;

    while (true) {
        cout << ">>>Merepresentasikan sebuah bilangan polinomial dengan double linked list<<<" << endl;
        cout << "============================================================================" << endl;
        cout << "\t1. Menyisipkan bilangan polinomial " << endl;
        cout << "\t2. Menghapus bilangan polinomial " << endl;
        cout << "\t3. Tampil " << endl;
        cout << "\t4. Keluar " << endl;
        cout << "Masukkan pilihan : ";
        cin >> pil;

        switch (pil) {
            case 1:
                tampil();
                cout << "\nInsert bilangan polinomial" << endl;
                cout << "Bilangan pokok : ";
                cin >> BilP;
                cout << "Pangkat : ";
                cin >> Pangkat;
                cekSisip(BilP, Pangkat);
                tampil();
                break;
            case 2:
                tampil();
                cout << "Bilangan polinomial yang akan dihapus : " << endl;
                cout << "Bilangan pokok : ";
                cin >>
                BilP;
                Hapus(BilP);
                tampil();
                break;
            case 3:
                tampil();
                break;
            case 4:
                cout << "Terima kasih...\n";
                exit(0);
                break;
            default:
                cout << "Pilihan anda tidak tersedia..." << endl;
                break;
        }
    }

    return 0;
}

