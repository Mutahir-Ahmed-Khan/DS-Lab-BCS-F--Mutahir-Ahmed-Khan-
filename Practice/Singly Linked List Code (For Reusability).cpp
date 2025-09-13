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

class LL{
    private: 
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

    void popBack(){
        if(head == NULL){
            cout << "Linked List is Empty" << endl;
        }
        else{
            node *temp = head;
            while(temp->next->next){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void popFront(){
        if(head == NULL){
            cout << "Linked List is Empty" << endl;
        }
        else{
            node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp; 
        }
    }

    void print(){ 
            node *temp = head;

            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

    void pushBack(int val){
        node *newNode = new node(val);
        
        if(head == NULL){
            head = tail = newNode;;
            return;
        }
        else{ 
            tail->next = newNode;
            tail = newNode;
            
        }
    }

    void insert(int val, int pos){
        node *newNode = new node(val);
        if(pos < 0){
            cout << "ERROR OFC" << endl;
        }
        else if(pos == 0){
            pushFront(val);
        }
        else{
            node *temp = head;
            for(int i = 0; i < pos-1; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    
};

int main(){

    LL ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    ll.print();

return 0;
}
