#include <iostream>
using namespace std;

int main(){
	
	int sortingArr[10] ={5,1,3,6,2,9,7,4,8,10};
	int temp;
	bool flag = false;
	int  bound = 9;
  
	while(flag == false){
		flag = true;
		for (int i = 0; i < bound; i++){
      
			if (sortingArr[i]<sortingArr[i+1]){
				temp = sortingArr[i];
				sortingArr[i] = sortingArr[i+1];
				sortingArr[i+1] = temp;
				flag = false;
        
			}
			
		}
	bound--;
	}
	
	cout <<"Sorted Array of [10]: ";
	for(int i=0;i<10;i++){
		cout<<sortingArr[i]<<", ";
	}
}
