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

    class SinglyLinkedList{
        private:
        node *head;
        node *tail;

        public: 
        SinglyLinkedList(){
            head = tail = NULL; 
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
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        
        node *getHead(){
            return head; 
        }

        void setHead(node *h){
            head = h; 
        }
    };

    node *reverse(node *head, int k){
        if(head == NULL){
            cout << "The List is Empty" << endl; 
            return NULL; 
        }

        int count = 0;
        node *prevNode = NULL, *curr = head, *next = NULL;

        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
            count++;
        }

        if(next != NULL){
            head->next = reverse(next,k);
        }

        return prevNode;
    }

    int main(){

        SinglyLinkedList SLL;
        SLL.pushBack(1);
        SLL.pushBack(2);
        SLL.pushBack(3);
        SLL.pushBack(4);
        SLL.pushBack(5);
        SLL.pushBack(6);
        SLL.pushBack(7);
        SLL.pushBack(8);
        SLL.print();

        int k = 3; 
        node *newHead = reverse(SLL.getHead(), k);
        SLL.setHead(newHead);

        cout << endl;
        cout << "Output: ";
        SLL.print();

    return 0;
    }
