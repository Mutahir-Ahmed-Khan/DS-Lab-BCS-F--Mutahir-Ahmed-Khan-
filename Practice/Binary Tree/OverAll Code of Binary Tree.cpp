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

void preOrder(node* root){
    //Sequence: root, left, right
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    //Sequence: left, root, right
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " "; 
    inOrder(root->right);
}

void postOrder(node* root){
    //Sequence: left, right, root
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " "; 
    
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight;
    int rightHeight;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int count(node* root){
    if(root == NULL){
        return 0;
    }

    int leftCount;
    int rightCount;

    leftCount = count(root->left);
    rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

int sum(node* root){
    if(root == NULL){
        return 0;
    }

    int leftsum;
    int rightsum;

    leftsum = sum(root->left);
    rightsum = sum(root->right);

    return leftsum + rightsum + root->data;
}

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

    int tempArr[11] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildTree(tempArr); 
    
    cout << height(root) << endl;
    cout << count(root) << endl;
    cout << sum(root) << endl;

return 0;
}
