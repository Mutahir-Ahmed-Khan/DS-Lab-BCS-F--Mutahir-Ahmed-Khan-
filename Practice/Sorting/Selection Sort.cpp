#include <iostream>
using namespace std;
//Time Complexity is O(n^2)
int main(){

    int arr[] = {4,1,5,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout  << arr[i] << " ";
    }
    cout << "]";

    for(int i = 0; i < size - 1; i++){
        int smallestIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
    }

    cout << endl;
    cout << "Selection Sorted Array" << endl; 
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout  << arr[i] << " ";
    }
    cout << "]";

return 0;
}

//Dry Run
//1st Iteration: 
// smallestIndex = 0; 1 < 4 -> yes, smallestIndex = 1 -> swapped with 4
//2nd Iteraion 
//smallestIndex = 1; 5 < 4 -> no, ---, ----, 
//3rd Iteration
//smallest index = 2; 2 < 3 ->yes...... 
