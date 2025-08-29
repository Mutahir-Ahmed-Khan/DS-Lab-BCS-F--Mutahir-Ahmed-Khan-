#include <iostream>
using namespace std;

int main(){
	int students,courses,marks,i,j;
	float avg,total=0.0;
	int **arr;
	
	cout<<"Enter number of students: ";
	cin>>students;
	arr=new int*[students];
	int size[students];
	
	for (i=0;i<students;i++){
		cout<<"Enter courses for Student "<<i+1<<" ";
		cin>>size[i];
		arr[i]=new int [size[i]];
		
	}
	for(i=0;i<students;i++){
		for (j=0;j<size[i];j++){
		cout<<"Enter marks for Student "<<i+1<<" Course "<<j+1<<endl;
		cin>>marks;
		arr[i][j]=marks;
			}
		
	}
	
	for(i=0;i<students;i++){
		for(j=0;j<size[i];j++){
			total=total+arr[i][j];
		}
		cout<<"Total for Student "<<i+1<<": "<<total<<endl;
		avg=total/size[i];
		cout<<"Avg for student "<<i+1<<": "<<avg<<endl;
		total=0;
	}
	
	for(i=0;i<students;i++){
		delete[] arr[i];
	}
	delete[] arr;
}
