pair<bool,int> chkMaxHeap(Node* root){
    //base case
    if(root==NULL){
        pair<bool,int> p = make_pair(true,INT_MIN);
        return p;
    }
    if(!root->left  && !root->right){
        return {true, root->data};
    }

    pair<bool,int> leftAns = chkMaxHeap(root->left);
    pair<bool,int> rightAns = chkMaxHeap(root->right);

    if(leftAns.first && rightAns.first && root->data > leftAns.second && root->data > rightAns.second){
        return {true, root->data};
    }
    else {
        return {false, root->val};
    }
}

bool isMaxHeap(Node* root){
    return chkMaxHeap(root).first;
}