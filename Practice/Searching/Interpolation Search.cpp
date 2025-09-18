#include <iostream>
using namespace std;

void insertionSort(int arr[],int size){
    for(int i = 1; i < size; i++){
        int curr = arr[i];
        int prev = i - 1;
        
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }
}

void print(int arr[],int size){
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}

int InterpolationSearch(int arr[], int s, int target){
    int start = 0; 
    int end = s-1;

    while(start <= end){
        int mid = start + ((target - arr[start]) * (end - start) / arr[end] - arr[start]); //all same as binary, just mid formula is changed

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

    int *arr;;
    int s,t;

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
    insertionSort(arr,s);
    print(arr,s);
    cout << endl;
    cout << "Enter the target: ";
    cin >> t; 
    cout << InterpolationSearch(arr,s,t);

return 0;
}
