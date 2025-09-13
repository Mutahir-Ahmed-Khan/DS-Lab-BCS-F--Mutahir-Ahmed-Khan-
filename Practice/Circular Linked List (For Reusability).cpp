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

class CL{
    private: 
    node *head;
    node *tail;

    public:
    CL(){
        head = tail = NULL;
    }

    void pushFront(int val){
        node *newNode = new node(val);

        if(head == NULL){
            head = tail = newNode; 
            tail->next = head;  
        }
        else{
            newNode->next = head; 
            head = newNode;
            tail->next = head;
        }
    }

    void print(){
        if(head == NULL){
            cout << "The List is Empty" << endl;
            return;
        }

        cout << head->data << "->";
        node *temp = head->next;

        while(temp != head){
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void pushBack(int val){
        node *newNode = new node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            newNode->next = head;
            tail->next = newNode; 
            tail = newNode;
        }
    }

    void popFront(){
        if(head== NULL){ 
            cout << "The List is Empty " << endl;
        }
        else if(head == tail){ 
            delete head; 
            head = tail = NULL;
        }
        else{ 
            node *temp = head;
            head = head->next; 
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void popBack(){
        if(head == NULL){
            cout << "The List is Empty ";
            return;
        }
        else if(head == tail){
            delete tail;
            head = tail = NULL;
        }
        else{
            node *temp = tail;
            node *prev = head;

            while(prev->next != tail){
                prev = prev->next;
            }

            prev->next = head;
            tail->next = NULL;
            tail = prev;
            delete temp;
        }
    }
};

int main(){

    CL cl;
    cl.pushFront(1);
    cl.pushFront(2);
    cl.pushFront(3);
    cl.pushBack(4);
    cl.pushBack(5);
    cl.popFront();
    cl.popBack();
    cl.print();

return 0;
}
