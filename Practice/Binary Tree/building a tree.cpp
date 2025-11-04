#include <iostream>
using namespace std;

class node{
    public: 
    int data;
    node* left; 
    node* right;

    node(int val){
        data = val; 
        left = right = NULL;
    }
};

static int idx = -1;
node* buildTree(int *arr){
    idx++;

     if(arr[idx] == -1){
        return NULL;
    }

    node* root = new node(arr[idx]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);

    return root;
}

int main(){

    int preOrder[11] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildTree(preOrder); 
    cout << root->right->data << endl;

return 0;
}
