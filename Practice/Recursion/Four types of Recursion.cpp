#include <iostream>
using namespace std;

int func1(int n);

//Example of tail Function
void tail(int n){
    if(n == 0){
        return;
    }
    else{
        return tail(n - 1);  //there is nothing being called by the function
    }
}

void nontail(int n){
    if(n == 0){
        return;
    }
    else{
        return nontail(n - 1); //Last thing is not recusive call
        cout << n << endl; 
    }
}


//Example of Indirect Function
int func2(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * func1(n-1);
    }
}

int func1(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * func2(n - 1);
    }
}

//Example of Direct Function
void printNumber(int n){
    //Base Case
    if(n == 1){
        cout << n << endl;
        return;
    }
    cout << n << endl;
    printNumber(n-1);
}

int main(){

    // printNumber(4);
    cout << "Result of indirect Recursion: " << func1(5) << endl;

return 0;
}
