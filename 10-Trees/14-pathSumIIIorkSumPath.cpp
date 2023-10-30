
class Solution {
public:
    void solvePath(TreeNode* root, int targetSum, vector<long long int>& path, int& count){
        if(!root)
            return;
        path.push_back(root->val);
        solvePath(root->left, targetSum, path, count);
        solvePath(root->right, targetSum, path, count);

        long long int size = path.size();
        long long int sum = 0;
        for(int i=size-1; i>=0; i--){
            sum += path[i];
            if(sum == targetSum)
                count++;
        }
        //backtrack
        path.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<long long int> path;
        solvePath(root, targetSum, path, count);
        return count;
    }
};