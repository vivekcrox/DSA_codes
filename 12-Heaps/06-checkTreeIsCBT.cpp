int countNode(Node* root){
    if(!root)
        return 0;
    
    return 1 + countNode(root->right) + countNode(root->left);
}

bool isCBT(Node* root, int index, int cnt){  //cnt --> count of Nodes in tree
    if(root==NULL)
        return true;

    if(index >= cnt)
        return false;
    else[
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);
        return left && right;
    ]
}