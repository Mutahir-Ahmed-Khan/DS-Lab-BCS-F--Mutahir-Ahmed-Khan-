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
    node *top;

    public: 
    LL(){
        top = NULL;
    }

    void pushFront(int val){
        node *newNode = new node(val);

        if(top == NULL){
            top = newNode;
            return;
        }
        else{ 
            newNode->next = top;
            top = newNode;
        }
    }

    void popFront(){
        if(top == NULL){
            cout << "Linked List is Empty" << endl;
        }
        else{
            node *temp = top;
            top = top->next;
            cout << "Top is now " << top->data << endl;
            temp->next = NULL;
            delete temp; 
        }
    }

    void print(){ 
            node *temp = top;

            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    
};

int main(){

    LL ll;
    ll.pushFront(10);
    ll.pushFront(20);
    ll.pushFront(30);
    ll.popFront();
    ll.print();


return 0;
}
