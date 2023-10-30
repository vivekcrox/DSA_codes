// 1. Using Recursion
bool searchBst(Node* root), int target{
    if(!root)
        return false;
    if(root->data == target)
        return true;
    
    if(root->data > target)
        return searchBst(root->left, target);
    else    
        return searchBst(root->right, target);
}

// 2. Using Iterative
bool searchBST(Node* root, int target){
    Node* temp = root;
    while(temp){
        if(temp->data == target)
            return true;
        if(temp->data > target)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}