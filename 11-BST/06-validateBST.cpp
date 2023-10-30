class Solution {
public:
    bool solve(TreeNode* root, long long int lb, long long int ub){
        if(!root)
            return true;
        
        if(root->val > lb && root->val < ub){    // not use '=' sign as same val may have in nodes of BST.
            bool leftAns = solve(root->left,lb,root->val);
            bool rightAns = solve(root->right,root->val,ub);
            return leftAns && rightAns;
        }
        else
            return false;
    }

    bool isValidBST(TreeNode* root) {
        long long int lowerBound = LONG_MIN;
        long long int upperBound = LONG_MAX;
        return solve(root, lowerBound, upperBound);
    }
};