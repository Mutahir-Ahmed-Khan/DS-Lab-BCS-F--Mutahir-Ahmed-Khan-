#include <iostream>
using namespace std;

class QuadProb{
    private:
    int *table;
    int size;
    int cnt;

    static int const empty = -1;
    static int const deleted = -2;

    public: 
    QuadProb(int s){
        cnt = 0;
        size = s;
        table = new int[size];
        for(int i = 0; i < size; i++){
            table[i] = empty;
        }
    }

    int hash(int val){
        if(val < 0){
            return -1;
        }

        return val % 10;
    }

    void addkey(int val){
        if(cnt == size){
            cout << "Table is Full" << endl;
            return;
        }

        int index = hash(val);
        int newIndex;
        int i = 0;
        while(i < size){
            newIndex = index + (i * i) % size;
            if(table[newIndex] == empty || table[newIndex] == deleted){
                table[newIndex] = val;
                cnt++;
                return;
            }

            i++;

        }
        cout << "Failed To Insert " << endl;
    }

    bool searchKey(int val){
        int index = hash(val);
        int i = 0;
        int newIndex;

        while(i < size){
            newIndex = index + (i * i) % size;
            if(table[newIndex] == val){
                return true;
            }
            if(table[newIndex] == empty){
                return false;
            }
            i++;
        }

        return false;

    }

    void deleteKey(int val){
        int index = hash(val);  
        int newIndex;
        int i = 0;

        while(i < size){
            newIndex = index + (i * i) % size;
            if(table[newIndex] == val){
                table[newIndex] = deleted;
                cnt--;
                return;
            }

            if(table[newIndex] == empty){
                return; 
            }

            i++;
        }

        return; 
    }

    void display(){
        for(int i = 0; i < size; i++){
            cout << i << " : ";
            if(table[i] == empty){
                cout << "Empty" << endl;
            }
            else if(table[i] == deleted){
                cout << "Deleted" << endl;
            }
            else{
                cout << table[i] << endl;
            }
        }
    }

};

int main(){
    QuadProb qb(10);

    qb.addkey(19);
    qb.addkey(27);
    qb.addkey(31);
    qb.addkey(41);
    qb.addkey(51);

    qb.deleteKey(51);
    
    qb.display();
return 0;
}
