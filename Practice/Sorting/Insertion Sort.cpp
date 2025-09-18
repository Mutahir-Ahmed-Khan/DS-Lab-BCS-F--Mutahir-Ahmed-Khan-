#include <iostream>
using namespace std;
//Time Complexity is O(n^2)
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

void printArray(int arr[],int size){
    cout << "[ ";
    for(int i = 0; i < size ; i++){
        cout << arr[i] << " "; 
    }
    cout << "]";
}
int main(){

   int arr[] = {4,1,2,5,3};
   int size = sizeof(arr) / sizeof(arr[0]);
   printArray(arr,size);
   insertionSort(arr,size);
   cout << endl;
   cout << "Insertion Sorted Array" << endl;
   printArray(arr,size);
return 0;
}

