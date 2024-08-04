#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 20

struct vertex {
    float x, y, jarak;
    int status;
    char nama[100];
    vertex *next, *connector;
};

typedef struct vertex *pvertex;

struct edge {
    float jarak;
    char titik1[100];
    char titik2[100];
    edge *next;
};

typedef struct edge *garis;

garis awalga = NULL, akhirga = NULL;

pvertex makeptree(float x, float y, char nama[]) {
    pvertex baru;
    baru = new vertex;
    baru->x = x;
    baru->y = y;
    baru->status = 0;
    baru->next = NULL;
    baru->connector = NULL;
    strcpy(baru->nama, nama);
    return baru;
}

void makevertex(pvertex *vertex, float x, float y, char nama[]) {
    pvertex p, q;
    p = makeptree(x, y, nama);
    q = *vertex;
    if (q == NULL)
        *vertex = p;
    else {
        for (; q->next; q = q->next) {}
        q->next = p;
    }
}

void makeedge(garis *awalga, garis *akhirga, char titik1[], char titik2[], float jarak) {
    garis baru;
    baru = new edge;
    baru->jarak = jarak;
    strcpy(baru->titik1, titik1);
    strcpy(baru->titik2, titik2);
    baru->next = NULL;
    if (*awalga == NULL) {
        *awalga = baru;
        *akhirga = baru;
    } else {
        (*akhirga)->next = baru;
        *akhirga = baru;
    }
}

void cek(pvertex vertex, int jumlah) {
    pvertex awal, p, q;
    float jarak;
    float min;
    float temp;
    awal = vertex;
    for (p = awal; p != NULL; p = p->next) {
        min = 999;
        p->status = 1;
        for (q = awal->next; q != NULL; q = q->next) {
            if (q->status != 1) {
                jarak = (((p->x) - (q->x)) * ((p->x) - (q->x))) + (((p->y) - (q->y)) * ((p->y) - (q->y)));
                jarak = sqrt(jarak);
                if (min > jarak) {
                    min = jarak;
                    p->jarak = min;
                    p->connector = q;
                }
            }
        }
        makeedge(&awalga, &akhirga, p->nama, p->connector->nama, p->jarak);
    }
    temp = (((p->x) - (awal->x)) * ((p->x) - (awal->x))) + (((p->y) - (awal->y)) * ((p->y) - (awal->y)));
    p->jarak = sqrt(temp);
    p->connector = awal;
}

void displayedge(pvertex vertex) {
    pvertex list = vertex;
    float tot = 0;
    cout << "\nTabel edge:" << endl;
    while (list->next != NULL) {
        cout << "\t" << list->nama << " ke " << list->connector->nama << " panjangnya: " << list->jarak << endl;
        tot += list->jarak;
        list = list->next;
    }
    cout << "\t" << list->nama << " ke " << list->connector->nama << " panjangnya: " << list->jarak << endl;
    tot += list->jarak;
    cout << endl;
}

void view(pvertex vertex) {
    pvertex p;
    float total = 0;
    p = vertex;
    cout << "\nView semua edge:" << endl;
    cout << "\nYang akan dilewati adalah>> ";
    cout << p->nama << " ";
    total += vertex->jarak;
    for (p = p->connector; strcmp(p->nama, vertex->nama) != 0; p = p->connector) {
        cout << p->nama << " ";
        total += p->jarak;
    }
    cout << p->nama << " ";
    cout << "\nTotal jaraknya>> " << total << endl;
}

int main() {
    char nama[MAX][100];
    float x[MAX], y[MAX];
    int jumlah;
    cout << "Masukkan jumlah vertex: ";
    cin >> jumlah;
    cout << "Masukkan koordinat vertex dan nama:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Koordinat vertex ke-" << i + 1 << ": ";
        cin >> x[i] >> y[i];
        cout << "Nama vertex ke-" << i + 1 << ": ";
        cin >> nama[i];
    }
    pvertex vertex = NULL;
    for (int i = 0; i < jumlah; i++) {
        makevertex(&vertex, x[i], y[i], nama[i]);
    }
    cek(vertex, jumlah);
    displayedge(vertex);
    view(vertex);
    return 0;
}

