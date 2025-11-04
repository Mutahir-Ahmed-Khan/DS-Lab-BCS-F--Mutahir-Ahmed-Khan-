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
