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

// max Val node in BST.
Node* maxVal(Node* root){
    if(!root)
        return NULL;

    Node* temp = root;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}