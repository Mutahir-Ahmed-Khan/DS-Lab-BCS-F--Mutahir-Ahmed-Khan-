#include <iostream>
using namespace std;

//Comments are for my own understanding

class BankAccount{ 
    public:
    int* balance;
    //Default One
    BankAccount(){
        balance = new int(0);
    }

    //Parameter one
    BankAccount(int p){
        balance = new int(p); //Doing this beacause of the pointer
    }

    //Deep Copy Constructor
    BankAccount(const BankAccount& other){
        balance = new int(*other.balance);
    }

    //Functions
    void printBalance(){
        cout << "Balance: $" << *balance << endl;
    }

    void deposit(int b){
        *balance = *balance - b;
    }

    ~BankAccount() {
        delete balance;
    }

};

int main(){
    //Question 01 Part(a)
    BankAccount a1; 
    cout << "Account 01, ";
    a1.printBalance();

    //Question 01 Part (b)
    BankAccount a2(1000);
    cout << "Account 02, ";
    a2.printBalance();

    //Question 01 Part (c) using a deep copy
    BankAccount a3;
    a3 = a2;

    
    a3.deposit(200);
    cout << "Account 03, ";
    a3.printBalance();


return 0;
}
