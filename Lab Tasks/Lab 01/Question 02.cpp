#include <iostream>
using namespace std;

class Exam{
    private: 
    string* stdname; 
    float* examDate; 
    float* score;

    public: 
    //Testing Shallow Copy
    Exam(){
        stdname = new string;
        examDate = new float;
        score = new float;
    }

    //Setters 
    void setStdName(string n){
        *stdname = n;
    }
    void setExamDate(float d){
        *examDate = d;
    }
    void setScore(float s){
        *score = s;
    }


    //Display the Info 
    void display(){
        cout << "Name: " << *stdname << endl;
        cout << "Exam Date: " << *examDate << endl;
        cout << "Score: " << *score << endl;
    }

    ~Exam(){
        cout << "Destructor is destroying" << endl; // Double Deletion - shallow Copy Issue
        delete stdname; 
        delete examDate;
        delete score;
    }

};
int main(){
    Exam s1;
    Exam s2;
    
    s1.setStdName("Mutahir Ahmed Khan");
    s1.setExamDate(12);
    s1.setScore(3.2);

    s1.display();
    s1 = s2;

    cout << endl;

    //Both are taking the same memory -- Shallow Copy
    cout << "Memory is same for both instance" << endl;
    cout << "Size of S1 is: " << sizeof(s1) << endl;
    cout << "Size of S2 is: " << sizeof(s2) << endl;

    cout << endl;

    cout << "Though, Values are not Copied" << endl; 
    s2.display();

return 0;
}
