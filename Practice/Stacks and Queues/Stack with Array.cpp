#include <iostream>
using namespace std;

class Stack{
    private: 
    int* arr;
    int top;
    int size;

    public:
    Stack(int s){
        size = s;
        arr = new int[s];
        top = -1;
    }

    void push(int val){
        if(top >= (size - 1)){
            cout << "Stack OverFlow" << endl;
            return;
        }
        else{
            top++;
            arr[top] = val; 
        }
    }

    void pop(){
        if(top < 0){
            cout << "Stack UnderFLow" << endl;
            return;
        }
        else{
            top--;
        }
    }

    int topElement(){
        return arr[top];
    }

    bool isEmpty(){
        if(top < 0){
            return true; 
        }
        else{
            return false;
        }
    }

    ~Stack(){
        delete[] arr;
    }

};

int main(){

    Stack a(4);

    a.push(10);
    a.push(20);
    a.push(30);

    while(!a.isEmpty()){
        cout << a.topElement() << " ";
        a.pop();
    }
    
    
return 0;
}
