class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftAns = minDepth(root->left);
        int rightAns = minDepth(root->right);
        if(leftAns==0){
            return rightAns+1;
        }
        else if(rightAns==0)
            return leftAns+1;
        else
            return min(leftAns,rightAns)+1;
    }
};