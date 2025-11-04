void inOrder(node* root){
    //Sequence: left, root, right
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " "; 
    inOrder(root->right);
}
