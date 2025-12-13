#include <iostream>
using namespace std;

class node{
    public: 
        node *next;
        int data;

        node(int v){
            data = v;
            next = NULL;
        }
};

class SeperateChaining{
    private: 
        static int const size = 10;
        node* table[size];
    public: 
        SeperateChaining(){
            for(int i = 0; i < size; i++){
                table[i] = NULL;
            }
        }

        int hash(int x){
            if(x < 0){
                return -1;
            }

            return x % 10;
        }

        void add(int val){
            int key = hash(val);

            node* newNode = new node(val);
            newNode->next = table[key];
            table[key] = newNode;
        }

        void deleteVal(int val){
            int key = hash(val);

            node* curr = table[key];
            node * prev = NULL;
            while(curr != NULL){
                if(curr->data == val){
                    if(curr == table[key]){
                        table[key] = table[key]->next;
                    }
                    else{
                        prev->next = curr->next;
                    }
                    delete curr;
                    cout << "deleted" << endl; 
                    return;
                }
                else{
                    prev = curr; 
                    curr = curr->next;
                }
            }
            cout << "==== VALUE NOT FOUND ====" << endl;
            return;
        }

        bool SK(int val){
            int key = hash(val);

            node *curr = table[key];
            while(curr != NULL){
                if(curr->data == val){
                    return true;
                }
                else{
                    curr = curr->next;
                }
            }

            return false;
        }

        void print(){
            for(int i = 0; i < size; i++){
                node* temp = table[i];
                cout << i << " : ";
                while(temp != NULL){
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL";
                cout << endl;
            }
        }

};

int main(){

    SeperateChaining sp;
    sp.add(35);
    sp.add(15);
    sp.add(25);

    sp.deleteVal(45);

    if(sp.SK(35)){
        cout << "Founded the Searched Value" << endl; 
    }
    else{
        cout << "not Founded" << endl;
    }
    
    sp.print();

return 0;
}
