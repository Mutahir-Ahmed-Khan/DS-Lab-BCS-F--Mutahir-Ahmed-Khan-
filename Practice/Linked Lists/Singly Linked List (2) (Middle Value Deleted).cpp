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
    else if(head == tail){  
        delete head;
        head = tail = NULL;
    }
    else{
        node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
}


    void insert(int val, int pos){
        int total = 0;
        node *temp = head; 
        while(temp != NULL){
            temp = temp->next;
            total++;
        }

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
        if(head == NULL){
            cout << "List is Empty" << endl; 
        }

        int count = 0;
        node *temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }

        if(count % 2 == 0){
            cout << "No Middle Man" << endl;
            return;
        }

        int idx = count / 2;
        temp = head;

        if(idx == 0){
            delete head; 
            head = tail = NULL;
            return;
        }

        for(int i = 0; i < idx -1 ; i++){
            temp = temp->next;
        }

        node *delNode = temp->next;
        temp->next = delNode->next;
        if(delNode == tail){
            tail = temp;
        }
        delete delNode;

    }
};


int main(){

    Linked ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    ll.pushFront(5);
    ll.pushFront(10);
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
