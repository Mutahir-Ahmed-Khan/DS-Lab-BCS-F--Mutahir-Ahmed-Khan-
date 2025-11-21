#include <iostream>
using namespace std;

void merge(int *arr,int start,int mid,int end){
	
	int temp[end-start+1];
	int index=0;
	int i=start;
	int j=mid+1;
	
	while (i<=mid && j<=end){
		
		if (arr[i]<arr[j]){
			temp[index]=arr[i];
			i++;
			index++;
		}
		else{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	
	while (i<=mid){
		temp[index]=arr[i];
			i++;
			index++;
	}
	
	while (j<=end){
		temp[index]=arr[j];
		j++;
		index++;
		
	}
	
	for (int idx=0;idx<(end-start+1);idx++){
		arr[start+idx]=temp[idx];
		
	}
}

void mergeSort(int * arr,int start,int end ){
	
	if (start<end){
		int mid = start + (end-start)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
}

int main(){
	
	int arr1[10] = {14,61,91,41,9,0,12,8,4,10};
	int arr2[10] = {98,20,213,90,12,6,14,80,1,27};
	
	int newarr[20];
	
	for (int i=0;i<10;i++){
		newarr[i] = arr1[i];
	}
	int j=0;
	for (int i=10;i<20;i++){
		newarr[i] = arr2[j];
		j++;
	}
	cout <<"Combined Sorted Array Using Merge Sort: "<<endl;
	cout <<"{ ";
	mergeSort(newarr,0,19);
	printArray(newarr,20);
	cout <<" }"<<endl;
}
