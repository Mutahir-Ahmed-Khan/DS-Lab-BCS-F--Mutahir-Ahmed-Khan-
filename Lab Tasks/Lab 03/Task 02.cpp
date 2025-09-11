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
    public: 
    node *head;
    node *tail;

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
    
};

LL merge(LL &x, LL &y){
        LL sortedList;
        node *temp1 = x.head;
        node *temp2 = y.head;

        //Key Note: try solvong the Question on array approach 

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data < temp2->data){
                sortedList.pushBack(temp1->data);
                temp1 = temp1->next;
            }
            else{
                sortedList.pushBack(temp2->data);
                temp2 = temp2->next;
            }
        }

        //From the Example
        //Until here the temp1 would be pointing towards null, but temp2 is pointing 
        // towards 6, thus have to point it to NULL while storing its data in the Sorted List

        while(temp1 != NULL){
            sortedList.pushBack(temp1->data);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            sortedList.pushBack(temp2->data);
            temp2 = temp2->next;
        }

        return sortedList;
    }

int main(){

    LL ll;
    LL merged;
    cout << "Linked List A: ";
    ll.pushFront(1);
    ll.pushBack(3);
    ll.pushBack(5);
    ll.print();
    cout << endl;
    cout << "Linked List B: ";
    LL ll2;
    ll2.pushFront(2);
    ll2.pushBack(4);
    ll2.pushBack(6);
    ll2.print();
    cout << endl;

    merged = merge(ll,ll2);
    cout << "Sorted List: ";
    merged.print();

return 0;
}
