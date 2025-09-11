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
    static int counter; 
    LL(){
        head = tail = NULL;
    }

    void pushFront(int val){
        node *newNode = new node(val);
        if(head == NULL){
            head = tail = newNode;
            counter++; 
            return;
        }
        else{
            counter++; 
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
            counter--;
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
            counter--; 
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
            head = tail = newNode;
            counter++;
            return;
        }
        else{ 
            tail->next = newNode;
            tail = newNode;
            counter++;
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
            counter++;
        }
    }

    void isPalindrome(){
        int tempArr[counter];
        int reverse[counter];
        node *temp = head;
        int o = 0;
        if(head == NULL){
            cout << "Empty Linked List" << endl;
        }
        else{
            while(temp != NULL){
                tempArr[o] = temp->data;
                temp = temp->next;
                o++;
            }
        }

        for(int i = 0; i < counter; i++){
            reverse[i] = tempArr[counter - i - 1];
        }

        temp = head;
        int k = 0;
        bool isPal = true;
        while(temp != NULL) {
        if(temp->data != reverse[k]) {
            isPal = false;
            break;
        }
        temp = temp->next;
        k++;
    }

    
        if(isPal)
            cout << "Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;
    }
};

int LL::counter = 0;

int main(){

    LL ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(2);
    ll.pushFront(1);
    ll.print();
    cout << endl;
    ll.isPalindrome();

return 0;
}
