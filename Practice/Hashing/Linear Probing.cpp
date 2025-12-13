#include <iostream>
using namespace std;

class linearProbing{
    private: 
        int *table;
        int cnt;
        int size;
        static int const empty = -1;
        static int const deleted = -2;

        public: 
            linearProbing(int s){
                size = s;
                table = new int[size];
                cnt = 0;
                for(int o = 0; o < size; o++){
                    table[o] = empty;
                }
            }

        int hash(int val){
            if(val < 0){
                return -1;
            }

            return val % 10;
        }

        void add(int val){
            int index = hash(val);

            if(cnt == size){
                cout << "Table is Full" << endl; 
                return;
            }

            int startIndex = index;
            while(table[index] != empty && table[index] != deleted){
                index = (index + 1) % 10;
                if(index == startIndex){
                    cout << "Cant be inserted" << endl;
                    return;
                }
            }
           
            table[index] = val;
            cnt++;
        }

        bool delKey(int val){
            int index = hash(val);
            int startIndex = index;

            while(table[index] != empty){
                if(table[index] == val){
                    table[index] = deleted;
                    cnt--;
                    return true;
                }
                else{
                    index = (index + 1) % 10;
                    if(index == startIndex){
                        return false;
                    }
                }
            }
            return false;
        }

        bool searchKey(int val){
            int index = hash(val);
            int startIndex = index;

            while(table[index] != empty){
                if(table[index] == val){
                    cout << "=== "<< val << " Found at " << index  << " ==="<< endl;
                    return true;
                }
                else{
                    index = (index + 1) % 10;
                    if(startIndex == index){
                        break;
                    }
                }
            }

            cout << "Not Found" << endl;
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

    linearProbing lp(10);
    lp.add(18);
    lp.add(36);
    lp.add(47);
    lp.add(57);

    lp.delKey(47);
    lp.searchKey(36);

    lp.display();

return 0;
}
