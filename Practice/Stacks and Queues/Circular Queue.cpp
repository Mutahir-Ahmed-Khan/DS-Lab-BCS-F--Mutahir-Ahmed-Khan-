#include <iostream>
using namespace std;

class circularQueue{
    public: 
    int* arr;
    int currSize, cap;
    int f,r;

    circularQueue(int size){
        cap = size;
        arr = new int(cap);
        f = 0;
        r = -1;

        void push(int val){
            if(full){
                return;
            }
            else{
                r = (r+1)%cap;
                arr[r] = data;
                currSize++;
            }
        }

        void pop(){
            if(empty){
                return;
            }
            else{
                f = (f+1)%cap;
                curSize--;
            }
        }

        int front(){
            return arr[f];
        }

        bool empty(){
            return currSize == 0;
        }

        bool full(){
            currSize == cap;
        }
    }
};

int main(){

return 0;
}
