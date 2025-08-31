#include <iostream>
using namespace std;
int main(){

    int **category;
    int *book;
    int c,x,pos;
    int search;
    bool found = false;

    cout << "How Many Category are there: ";
    cin >> c;

    category = new int*[c];
    book = new int[c];

    for(int i = 0; i < c; i++){
        cout << "How Many Books are there in Category " << i + 1 << "?: ";
        cin >> book[i];
        category[i] = new int[book[i]];
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < book[i]; j++){
            cout << "Enter ID for Book " << j+1 << " and Category " << i+1 << ": ";
            cin >> category[i][j];
        }
    }

    cout << "Enter the Book you want to Search: ";
    cin >> search;

     for(int i = 0; i < c; i++){
        for(int j = 0; j < book[i]; j++){
            if(search == category[i][j]){
                found = true;
                pos = i;
            }
        }
    }

    if(found){
        cout << "Book available in Category " << pos + 1 << endl;
    }
    else{
        cout << "Book not found" << endl;
    }

    for(int i = 0; i < c; i++){
        delete[] category[i];
    }

    delete[] category; 
    delete[] book;

return 0;
}
