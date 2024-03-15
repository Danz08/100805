#include <iostream> 
#include <conio.h> 

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

        if (head == NULL) { 
            head = temp; 
            tail = temp; 
        } 
        else {     
            tail->next = temp; 
            tail = temp; 
        } 
    } 

    void display() { 
        node *temp = head; 

        while (temp != NULL) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
    } 
}; 

int main() { 
    list obj; 
    int value, numNodes;

    cout << ">>>MEMBACA ATAU MENAMPILKAN LINKED LIST<<<" << endl; 
    cout << "\nMasukkan Jumlah Node: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; ++i) { 
        cout << "\nMasukkan Nilai Untuk Node ke-" << i + 1 << ": ";
        cin >> value;
        obj.createnode(value);
    }

    cout << "\nMenampilkan Nilai Node yang telah dimasukkan :\n"; 
    cout << "\n--------------------------------" << endl;
	obj.display(); 
	
    return 0;
}
