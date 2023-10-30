class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void convertToDLL(Node* root,Node* &head, Node* &prev){
        if(root == NULL)
            return;
        
        convertToDLL(root->left,head,prev);
        if(prev == NULL)   // handling first node i.e head node here.
            head = root;
        else{               // remaining nodes.
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        convertToDLL(root->right,head,prev);
    }
    
    Node * bToDLL(Node *root)
    {
        Node* prev = NULL;
        Node* head = NULL;
        convertToDLL(root,head,prev);
        return head;
    }
};