// convert BST into Sorted Doubly Linked List.
// we first make right subtree, instead of left subtree as less overhead to maintain pointers(i.e only head required to maintain).

void bstIntoDLL(Node* root, Node* head){
    if(!root)
        return;
    
    //right subtree ko Recursion -> DLL m convert krdega
    bstIntoDLL(root->right, head);

    root->right = head;
    if(head)                     // agar tree m right subtree hua tabhi prev ptr banayenge.
        head->left = root;          
    head = root;                //update head of list

    //left subtree ko Recursion -> DLL m convert krdega
    bstIntoDLL(root->left, head);
}