
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(!root)
            return result;
            
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            //level Process
            for(int i=0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                int index = leftToRight ? i : size-i-1;
                level[index] = frontNode->val;

                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            leftToRight = !leftToRight;
            result.push_back(level);
        }
        return result;
    }
};