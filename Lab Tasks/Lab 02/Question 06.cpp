#include <iostream>
using namespace std;

class safePointer{
    private: 
    int* integer;

    public: 
    safePointer(){
        integer = new int;
    }

    void setValue(int i){
        *integer = i;
    }

    int getValue(){
        return *integer;
    }

    void release(){
        delete integer;
    }
};

int main(){
    int m;
    safePointer std[5];

    for(int i = 0; i < 5; i++){
        cout << "Enter the Marks for Student " << i+1 << ": ";
        cin >> m;
        std[i].setValue(m);
    }

    cout << endl; 

    for(int i = 0; i < 5; i++){
        cout << "Value for Student " << i+1 << ": ";
        cout << std[i].getValue();
        cout << endl;
    }

    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << "Releasing for Student " << i+1 << endl;
        std[i].release();
    }

return 0;
}
