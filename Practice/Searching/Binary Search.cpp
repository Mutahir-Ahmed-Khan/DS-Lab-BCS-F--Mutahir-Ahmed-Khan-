#include <iostream>
using namespace std;

void print(int arr[],int size){
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}

int binarySearch(int arr[], int s, int target){
    int start = 0; 
    int end = s-1;

    while(start <= end){
        int mid = start + ((end - start) / 2);
        if(target > arr[mid]){
            start = mid + 1;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            cout << "Index: ";
            return mid;
        }
    }
    cout << "Item not Found ";
    return -1;
    
}

int main(){

    int arr[] = {-1,0,3,4,5,9};
    int s = sizeof(arr)/sizeof(arr[0]);
    int t; 

    cout << "Unsorted Array: ";
    print(arr,s);

    cout << endl; 
    cout << "Enter the target: ";
    cin >> t;

    cout << binarySearch(arr,s,t) << endl; 

return 0;
}
