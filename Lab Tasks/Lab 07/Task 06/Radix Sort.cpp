#include <iostream>
using namespace std;

class Node{
	
	public:
		int data;
		Node * next;
		Node(int val){
			data= val;
			next = NULL;
			
		}
		
};

void insertinbucket(Node *& head, int val){
	
	Node *newNode= new Node(val);
	if (head==NULL){
		head=newNode;
		return;
	}
	
	Node * temp = head;
	while (temp->next != NULL){
		temp = temp->next;
	} 
	temp->next= newNode;
}


void clearBucket(Node*& head){
	
	Node * temp;
	
	while (head!=NULL){
		temp = head;
		head= head->next;
		delete temp;
	}
	
}

int getmax(int *arr,int n){
	int max= arr[0];
	
	for (int i=0;i<n;i++){
		if (arr[i]>=max){
			max=arr[i];
		}
		
	}
	return max;
}


void RadixSort(int *arr,int n){
	int max=getmax(arr,n );
	int exp=1;
	
	Node* Bucket[10];
	while (max/exp>0){
	// intialize bucket array with NULL;
	for (int i=0;i<10;i++){
		Bucket[i]=NULL;
	}
	
	
	for (int i=0;i<n;i++){
		int dig = (arr[i]/exp)%10;
		insertinbucket(Bucket[dig],arr[i]);
	}
	
	int idx=0;
	
	for (int i=0;i<10;i++){
		Node * temp = Bucket[i];
		while(temp!=NULL){
			arr[idx]=temp->data;
			idx++;
			temp = temp->next;
		}
		clearBucket(Bucket[i]);
	}
	exp = exp*10;
	
	
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
	cout <<"Combined Sorted Array using Radix Sort: "<<endl;
	cout <<"{ ";
	RadixSort(newarr,20);
	printArray(newarr,20);
	cout <<" }"<<endl;
}