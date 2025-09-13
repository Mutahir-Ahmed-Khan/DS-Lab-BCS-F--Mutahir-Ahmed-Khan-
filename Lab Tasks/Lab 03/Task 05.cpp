#include <iostream>
using namespace std;

class node{
    public: 
    int data; 
    node *next;

    node(int val){
        data = val; 
        next = NULL;
    }
};

class Dnode{
    public: 
    int data; 
    Dnode *next;
    Dnode *prev;

    Dnode(int val){
        data = val; 
        next = NULL;
        prev = NULL;
    }
};

class Cnode{
    public:
    int data;
    Cnode *next;

    Cnode(int val){
        data = val;
        next = NULL;
    }
};

class LL{
    public: 
    node *head;
    node *tail;

    public: 
    LL(){
        head = tail = NULL;
    }

    void pushFront(int val){
        node *newNode = new node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{ 
            newNode->next = head;
            head = newNode;
        }
    }

    void print(){ 
            node *temp = head;

            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
 
};

class DLL{
    public:
    Dnode *head;
    Dnode *tail;

    public:
    DLL(){
        head = tail = NULL; 
    }

    void pushFront(int val){
        Dnode *newDnode = new Dnode(val); 

        if(head == NULL){
            head = tail = newDnode;
        }

        else{
            newDnode->next = head; 
            head->prev = newDnode; 
            head = newDnode; 
        }
    }

    void print(){
        Dnode *temp = head;

        while(temp != NULL){
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    DLL Dconversion(LL &x){
        node *temp = x.head;
        DLL result;
        while (temp != NULL){
            result.pushFront(temp->data); 
            temp = temp -> next;
        }
        return result;
    }
};

class CLL{
    public:
    Cnode *head;
    Cnode *tail;

    CLL(){
        head = tail = NULL;
    }

    void pushFront(int val){
        Cnode *newCNode = new Cnode(val);

        if(head == NULL){
            head = tail = newCNode;
            tail->next = newCNode;
        }
        else{
            newCNode->next = head;
            head = newCNode;
            tail->next = head;
        }
    }

    void print(){
        if(head == NULL){
            cout << "The List is Empty" << endl;
            return;
        }
        cout << " -> ";
        cout << head->data << " -> ";
        Cnode *temp = head->next;

        while(temp != head){
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "->" << endl;
    }

    CLL Cconversion(LL &x){
        node *temp = x.head;
        CLL result;

        while(temp != NULL){
            result.pushFront(temp->data);
            temp = temp->next;
        }

        return result;
    }
};


int main(){

    LL ll;
    DLL dll;
    CLL cll; 
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    cout << "Singly List: ";
    ll.print();

    cout << "Doubly List: ";
    dll = dll.Dconversion(ll);
    dll.print();

    cout << "Circular Linked List: ";
    cll = cll.Cconversion(ll);
    cll.print();
    

    

return 0;
}
