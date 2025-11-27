#include <iostream>
using namespace std;

class node{
    public: 
    node* left; 
    node* right;
    int data;
    int height;

    node(int val){
        left = right = NULL;
        data = val;
        height = 1;
    }
};

                    //Helper Functions//
    int height(node* n){
        if(n == NULL){
            return 0;
        }
        return n->height;
    }

    int getBalance(node* n){
        if(n == NULL){
            return 0;
        }
        return height(n->left) - height(n->right);
    }

    void updateHeight(node* n){
        n->height = 1 + max(height(n->left), height(n->right));
    }

                    //Rotations//
    node* rightRotation(node* y){
        node* x = y->left;
        node* o = x->right;

        x->right = y;
        y->left = o;

        updateHeight(x);
        updateHeight(y);

        return x;
    }

    node* leftRotation(node* x){
        node* y = x->right;
        node* o = y->left;

        y->left = x;
        x->right = o;

        updateHeight(x);
        updateHeight(y);

        return y;   
    }

                    //Rebalancing Functions//
    node* rebalance(node* n){
        updateHeight(n);

        int balance = getBalance(n);

        //Left Case
        if(balance > 1){
            //Left-Left 
            if(getBalance(n->left) >= 0){
                return rightRotation(n);
            }
            //Left-Right
            else{
                n->left = leftRotation(n->left);
                return rightRotation(n);
            }
        }

        //Right Case
        if(balance < -1){
            //Right-Right 
            if(getBalance(n->right) >= 0){
                return leftRotation(n);
            }
            //Right-Left
            else{
                n->right = rightRotation(n->right); 
                return leftRotation(n);
            }
        }

        return n;
    }

                    //Insert Function//
    node* insert(node* n, int key){
        if(n == NULL){
            return new node(key);
        }

        if(key < n->data){
            n->left = insert(n->left,key);
        }
        else if(key > n->data){
            n->right = insert(n->right,key);
        }
        else{
            return n;
        }

        return rebalance(n);
    }

                    //Inorder Traversal//
    void inorder(node* root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

int main(){
    node* root = NULL;

    // Inserting nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
    cout << endl;

return 0;
}
