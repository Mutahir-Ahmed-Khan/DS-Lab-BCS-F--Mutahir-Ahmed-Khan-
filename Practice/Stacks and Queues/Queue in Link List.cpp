#include <iostream>
using namespace std;

class node{
    public: 
    int data; 
    node* next; 

    node(int val){
        data = val; 
        next = NULL;
    }  
};

class Queue{
    node* head; 
    node* tail; 

    public: 
    Queue(){
        head = tail = NULL;
    }
    

    void enqueue(int val){ //Insert data on tail
        node* newNode = new node(val); 

        if(empty()){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue(){ // Deleting from the Front
        if(empty()){
            cout << "List is Empty" << endl;
            return; 
        }
        
        node* temp = head;
        head = head->next; 
        delete temp;
    }

    int front(){
        if(empty()){
            cout << "List is Empty" << endl; 
            return -1;
        }
        else{
            return head->data;
        }
    }

    bool empty(){
        return head == NULL;
    }
};

int main(){

    Queue q; 

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    while(!q.empty()){
        cout << q.front() << " "; 
        q.dequeue();
    }

    cout << endl; 


return 0;
}
