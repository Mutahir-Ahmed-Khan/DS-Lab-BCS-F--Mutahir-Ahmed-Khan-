#include <iostream>
using namespace std;

void combSort(int arr[], int size){
    double shrink = 1.3;
    int gap = size;
    bool swapped = true;


    while(gap > 1 || swapped){
        gap = (int)(gap / shrink);
        if(gap < 1){
            gap = 1;
        }

        swapped = false;

        for(int i = 0; i + gap < size; i++){
            if(arr[i] > arr[i + gap]){
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main(){

    int arr[] = {5,2,4,1,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    combSort(arr,size);

    cout << "Sorted Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

return 0;
}
