
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root->val == p->val || root->val == q->val)   // finded node
            return root;                        
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right){
            return root;    // ans mil gya h
        }
        else if(left && !right){
            return left;
        }
        else if(!left && right){
            return right;
        }
        else{
            return NULL;
        }
    }
};