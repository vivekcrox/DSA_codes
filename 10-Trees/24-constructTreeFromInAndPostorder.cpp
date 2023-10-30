
class Solution {
public:
    void constructMap(map<int,int>& mp, vector<int> inorder, int n){   //mapping node to index
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
    }
    TreeNode* solve(vector<int>& postorder,vector<int>& inorder, int startIn, int endIn, int& index, int n, map<int,int>& mp){
        if(index < 0 || startIn > endIn)    //index>=n -> incase of in & pre
            return NULL;
        
        int element = postorder[index--];     // index++ -> incase of in & pre
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];

        root->right = solve(postorder,inorder,pos+1,endIn,index,n,mp);
        root->left = solve(postorder,inorder,startIn,pos-1,index,n,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int> mp;
        constructMap(mp,inorder,n);
        int index = n-1;        //index = 0 -> incase of in & pre

        TreeNode* ans = solve(postorder,inorder,0,n-1,index,n,mp);
        return ans;
    }
};