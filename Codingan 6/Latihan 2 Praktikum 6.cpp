#include <iostream> 
#include<conio.h> 
using namespace std; 
 
class polyll { 
private: 
    struct polynode { 
        float coeff; 
        int exp; 
        polynode* link; 
    } * p; 
public: 
    polyll(); 
    void poly_append(float c, int e); 
    void display_poly(); 
    void poly_add(polyll& l1, polyll& l2); 
    ~polyll(); 
}; 
polyll::polyll() 
{ 
    p = NULL; 
    } 
void polyll::poly_append(float c, int e) 
{ 
    polynode* temp = p; 
    if (temp == NULL) { 
        temp = new polynode; 
        p = temp; 
    } 
    else { 
        while (temp->link != NULL) 
            temp = temp->link; 
        temp->link = new polynode; 
        temp = temp->link; 
    } 
    temp->coeff = c; 
    temp->exp = e; 
    temp->link = NULL; 
} 
void polyll::display_poly() 
{ 
    polynode* temp = p; 
    int f = 0; 
 
    cout << endl; while (temp != NULL) { if (f != 0) { if (temp->coeff> 0) 
                cout << " + "; 
            else 
                cout << " "; } if (temp->exp != 0) 
                            cout << temp->coeff << "x^" << temp->exp; 
        else 
            cout << temp->coeff; 
        temp = temp->link; 
        f = 1; 
    } 
} 
void polyll::poly_add(polyll& l1, polyll& l2) 
{ 
    polynode* z; 
    if (l1.p == NULL && l2.p == NULL) 
        return; 
    polynode *temp1, *temp2; 
    temp1 = l1.p; 
    temp2 = l2.p; 
    while (temp1 != NULL && temp2 != NULL) { 
        if (p == NULL) { 
            p = new polynode; 
            z = p; 
        } 
        else { 
            z->link = new polynode; 
            z = z->link; 
        } 
        if (temp1->exp < temp2->exp) { 
            z->coeff = temp2->coeff; 
            z->exp = temp2->exp; 
            temp2 = temp2->link; 
                    } 
        else { 
            if (temp1->exp > temp2->exp) { 
                z->coeff = temp1->coeff; 
                z->exp = temp1->exp; 
                temp1 = temp1->link; 
            } 
            else { 
                if (temp1->exp == temp2->exp) { 
                    z->coeff = temp1->coeff + temp2->coeff; 
                    z->exp = temp1->exp; 
                    temp1 = temp1->link; 
                    temp2 = temp2->link; 
                } 
            } 
        } 
    } 
    while (temp1 != NULL) { 
        if (p == NULL) { 
            p = new polynode; 
            z = p; 
        } 
        else { 
            z->link = new polynode; 
            z = z->link; 
        } 
        z->coeff = temp1->coeff; 
        z->exp = temp1->exp; 
                temp1 = temp1->link; 
    } 
    while (temp2 != NULL) { 
        if (p == NULL) { 
            p = new polynode; 
            z = p; 
        } 
        else { 
            z->link = new polynode; 
            z = z->link; 
        } 
        z->coeff = temp2->coeff; 
        z->exp = temp2->exp; 
        temp2 = temp2->link; 
    } 
    z->link = NULL; 
} 
polyll::~polyll() 
{ 
    polynode* q; 
    while (p != NULL) { 
        q = p->link; 
        delete p; 
        p = q; 
    } 
} 
int main() 
{ 
 cout<<"\t\tBILANGAN POLINOMIAL\n\n"; 
 cout<<"---------------------------------------------------"; 
    polyll p1; 
    p1.poly_append(6, 8); 
    p1.poly_append(8, 7); 
    p1.poly_append(5, 5); 
    p1.poly_append(1, 3); 
    p1.poly_append(15,0); 
    cout << "\nPOLINOMIAL PERTAMA :\n"; 
    p1.display_poly(); 
    polyll p2; 
    p2.poly_append(3, 9); 
    p2.poly_append(4, 7); 
    p2.poly_append(3, 4); 
    p2.poly_append(2, 3); 
    p2.poly_append(2, 2); 
    p2.poly_append(10, 0); 
    cout<<"\n";cout<<"---------------------------------------------------"; 
 cout << "\nPOLINOMIAL KEDUA :\n"; 
    p2.display_poly(); 
    polyll p3; 
    p3.poly_add(p1, p2); 
    cout<<"\n";cout<<"---------------------------------------------------"; 
 cout << "\nHASIL POLINOMIAL : \n"; 
     p3.display_poly(); 
    return 0;; 
}
