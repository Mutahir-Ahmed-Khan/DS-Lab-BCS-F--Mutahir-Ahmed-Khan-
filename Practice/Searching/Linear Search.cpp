#include <iostream>
using namespace std;

void print(int arr[],int size){
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}

void LinearSearch(int arr[],int v,int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == v){
            cout << "Founded on Index " << i << endl;
            return; 
        }
        cout << "Not in Array" << endl;
    }

}


int main(){
    int *arr;
    int s,v;
    cout << "Enter the Size of the Array: ";
    cin >> s;
    arr = new int[s];

    cout << "Enter the Value to Find in an Array: ";
    cin >> v;

    cout << "Enter the Integer in the Array" << endl;
    for(int i = 0; i < s; i++){
        cout << "Enter for Array " << i+1 << ":";
        cin >> arr[i];
    } 
    cout << "Array: ";
    print(arr,s);
    cout << endl; 
    LinearSearch(arr,v,s);
    
return 0;
}
