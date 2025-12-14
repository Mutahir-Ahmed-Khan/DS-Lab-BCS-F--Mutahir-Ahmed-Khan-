#include <iostream>
#include <algorithm>
using namespace std; 

class node{
	public: 
	int data;
	int height;
	node* left;
	node* right;
	
	node(int v){
		left = right = NULL;
		height = 1;
		data = v;
	}
};

///--------------------------------------///
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
	
///------------------------------------------------///
	
	node* leftRotation(node* y){
		node* x = y->right;
		node* temp1 = x->left;
		
		x->left = y;
		y->right = temp1;
		
		updateHeight(y);
		updateHeight(x);
		
		return x;	
	}
	
	node* rightRotation(node *x){
		node* y = x->left;
		node* temp2 = y->right;
		
		y->right = x;
		x->left = temp2;
		
		updateHeight(x);
		updateHeight(y);
		
		return y;
	}
///-------------------------------------//

	node* rebalance(node* n){
		int balance = getBalance(n);
		
		if(balance > 1){
			if(getBalance(n->left) >= 0){
				return rightRotation(n);
			}
			else{
				n->left = leftRotation(n->left);
				return rightRotation(n);
			}
		}
		
		if(balance < -1){
			if(getBalance(n->right ) <= 0){
				return leftRotation(n);
			}
			else{
				n->right = rightRotation(n->right);
				return leftRotation(n);
			}
		}
		
		return n;
	}

///-------------------------------------//
	
	node* insert(node* root, int key){
		if(root == NULL){
			return new node(key);
		}
		
		if(key > root->data){
			root->right = insert(root->right, key);
		}
		else if(key < root->data){
			root->left = insert(root->left, key);
		}
		else{
			return root;
		}
		
		return rebalance(root);
	}
	
	void inOrder(node* n){
		if(n == NULL){
			return;
		}
		
		inOrder(n->left);
		cout << n->data << " ";
		inOrder(n->right);
	}
	
int main(){
	
	
	
}
