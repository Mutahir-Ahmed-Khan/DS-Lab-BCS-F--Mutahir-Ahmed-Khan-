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
