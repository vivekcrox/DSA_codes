class Solution
{
    public:
    int areMirror(Node* r1, Node* r2) {
        if(!r1 && !r2)
            return 1;
        if((r1 && !r2) || (!r1 && r2))
            return 0;
        
        bool left = areMirror(r1->left, r2->right);
        bool right = areMirror(r1->right, r2->left);
        bool value = r1->data==r2->data;
        
        if(left && right && value)
            return 1;
        else
            return 0;
    }

};