#include <iostream>
using namespace std;

bool isSorted(int arr[], int s){
    for(int i = 0; i < s; i++){
        for(int j = i ; j < s; j++){
            if(arr[i] > arr[i+1]){

            }
        }
        
    }
    return true;
}

void selectionSort(int arr[], int s){
    int smallestIndex;
    for(int i = 0; i < s; i++){
        smallestIndex = i;
        for(int j = i + 1; j < s; j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
    }
}

int interpolation(int arr[], int s, int target){
    int start = 0;
    int end = s - 1;
    int mid;

        while(start <= end){
            mid = start + ((target - arr[start]) * (end - start)) / (arr[end] - arr[start]);

            if(target > arr[mid]){
                start = mid + 1;
            }
            else if(target < arr[mid]){
                end = mid - 1;
            }
            else{
                return mid;
            }
        }

        cout << "Item not found" << endl;
}
int main(){
    int *arr;
    int t,s;
    cout << "Enter the Array size: "; 
    cin >> s;

    arr = new int[s]; 

    cout << "ENTER THE VALUES" << endl; 
    for(int i = 0; i < s; i++){
        cout << "Array " << i+1 << ":";
        cin >> arr[i];
    }

    if(!isSorted(arr,s)){
        selectionSort(arr,s);
    }

    cout << "Enter the target value you want to find: ";
    cin >> t;
    
    cout << "INDEX: " << interpolation(arr,s,t);
    

return 0;
}
