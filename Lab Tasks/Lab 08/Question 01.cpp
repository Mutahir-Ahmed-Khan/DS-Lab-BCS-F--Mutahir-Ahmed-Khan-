#include <iostream>
#include <queue>
using namespace std;


class Node{
	public:
		int data;
		Node * left;
		Node * right;
		
		Node(int val){
			data = val;
			left=right=NULL;
		}
};


void preOrder(Node * root){
	
	if (root==NULL){
		return ;
	}
	cout <<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node * root){
	
	if (root == NULL){
		return ;
	}
	
	inOrder(root->left);
	cout <<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node *root){
	
	if (root==NULL){
		return;
		
	}
	postOrder(root->left);
	postOrder(root->right);
	cout <<root->data<<" ";
}

void levelOrder(Node * root){
	
	queue <Node*> q;
	q.push(root);
	
	while(q.size()>0){
		Node * curr = q.front();
		q.pop();
		cout <<curr->data<<" ";
		
		if (curr->left!=NULL){
			q.push(curr->left);
		}
		if (curr->right != NULL){
			q.push(curr->right);
		}
	}
	cout <<endl;
}




int height(Node * root){
	
	if (root==NULL){
		return 0;
		
	}
	int leftH = height(root->left);
	int rightH= height(root->right);
	return max(leftH,rightH)+1;
}

int countNode(Node * root){
	
	if (root==NULL){
		return 0;
	}
	int leftcount =countNode(root->left);
	int rightcount = countNode(root->right);
	return 1+leftcount+rightcount;
}

int sumNodes(Node * root){
	
	if (root==NULL){
		return 0;
	}
	
	
	int leftsum = sumNodes(root->left);
	int rightsum = sumNodes(root->right);
	
	return leftsum + rightsum + root->data;
}

Node * insertinBst(Node * root,int val){
	
	if (root==NULL){
		return  new Node(val);
	}
	
	if (val<root->data){
		root->left= insertinBst(root->left,val);
	}
	else if(val>root->data){
			root->right= insertinBst(root->right,val);
	}
	
	return root;

}

bool isBinaryTreefull(Node * root){
	
	if (root==NULL){  // empty tree
		return true;
	}
	if (root->left==NULL && root->right==NULL){  // no child
		return true;
		
	}
	
	if (root->left != NULL && root->right!=NULL){ // two children
		return isBinaryTreefull(root->left) && isBinaryTreefull(root->left); // call for left subtree and right subtree
		// if left and right both are full then till root it is full
	}
	
	return false; // else case only , 1  child 
}


bool isBinaryTreeComplete(Node * root){
	
	if (root==NULL){
		return true;
	}
	
	queue  <Node*> q;
	q.push(root);
	bool nullfound=false;
	
	while (!q.empty()){
		Node * curr = q.front();
		q.pop();
		if (curr==NULL){
			nullfound = true;
		}
		else{
			if (nullfound==true){
				return false;
			}
			else{
				q.push(root->left);
				q.push(root->right);
			}	
		}
	} 
	return true;
}
bool search(Node * root,int key){
	if(root==NULL){
		return false;
	}
	if (root->data==key){
		return true;
	}
	
	if (key <root->data){
		return search(root->left,key);
	}
	else{
		return search(root->right,key);
	}
}

Node* getInorderSuccessor(Node * root){  // to find the min (left most) of a tree
	
	while (root!=NULL && root->left != NULL){
		root= root->left;
	}
	return root;
}

Node * deleteNode(Node * root, int key){
	
	if (root==NULL){
		return NULL;
	}
	
	if (key< root->data){
		root->left = deleteNode(root->left,key);
	}
	else if (key > root->data){
		root->right = deleteNode(root->right,key);
	}
	else{ // root->data = key
		 // O children 
		if (root->left==NULL && root->right ==NULL){
			delete root;
			return NULL;
		}
		// 1 children  (have right child)
		else if (root->left ==NULL){
			Node * temp = root->right;
			delete root;
			return temp;
		}
		// 1 children  (have left child)
		else if (root->right == NULL){
			Node * temp = root->left;
			delete root;
			return temp;
		}
		else {  // 2 children
				// 3 steps:
						//1. find InOrder Successor (MIN VALUE TO ROOT->RIGHT)
						//2. Root-data = IS->data;
						//3. delete IS;
				
				Node * InorderSuccessor = getInorderSuccessor(root->right);
				root->data = InorderSuccessor->data;
				root ->right = deleteNode(root->right,InorderSuccessor->data );
			
		}
		
		
	}
	return root;
}



int main(){
	
	int values[] ={3,2,1,5,6,4};
	Node * root=NULL;
	for (int i=0;i<6;i++){
	root = insertinBst(root,values[i]);
	}

	cout << "Height: " << height(root) << endl;
    cout << "Node count: " << countNode(root) << endl;
    cout << "Sum of nodes: " << sumNodes(root) << endl;
	
	 cout << "Preorder: ";
    preOrder(root);
    cout << endl;

    cout << "Inorder: ";
    inOrder(root);
    cout << endl;

    cout << "Postorder: ";
    postOrder(root);
    cout << endl;

    cout << "Level order: ";
    levelOrder(root);
	
	
	
    cout << "Delete 10" << endl;
    root = deleteNode(root, 10);

    cout << "Inorder after deletion: ";
    inOrder(root);
    cout << endl;

}
