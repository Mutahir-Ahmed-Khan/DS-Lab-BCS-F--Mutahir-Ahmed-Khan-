#include <iostream>
using namespace std;

void print(int arr[],int size){
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}

void selectionSort(int arr[], int size){

    for(int i = 0; i < size - 1; i++){
        int smallestIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
    }
}


int main(){
    int *arr;
    int s,v;
    cout << "Enter the Size of the Array: ";
    cin >> s;
    arr = new int[s];

    cout << "Enter the Integer in the Array" << endl;
    for(int i = 0; i < s; i++){
        cout << "Enter for Array " << i+1 << ":";
        cin >> arr[i];
    } 
    cout << "Unsorted Array: ";
    print(arr,s);
    cout << endl; 
    cout << "Sorted Array: ";
    selectionSort(arr,s) ;
    print(arr,s);


    
return 0;
}
