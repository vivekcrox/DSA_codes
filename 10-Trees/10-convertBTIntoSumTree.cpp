class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int toSumHelp(Node* &node){
        if(!node)
            return 0;
        if(!node->left && !node->right){ //leaf node
            int val = node->data;
            node->data = 0;
            return val;
        }
        
        int leftSum = toSumHelp(node->left);
        int rightSum = toSumHelp(node->right);
        int val = node->data;
        
        node->data = leftSum + rightSum;
        return node->data + val;
    }
    
    void toSumTree(Node *node)
    {
        toSumHelp(node);
    }
};