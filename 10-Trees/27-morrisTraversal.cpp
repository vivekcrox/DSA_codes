    // Inorder Traversal : TC: O(n) | SC: O(1)
    vector<int> morrisTraversal(TreeNode* root, vector<int>& ans){
        if(!root)
            return ans;

        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* predecessor = curr->left;
                while(predecessor->right && predecessor->right != curr){ //2nd condition: if temp link
                    predecessor = predecessor->right;
                }
                if(predecessor->right == NULL){     // temp link creation
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else{    // removing temp link
                    predecessor->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }