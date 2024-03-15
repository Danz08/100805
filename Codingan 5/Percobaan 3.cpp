#include<iostream> 
#include<conio.h> 

using namespace std;

struct node {
    int data;
    node *next;
}; 

class list {
private:
    node *head, *tail;
public:
    list() {
        head = NULL;
        tail = NULL;
    }

    void createnode(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        } else {     
            tail->next = temp;
            tail = temp;
        } 
    } 

    void display() {
        node *temp = head;
        while(temp != NULL) {
            cout << temp->data << " "; 
            temp = temp->next;
        } 
    } 

    void insert_position(int pos, int value) {
        if(pos == 1) { 
            node *temp = new node; 
            temp->data = value; 
            temp->next = head; 
            head = temp; 
            return; 
        }

        node *pre = new node; 
        node *cur = head; 

        for(int i = 1; i < pos; i++) { 
            pre = cur; 
            cur = cur->next; 
        } 

        node *temp = new node; 
        temp->data = value; 
        pre->next = temp;    
        temp->next = cur; 
    }

    bool search(int value) {
        node *temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Simpul dengan nilai " << value << " ditemukan pada posisi ke-" << position << ".\n";
                return true;
            }
            temp = temp->next;
            position++;
        }
        cout << "Simpul dengan nilai " << value << " tidak ditemukan.\n";
        return false;
    }
}; 

int main() { 
    list obj; 
    int pos, value;

    cout << ">>>MENCARI SEBUAH SIMPUL TERTENTU. TAMBAHKAN KONDISI JIKA YANG DICARI ADALAH DATA YANG PALING DEPAN<<<\n"; 
    cout << "\nMasukkan jumlah node: ";
    int numNodes;
    cin >> numNodes;
    for(int i = 0; i < numNodes; i++) {
        cout << "Masukkan nilai untuk node " << i + 1 << ": ";
        cin >> value;
        obj.createnode(value);
    }
    cout << "\nMenampilkan semua node\n"; 
    obj.display(); 
    cout << "\n\nMasukkan nilai yang ingin Anda cari: "; 
    cin >> value; 
    obj.search(value); 
	 
    return 0;
}
