void preOrder(node* root){
    //Sequence: root, left, right
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
