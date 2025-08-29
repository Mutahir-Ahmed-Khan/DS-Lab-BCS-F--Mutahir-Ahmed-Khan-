#include <iostream >
using namespace std;

int main(){
	int size;
	int *arr1;
	int pos;
	int inte;
	int x;
	cout << "Enter the size: ";
	cin >> size;
	
	arr1 = new int[size];
	cout << "Intialising with zeros"<< endl; 
	cout << endl; 
	for(int i = 0; i < size; i++){
		arr1[i] = 0;
	} 
	
	cout << "Enter how values you want to update: " ;
	cin >> x;
	
	for(int i = 0; i < x; i++){
		cout << "Enter the Position, you want to add the number at: ";
		cin >> pos;
	
		if(pos > size){ 
	 	cout << "Out of Bound" << endl;
	 	break;
		}
		else{ 
			cout << "Enter the Integer: "; 
			cin >> inte;
			arr1[pos-1] = inte;
		}
	
	}
	
		for(int i = 0; i < size; i++){
			cout << "Element " << i+1 << ": " << arr1[i] << endl;
		}
	
	delete[] arr1;
	cout << "Deleted" << endl;
	
}
