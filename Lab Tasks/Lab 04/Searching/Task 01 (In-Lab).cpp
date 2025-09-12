#include <iostream>
using namespace std;

int main(){
	int *arr;
	int findvar;
	int temp;
	int count;
	bool flag = false;
	
	cout <<"Enter Number of values you want to store:";
	cin >>count;
	
	arr =  new int[count];
	
	for (int i=0;i<count;i++){
		cout <<"Enter Value "<<i+1<<" : ";
		cin >> arr[i];
	}
	cout <<"Enter value to find:";
	cin >> findvar;
	
	for (int i = 0;i < count; i++){
		if(arr[i] == findvar){
			temp = i;
			flag =  true;
			break;
		}
	}
	
	if (flag == true){
		cout <<"Value at Index: " << temp <<endl;;
	}
	else{
		cout <<"Not Found"<<endl;
	}
	cout<<endl;
	cout <<"Array: ";
	for (int i=0;i<count;i++){
		cout <<arr[i]<<", ";
	}
}
