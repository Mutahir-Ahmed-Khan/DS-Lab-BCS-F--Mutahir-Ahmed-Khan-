#include <iostream>
using namespace std;

class Box{
    public: 
    int *size;
    int *boxHeight;

    Box(int s){
        size = new int(s);
        boxHeight= new int;
    }

    //::Rule of three :: (Copy Constructor)
    //If you comment out this Rule then, both boxes will have the same value
    //Think of this as an ON/OFF switch for shallow and deep Copy OFF = Shallow and ON = Deep

    Box(const Box& other){
        size = new int(*other.size);
        boxHeight = new int(*other.boxHeight); 
    }


    //Functions
    void setBoxHeight(int h){
        *boxHeight  = h;
    }

    void display(){
        cout << "Box Height is: " << *boxHeight << endl; 
    }

    // :: Rule of three :: (Destructor)
    ~Box(){
        //In Shallow Copy, both with try to delete the same memory, as they point to same memory
        cout << "Destructor Destroying" << endl;
        delete size;
        delete boxHeight;    
    }

    
};

int main(){

    //For Shallow Copy, without custom copy assignment operator and  copy constructor
    //the code will run on shallow copy concept, as shown in the manual

    Box b1(10);
    Box b2 = b1;
    b1.setBoxHeight(11);

    cout << "Size of Box 1 is: " << sizeof(b1) << endl; 
    cout << "Size of Box 2 is: " << sizeof(b2) << endl;

    //Both have same memory,which is the basic definition 
    //of shallow copy 
    cout << endl;

    b1.display(); 
    b2.display();

    cout << endl; 

    b2.setBoxHeight(12);
    b1.display();
    b2.display();

    //For Deep Copy, Modifying b2 did not effect b1
    //For Shallow Copy, Modifying b2 effect b1 also, check by commenting out copy constructor part


return 0;
}

// CONCLUSION 

//Shallow Copy: Shares same Memory, but do not copy the actual data, and have an effect when the copied 
//or original instance will be modified, try to delete same memory, sometimes things crashes

//Deep Copy: Share same memory and also copy the original data, does not effect the original instances
//do not have data corruption or double deletion

