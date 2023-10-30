Node* solve(Node* root, int& k, int node){
    if(!root)
        return NULL;
    if(root->data == node)
        return root;
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns && !rightAns){
        k--;
        if(k == 0){
            k = INT_MAX;  // lock ans
            return root;
        }
        return leftAns;
    }
    if(!leftAns && rightAns){
        k--;
        if(k == 0){
            k = INT_MAX;  // lock ans
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(!ans || ans->data == node){   // means atleast ek upar ka ancestor hoga hi (given:k>=1)
        return -1;
    }
    else{
        return ans->data;
    }
}