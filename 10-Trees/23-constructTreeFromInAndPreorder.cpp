/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void constructMap(map<int,int>& mp, vector<int> inorder, int n){   //mapping node to index
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder, int startIn, int endIn, int& index, int n, map<int,int>& mp){
        if(index >= n || startIn > endIn)
            return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];

        root->left = solve(preorder,inorder,startIn,pos-1,index,n,mp);
        root->right = solve(preorder,inorder,pos+1,endIn,index,n,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int,int> mp;
        constructMap(mp,inorder,n);
        int index = 0;

        TreeNode* ans = solve(preorder,inorder,0,n-1,index,n,mp);
        return ans;
    }
};