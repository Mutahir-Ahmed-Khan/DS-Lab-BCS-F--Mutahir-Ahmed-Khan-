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
            cout << "Node Created with value " << val << endl;
            return;
        }
        else{ 
            newNode->next = head;
            head = newNode;
            cout << "Node Added with Value " << val << endl;
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
            cout << "Deleted from the Back" << endl;
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
            cout << "Deleted from the Front" << endl; 
        }
    }

    void print(){ 
            node *temp = head;

            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }

            cout << "NULL";
        }

    void pushBack(int val){
        node *newNode = new node(val);
        
        if(head == NULL){
            head = tail = newNode;;
            cout << "Node Created with value " << val << endl;
            return;
        }
        else{ 
            tail->next = newNode;
            tail = newNode;
            cout << "Node Added with Value " << val << endl;
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
            cout << "Added at " << pos << " Successfully" << endl;
        }
    }

    void search(int val){
        node *temp = head;
        int count = 0;
        if(head == NULL){
            cout << "Linked List is Empty" << endl; 
        }
        else{
            while(temp != NULL){
                if(temp->data == val){
                    cout << "Founded at Position " << count << endl;
                    return;
                }

                temp = temp->next;
                count++;
            }
        }
    }
};

int main(){

    cout << "LINKED LIST PRACTICE (4 MAIN FUNCTIONS):" << endl;
    cout << endl;
    cout << "PUSHING FRONT" << endl;
    LL ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);

    cout << endl;
    cout << "PRINTING" << endl;
    ll.print();

    cout << endl;
    cout << endl;
    cout << "PUSHING BACK" << endl;
    ll.pushBack(4);
    ll.print();

    cout << endl; 
    cout << endl; 
    cout << "POPPING FRONT" << endl; 
    ll.popFront();
    ll.print();

    cout << endl;
    cout << endl;
    cout << "POPPING BACK" << endl;
    ll.popBack();
    ll.print();
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "LINKED LIST PRACTICE (INSERTING):" << endl;
    LL ll2;
    ll2.pushFront(3);
    ll2.pushFront(2);
    ll2.pushFront(1);
    ll2.print();

    cout << endl; 
    cout << endl;
    cout << "INSERTING AT POSITITION" << endl;
    ll2.insert(4,2);
    ll2.print();

    cout << endl;
    cout << endl;
    cout << "SEARCHING..." << endl;
    ll2.search(1);
return 0;
}
