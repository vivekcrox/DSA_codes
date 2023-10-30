// Given BST which is CBT  ----> build Max Heap.

// !! ans logically shi h... 

void storeInorder(Node* root, vector<int>& inorder){
    if(!root)
        return;
    
    inorder(root->left, ans);
    inorder.push_back(root->data);
    inorder(root->right, ans);
} 

void buildMaxHeapFromBST(Node* &root, vector<int>& inorder, int& i){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        root->data = inorder[i];
        i=i+1;
        return;
    }

    buildMaxHeapFromBST(root->left, inorder, i);
    buildMaxHeapFromBST(root->right, inorder, i);

    if(!root){
        root->data = inorder[i];
        i=i+1;
    }
}