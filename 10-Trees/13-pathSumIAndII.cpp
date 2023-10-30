/* Path Sum I : return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.*/
class Solution {
public:
    bool hasPath = false;
    void solve(TreeNode* root, int targetSum, int& sum){
        if(!root)
            return;
        if(!root->left && !root->right){
            sum += root->val;
            if(sum == targetSum)
                hasPath = true;
            sum -= root->val;
            return;
        }
        sum += root->val;
        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);
        sum -= root->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // Method 1:
        // if (!root) return false;
        // if (root->val == targetSum && !root->left && !root->right) 
        //     return true;
            
        // return (hasPathSum(root->right, targetSum - root->val) || 
        //         hasPathSum(root->left, targetSum - root->val));

        // Method2:
        int sum = 0;
        solve(root, targetSum, sum);
        return hasPath;
    }
};

/* Path Sum II : return all root-to-leaf paths where the sum of the node values in the path equals targetSum.*/

class Solution {
public:
    void solve(TreeNode* root, int targetSum, int& currSum, vector<int>& path, vector<vector<int>>& ans){
        if(!root)
            return;
        if(!root->left && !root->right){
            path.push_back(root->val);
            currSum += root->val;
            if(currSum == targetSum)
                ans.push_back(path);
            path.pop_back();
            currSum -= root->val;
            return;
        }

        //include curr node
        path.push_back(root->val);
        currSum += root->val;

        solve(root->left, targetSum, currSum, path, ans);
        solve(root->right, targetSum, currSum, path, ans);
        //backtrack
        path.pop_back();
        currSum -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > ans;
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum, sum, temp, ans);
        return ans;   
    }
};