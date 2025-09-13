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
            tail->next = head; //Beacuse of the condition of the circular linked list
            cout << val << " Value Added at Front* " << endl; 
        }
        else{
            newNode->next = head; 
            head = newNode;
            tail->next = head;
            cout << val <<" Value Added at Front" << endl;
        }
    }

    void print(){
        //In Circular Linked List Printing is a bit different, we would be hard coding 
        //the value of head and then traverse the list while temp(which is pointing to head's next node)
        // is equal to head again
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
            cout << val << " Value Added at Back*" << endl;
        }
        else{
            newNode->next = head;
            tail->next = newNode; 
            tail = newNode;
            cout << val << " Value Added at Back" << endl;
        }
    }

    void popFront(){
        if(head== NULL){ //Case to handle the Empty List
            cout << "The List is Empty " << endl;
        }
        else if(head == tail){ // Case to handle single node in a list
            cout << "Deleting a Sinle node with value " << head->data << endl;
            delete head; 
            head = tail = NULL;
        }
        else{  //When there are two or more nodes
            node *temp = head;
            head = head->next; 
            tail->next = head;
            temp->next = NULL;
            cout << "Deleting the value " << temp->data << endl; 
            delete temp;
        }
    }

    void popBack(){
        if(head == NULL){
            cout << "The List is Empty ";
            return;
        }
        else if(head == tail){
            cout << "Deleting a Single Node with value " << tail->data << endl;
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
            cout << "Deleting th Value " << temp->data << endl;
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
