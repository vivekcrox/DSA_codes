/*
    Using Binary Search logic.
 */
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int s, int e){
        if(s > e)
            return NULL;
        
        int mid = s+(e-s)/2;
        int element = preorder[mid];
        TreeNode* root = new TreeNode(element);

        root->left = solve(preorder,s,mid-1);
        root->right = solve(preorder,mid+1,e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};