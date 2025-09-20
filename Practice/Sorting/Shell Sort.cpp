#include <iostream>
using namespace std;

void shellSort(int arr[], int size){
    //Dealing with the gap
    for(int gap = size/2; gap >= 1; gap = gap / 2){
        //Dealing with j
        for(int j = gap; j < size; j++){
            //Dealing with i
            for(int i = j - gap; i >= 0; i = i - gap){
                if(arr[i + gap] > arr[i]){
                    break;
                }
                else{ 
                    swap(arr[i + gap], arr[i]);
                }
            }
        }
    }
}

int main(){

    int arr[] = {5,2,4,1,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr,size);

    cout << "Sorted Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

return 0;
}
