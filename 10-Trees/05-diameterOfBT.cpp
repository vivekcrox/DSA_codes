pair<int,int> diameterFast(TreeNode* root){
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // if(!root)
        //     return 0;
        
        // int op1 = diameterOfBinaryTree(root->left);
        // int op2 = diameterOfBinaryTree(root->right);
        // int op3 = height(root->left) + height(root->right);

        // int ans = max(op1, max(op2, op3));
        // return ans;

        //** Fast way: using pair
        return diameterFast(root).first - 1;

    }