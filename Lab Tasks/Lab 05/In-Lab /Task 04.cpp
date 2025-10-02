#include <iostream>
using namespace std;

int ackermann(int m, int n){
    if(m == 0){
        return n + 1;
    }
    else if(m > 0 && n == 0){
        return ackermann(m-1, 1);
    }
    else if(m > 0 && n > 0){
        return ackermann(m - 1, ackermann(m , n - 1));
    }  
}

int main(){

//DRY-RUN FOR INPUT (2,2)
   
// ackermann(2,2)
// m>0 and n>0 → ackermann(1, ackermann(2,1))
// compute ackermann(2,1)
// ackermann(2,1) = ackermann(1, ackermann(2,0))
// compute ackermann(2,0)
// m>0 and n=0 → ackermann(1,1)
// compute ackermann(1,1)
// ackermann(1,1) = ackermann(0, ackermann(1,0))
// compute ackermann(1,0)
// m>0 and n=0 → ackermann(0,1) = 2
// ackermann(1,1) = ackermann(0,2) = 3
// ackermann(2,0) = 3
// ackermann(2,1) = ackermann(1,3)
// compute ackermann(1,3)
// ackermann(1,3) = ackermann(0, ackermann(1,2))
// compute ackermann(1,2)
// ackermann(1,2) = ackermann(0, ackermann(1,1))
// ackermann(1,1) = 3 (from step 5)
// so ackermann(1,2) = ackermann(0,3) = 4
// ackermann(1,3) = ackermann(0,4) = 5
// ackermann(2,1) = 5
// ackermann(2,2) = ackermann(1,5)
// compute ackermann(1,5)
// ackermann(1,5) = ackermann(0, ackermann(1,4))
// compute ackermann(1,4)
// ackermann(1,4) = ackermann(0, ackermann(1,3))
// ackermann(1,3) = 5 (from step 10)
// so ackermann(1,4) = ackermann(0,5) = 6
// ackermann(1,5) = ackermann(0,6) = 7
// ackermann(2,2) = 7



return 0;
}
