#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct tree {
    char info;
    tree *kiri;
    tree *kanan;
};

typedef struct tree *pohon;

pohon baru(char hrf) {
    pohon br;
    br = (pohon)malloc(sizeof(struct tree));
    br->info = hrf;
    br->kiri = NULL;
    br->kanan = NULL;
    return br;
}

void sisip(pohon ph, pohon sp) {
    pohon P, Q;
    P = ph;
    Q = ph;
    while ((sp->info != ph->info) && (Q != NULL)) {
        P = Q;
        if (sp->info < P->info)
            Q = P->kiri;
        else
            Q = P->kanan;
    }
    if (sp->info == P->info)
        cout << "Sudah Ada";
    else if (sp->info < P->info)
        P->kiri = sp;
    else
        P->kanan = sp;
}

void preorder(pohon ph) {
    if (ph != NULL) {
        cout << ph->info << " ";
        preorder(ph->kiri);
        preorder(ph->kanan);
    }
}

void inorder(pohon ph) {
    if (ph != NULL) {
        inorder(ph->kiri);
        cout << ph->info << " ";
        inorder(ph->kanan);
    }
}

void postorder(pohon ph) {
    if (ph != NULL) {
        postorder(ph->kiri);
        postorder(ph->kanan);
        cout << ph->info << " ";
    }
}

int main() {
    int j = 0;
    char input, jawab[2];
    pohon br, ssp;
    while (true) {
        cout << "Ketikkan Huruf: ";
        cin >> input;
        cin.ignore();
        if (j == 0)
            br = baru(input);
        else {
            ssp = baru(input);
            sisip(br, ssp);
        }
        cout << "Ada data lagi (y/t): ";
        cin >> jawab;
        cin.ignore();
        if ((strcmp(jawab, "Y") == 0) || (strcmp(jawab, "y") == 0)) {
            j++;
            continue;
        } else if ((strcmp(jawab, "T") == 0) || (strcmp(jawab, "t") == 0))
            break;
    }
    preorder(br);
    cout << endl;
    inorder(br);
    cout << endl;
    postorder(br);

    return 0;
}
