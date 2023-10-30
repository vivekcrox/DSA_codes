// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    pair<bool,int> isSumHelper(Node* root){
        if(!root){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(!root->left && !root->right){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumHelper(root->left);
        pair<bool,int> rightAns = isSumHelper(root->right);
        
        bool isleftSumTree = leftAns.first;
        bool isrightSumTree = rightAns.first;
        bool condn = root->data==(leftAns.second+rightAns.second);
        
        pair<bool,int> ans;
        if(isleftSumTree && isrightSumTree && condn){
            ans.first = true;
            ans.second = root->data + leftAns.second + rightAns.second;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
        
    bool isSumTree(Node* root)
    {
         return isSumHelper(root).first;
    }
};