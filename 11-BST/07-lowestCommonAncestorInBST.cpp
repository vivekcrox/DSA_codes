class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1. Recursive solution: 
        // if(!root)
        //     return NULL;
        
        // if(root->val < p->val && root->val < q->val)  // case A
        //     return lowestCommonAncestor(root->right,p,q);
        // if(root->val > p->val && root->val > q->val)   // case B
        //     return lowestCommonAncestor(root->left,p,q);
        
        // return root;    // case C & D

    // 2. Iterative solution :
        if(!root)
            return NULL;
        while(root){
            if(root->val < p->val && root->val < q->val)  // case A
                root = root->right;
            else if(root->val > p->val && root->val > q->val)   // case B
                root = root->left;
            else
                return root;    // case C & D
        }
        return NULL;

    }
};