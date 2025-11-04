void postOrder(node* root){
    //Sequence: left, right, root
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " "; 
    
}
