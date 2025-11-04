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
