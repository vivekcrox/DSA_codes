// min Val in BST.
Node* minVal(Node* root){
    if(!root)
        return NULL;
    
    Node* temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

Node* deleteBST(Node* root, int val){
    //base case
    if(root==NULL)
        return root;
    if(root->data == val){
        // 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left && root->right){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = delete(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteBST(root->right, val);
        return root;
    }
}