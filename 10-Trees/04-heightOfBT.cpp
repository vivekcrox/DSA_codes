class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int leftAns = maxDepth(root->left);
        int rightAns = maxDepth(root->right);

        int ans = max(leftAns, rightAns) + 1;
        return ans;
    }
};