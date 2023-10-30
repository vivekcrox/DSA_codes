// Predecessor->(left subtree ka max) and Successor->(right subtree ka min) in BST.
pair<int,int> preSuc(Node* root, int key){
    Node* temp = root;
    int pred = -1;
    int succ = -1;
    //first find the key in BST
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;    // possible successor
            temp = temp->left;
        }
        else{
            pred = temp->data;   // possible successor
            temp = temp->right;
        }
    }
    //pred
    Node* leftTree = temp->left;
    while(leftTree){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    //succ
    Node* rightTree = temp->right;
    while(rightTree){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    return {pred,succ};
}