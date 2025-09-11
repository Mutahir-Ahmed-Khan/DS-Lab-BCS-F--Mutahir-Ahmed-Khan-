#include <iostream>
using namespace std;

class node{
    public: 
    int data;
    node *next;
    node *prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLL{
    private:
    node *head;
    node *tail;

    public:
    DLL(){
        head = tail = NULL; //Structure of Empty List
    }

    void pushFront(int val){
        node *newNode = new node(val); //New node is in action

        if(head == NULL){
            head = tail = newNode;
            cout << "Empty List Added a new Node with value "  << val << endl;
        }

        else{
            newNode->next = head; //New node is created and its next point to head
            head->prev = newNode; //head previous pointing towards new node
            head = newNode; //New node becoming new head of the list //Mistake it would not be newNode = head
            cout << "New Node Added to the List with value " << val << endl;
        }
    }

    void pushBack(int val){
        node *newNode = new node(val);

        if(head == NULL){
            head = tail = newNode;
            cout << "New Node Added in an Empty List" << endl;
        }
        else{
            newNode->prev = tail; //New Node's next pointing towards tail
            tail->next = newNode; //Tail's next pointing towards newNode
            tail = newNode; //updating teh tail
            cout << "New Node added at the Back with value " << val << endl;
        }
    }

    void print(){
        node *temp = head;

        while(temp != NULL){
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void popFront(){
        if(head == NULL){
            cout << "The List is Empty" << endl;
            return;
        }
        node *temp = head; //1. Storing Head address into a temp 
        head = head->next;// 2. updating the head
        if(head != NULL){   //3.checking if head does not points to a NULL 
            head->prev = NULL;  //breaking connections
        } 
            temp->next = NULL;
            cout << "Deleted from Front with value " << temp->data << endl;
            delete temp;
    
    }

    void popBack(){
       node *temp = tail;
       tail = tail->prev;
       if(tail != NULL){
            tail->next = NULL;
       }

       temp->prev = NULL;
       cout << "Deleting from Back with value " << temp->data << endl;
       delete temp;
    
    }

};

int main(){

    DLL dll;
    dll.pushFront(1);
    dll.pushFront(2);
    dll.pushFront(3);
    dll.pushBack(4);
    dll.popFront();
    dll.popBack();
    dll.print();

return 0;
}
