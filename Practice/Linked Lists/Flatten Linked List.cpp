#include <iostream>
using namespace std;
class node{
    public: 
    int data; 
    node *next;
    node *child;

    node(int val){
        data = val;
        next = NULL;
        child = NULL;
    }
};

class LinkedList{
    private: 
    node *head;
    node *tail;

    public:
    LinkedList(){
        head = tail = NULL;
    }

    node* getHead(){
        return head;
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

    void print(){
        node *temp = head;

        if(head == NULL){
            cout << "The List is Empty" << endl;
        }
        
        while(temp != NULL){
            cout << temp->data << "-";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

node *flatten(node *head){
    if(head == NULL){
        cout << "List is Empty" << endl;
    }

    node *curr = head;
    while(curr != NULL){
        if(curr->child != NULL){
            //Flatten the child Nodes
            node *next = curr->next;
            curr->next = flatten(curr->child);
            curr->child = NULL;

            //Finding the Tail
            while(curr->next != NULL){
                curr = curr->next;
            }

            //Attaching the tail with next ptr
            if(next != NULL){
                curr->next = next;
            }
        }

        curr = curr->next;
    }

    return head;
}

void printResult(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

    LinkedList list01;
    LinkedList list02;

    list01.pushBack(1);
    list01.pushBack(2);
    list01.pushBack(3);
    
    
    list02.pushBack(4);
    list02.pushBack(5);

    node *head01 = list01.getHead();
    node *secondNode = head01->next;

    secondNode->child = list02.getHead();

    cout << "List 01: ";
    list01.print();
    cout << "           |";
    cout << endl;
    cout << "List 02:   ";
    list02.print();

    cout << endl;

    cout << "Output: ";
    node *FinalHead = flatten(head01);
    printResult(FinalHead);
    


return 0;
}
