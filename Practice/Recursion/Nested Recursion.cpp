#include <iostream>
using namespace std;

void fun(int n){
    if(n > 100){
        return n-10;  //this is the condition where fun(n-1) will be returning any integer, instead of call fun(n), this should be the approach, se the dry run 
    }
    else{
        return fun(fun(n-1));
    }
}

int main(){

    fun(95);
    
return 0;
}

//fun(96)
//96 > 100, false
// thus it would add 11 and then call again, 96 + 11 = 107
//now it will check that 107 is greater than 100, thus it will not call and -10 107 which would be 97....... and so on
