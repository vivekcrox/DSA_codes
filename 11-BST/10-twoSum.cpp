
class Solution {
public:
    void createInorder(TreeNode* root, vector<int>& inorder){
        if(!root)
            return;
        
        createInorder(root->left,inorder);
        inorder.push_back(root->val);
        createInorder(root->right,inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        createInorder(root, inorder);

        int s=0, e = inorder.size()-1;
        while(s < e){
            int sum = inorder[s] + inorder[e];
            if(sum == k)
                return true;
            else if(sum > k)
                e--;
            else
                s++;
        }
        return false;
    }
};