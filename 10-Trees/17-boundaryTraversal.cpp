class Solution {
public:
    void traverseLeft(Node* root, vector<int>& ans){
        if(!root || (!root->left && !root->right))
            return;
        
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }
    void traverseLeaf(Node* root, vector<int>& ans){
        if(!root)
            return;
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    void traverseRight(Node* root, vector<int>& ans){
        if(!root || (!root->left && !root->right))
            return;
        
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {   
        vector<int> ans;
        if(!root)
            return ans;
        // push root node
        ans.push_back(root->data);
        // left view except leaf node
        traverseLeft(root->left, ans);
        // left subtree leaf nodes
        traverseLeaf(root->left, ans);
        // right subtree leaf nodes
        traverseLeaf(root->right, ans);
        // right view except leaf node in reverse order
        traverseRight(root->right, ans);
        
        return ans;
    }
};