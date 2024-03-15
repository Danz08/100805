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
        head=NULL;
        tail=NULL;
    }   

    void tambahsimpul(int value) {
        node *temp=new node; 
        temp->data=value; 
        temp->next=NULL; 

        if(head==NULL) {
            head=temp; 
            tail=temp; 
            temp=NULL; 
        } 
        else {
            tail->next=temp; 
            tail=temp; 
        } 
    } 

    void display() {
        node *temp=head; 
        while(temp!=NULL) { 
            cout<<temp->data<<" "; 
            temp=temp->next; 
        } 
    } 

    void sisipAkhir(int value) {
        node *temp=new node; 
        temp->data=value; 
        temp->next=NULL; 

        if(head==NULL) {
            head=temp; 
            tail=temp; 
        } 
        else {
            tail->next=temp; 
            tail=temp; 
        } 
    } 

    void sisipAwal(int value) {
        node *temp=new node; 
        temp->data=value; 
        temp->next=head; 
        head=temp; 
    } 

    void sisipPosisi(int pos, int value) {
        node *pre=new node; 
        node *cur=new node; 
        node *temp=new node; 
        cur=head; 

        for(int i=1;i<pos;i++) { 
            pre=cur; 
            cur=cur->next; 
        } 

        temp->data=value; 
        pre->next=temp;    
        temp->next=cur; 
    } 

    void hapusAwal() {
        node *temp=new node; 
        temp=head; 
        head=head->next; 
        delete temp; 
    } 

    void hapusAkhir() {
        node *current=new node; 
        node *previous=new node; 
        current=head; 

        while(current->next!=NULL) { 
            previous=current; 
            current=current->next; 
        } 

        tail=previous; 
        tail->next=NULL; 
        delete current; 
    } 

    void hapusPosisi(int pos) {
        node *current=new node; 
        node *previous=new node; 
        current=head; 

        for(int i=1;i<pos;i++) { 
            previous=current; 
            current=current->next; 
        } 

        previous->next=current->next; 
    } 
}; 

int main() { 
    list obj; 
    int value, numNodes;

    cout<<"\t>>>SINGLE LINKED LIST<<<\n"; 
    cout<<"Masukkan jumlah node: ";
    cin>>numNodes;

    for(int i=0; i<numNodes; i++) {
        cout<<"Masukkan nilai untuk node "<< i+1 <<": ";
        cin>>value;
        obj.tambahsimpul(value);
    }

    cout<<"\nTampilkan semua nodes\n"; 
    obj.display(); 
    cout<<"\n";

    cout<<"\nSisipkan di akhir\n"; 
    obj.sisipAkhir(12); 
    obj.display(); 
    cout<<"\n";

    cout<<"\nSisipkan di awal\n"; 
    obj.sisipAwal(14); 
    obj.display(); 
    cout<<"\n";

    cout<<"\nSisipkan pada posisi 5\n"; 
    obj.sisipPosisi(5,16); 
    obj.display(); 
    cout<<"\n";

    cout<<"\nHapus node pertama\n"; 
    obj.hapusAwal(); 
    obj.display(); 
    cout<<"\n";

    cout<<"\nHapus node terakhir\n"; 
    obj.hapusAkhir(); 
    obj.display(); 
    cout<<"\n";

    cout<<"\nHapus node pada posisi ke-4\n"; 
    obj.hapusPosisi(4); 
    obj.display(); 
    cout<<"\n";

    getch(); 
    return 0; 
}

