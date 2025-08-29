#include <iostream>
using namespace std; 

int main(){
	int benches;
	int **arr;
	int *seats;
	int s,r,l;
	
	cout << "Enter the how many Benches are there: ";
	cin >> benches;
	
	arr = new int*[benches];
	seats = new int[benches];
	
	cout << "Enter the Number of Seats" << endl; 
	for(int i = 0; i < benches; i++){
		cout << "Enter Seats in a bench " << i+1 << ": ";
		cin >> seats[i];
		arr[i] = new int[seats[i]];
	}
	
	for(int i = 0; i < benches; i++){
		for(int j = 0; j < seats[i]; j++){
			arr[i][j] = 0;
		}
	}
	
	cout << "Enter how many seats needed: "; 
	cin >> s;
	
	for(int i = 0; i < s; i++){
		cout << "Which Seat in a bench you want: ";
		cin  >> r;
		cin >> l;
		if(r > benches || l > seats[r-1] ){
			cout << "Out Of Bound" << endl;
		}
		
		arr[r-1][l-1] = 1;
		
	}
	
	for(int i = 0; i < benches; i++){
		for(int j = 0; j < seats[i]; j++){
			cout << arr[i][j];
			cout << " ";
		}
		cout << endl;
	}
	
}
