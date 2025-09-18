#include <iostream>
using namespace std;

void print(int arr[],int size){
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}

void bubbleSort(int arr[],int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int *arr;
    int s;
    cout << "Enter the Size of the Array: ";
    cin >> s;
    arr = new int[s];

    cout << "Enter the Integer in the Array" << endl;
    for(int i = 0; i < s; i++){
        cout << "Enter for Array " << i+1 << ":";
        cin >> arr[i];
    } 
    cout << "Unsorted: ";
    print(arr,s);
    cout << endl;
    bubbleSort(arr,s);
    cout << "Sorted: ";
    print(arr,s);
return 0;
}
