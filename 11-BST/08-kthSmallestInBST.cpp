class Solution {
public:
    // Using Inorder traversal.
    int kthSmallest(TreeNode* root, int& k) {
        if(!root)
            return -1;
        
        int leftAns = kthSmallest(root->left, k);   
        if(leftAns != -1)
            return leftAns;
        
        k--;
        if(k == 0)
            return root->val;
        
        int rightAns = kthSmallest(root->right, k);
        return rightAns;   //assuming always valid k that's why no check on rightAns.
    }
};