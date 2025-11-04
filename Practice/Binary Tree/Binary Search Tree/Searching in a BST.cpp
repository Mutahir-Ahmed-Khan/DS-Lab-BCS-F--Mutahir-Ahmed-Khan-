bool search(node* root, int key){
    if(root == NULL){
        return false;
    }
    else if(root->data == key){
        return true;
    }
    else if(key > root->data){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}
