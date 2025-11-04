node* insert(node* root, int val){
    node* newNode;
    if(root == NULL){
        return new node(val);
    }
    else if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

void inOrder(node* root){
    if(root == NULL){
        return; 
    }
    
    inOrder(root->left); 
    cout << root->data << " ";
    inOrder(root->right);
}

node* buildBST(int* arr, int s){
    node* root;

    for(int i = 0; i < s; i++){
        root = insert(root, arr[i]);
    }

    return root; 
}
