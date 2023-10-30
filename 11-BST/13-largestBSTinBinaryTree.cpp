class Solution{
    public:
    // Return the size of the largest sub-tree which is also a BST
    class Info{
      public:
        int size;
        int maxVal;
        int minVal;
        bool isBST;        
    };
    
    Info solve(Node* root, int& ans){
        if(!root)
            return {0,INT_MIN,INT_MAX,true};
        
        Info leftAns = solve(root->left, ans);
        Info rightAns = solve(root->right, ans);
        
        Info currNode;
        currNode.size = 1 + leftAns.size + rightAns.size;
        currNode.maxVal = max(root->data, rightAns.maxVal);
        currNode.minVal = min(root->data, leftAns.minVal);
        if(leftAns.isBST && rightAns.isBST && (root->data > leftAns.maxVal) && (root->data < rightAns.minVal)){
            currNode.isBST = true;
        }
        else{
            currNode.isBST = false;
        }
        
        if(currNode.isBST)  
            ans = max(ans, currNode.size);
        
        return currNode;
    }
    
    int largestBst(Node *root)
    {
    	int maxSize = 0;
    	Info ans = solve(root,maxSize);
    	return maxSize;
    }
};