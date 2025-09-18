#include <iostream>
using namespace std;
//Time Complexity of this sort is O(n^2)
//it will also n^2 times on sorted array
int main(){

    int arr[] = {4,1,5,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int temp;
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout  << arr[i] << " ";
    }
    cout << "]";


    for(int i = 0; i < size; i++){
        //isSwap = false;
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
                //isSwap = false;
            }
        }
    }

    //if(isSwap){
        //cout << "The array is Sorted" << endl;
        //return; 
    //}
    

    cout << endl;
    cout << "Bubble Sorted Array" << endl;
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout  << arr[i] << " ";
    }
    cout << "]";
return 0;
}
