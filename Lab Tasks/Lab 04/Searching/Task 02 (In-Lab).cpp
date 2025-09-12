#include <iostream>
using  namespace std;

int binarySearch(int *arr,int right,int left,int key);
int main(){
	
	int last2 = 57;
	
	int arr[10] = {12,23,24,56,76,89,99,101,112,123};
	
	int left = 0;
	int right = 9;
	int temp =	binarySearch(arr,right,left,last2);
	
	if (temp!=-1){
	cout <<"Value found at Index: "<<temp<<endl;
	}
	else{
		int pos;
		for (int i=0;i<10;i++){
			if (last2<arr[i]){
				pos=i;
				break;
			}
		}
		
		for (int i=11;i>pos;i--){
			arr[i] = arr[i-1];
		}
		arr[pos] = last2;
	
	}
	for (int i=0;i<11;i++){
		cout <<arr[i]<<", ";
	}
	
}
int binarySearch(int *arr,int right,int left,int key){

	while (left <= right) {
		int mid =  (right +left) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
		right = mid - 1;
		}
	}
	return -1;

	}
