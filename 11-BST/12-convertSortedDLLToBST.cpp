Node* sortedDLLToBst(Node* head, int n){
    if(n <= 0 || head==NULL)
        return NULL;
    
    Node* leftSubtree = sortedDLLToBst(head, n/2);

    Node* root = head;      // mid node created of bst
    root->left = leftSubtree;
    head = head->right;      //update head

    //right part solve krna h
    root->right = sortedDLLToBst(head, n/2 - 1);
    return root;
}