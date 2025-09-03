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

class Linked{
    private: 
    node *head;
    node *tail;

    public:
    Linked(){
        head = NULL;
        tail = NULL;
    }

    void pushFront(int val){
        node *newNode = new node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void print(){
        if(head == NULL){
            cout << "The List is Empty" << endl;
        }
        else{
            node *temp = head;
            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void pushBack(int val){
        node *newNode = new node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront(){
        if(head == NULL){
            cout << "List is Empty" << endl; 
        }
        else{
            node *temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void popBack(){
        if(head == NULL){
            cout << "The List is Empty" << endl;
        }
        else{
            node *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void insert(int val, int pos){
        int total = 0;
        node *temp = head; 
        while(temp != NULL){
            temp = temp->next;
            total++;
        }
        delete temp;

        if(pos < 0){
            cout << "Error Ofcourse" << endl;
        }
        else if(pos > total){
            cout << "Out Of Bound" << endl;
            return;
        }
        else if(pos == 0){
            pushFront(val);
        }
        else{
            node *newNode = new node(val);
            node *temp = head;
            for(int i = 0; i < pos-1; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    void MiddleManGone(){
        node *temp = head;
        int count = 0;
        int idx;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        cout << "Counter " << count <<  endl;
        if(count % 2 == 0){
            cout << "No Middle Man" << endl;
        }
        else{
            idx = count / 2;
            node *temp = head;
            for(int i = 0; i < idx; i++){
                temp = temp->next;
                delete temp;
            }
        }
    }
};


int main(){

    Linked ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    ll.print();
    cout << endl;
    ll.pushBack(4);
    ll.print();
    cout << endl;
    ll.popFront();
    ll.print();
    cout << endl;
    ll.popBack();
    ll.print();
    cout << endl;
    ll.insert(5,3);
    ll.insert(7,2);
    ll.print();
    ll.MiddleManGone();
    ll.print();


return 0;
}
