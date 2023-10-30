//1. Top View
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(!root)
            return ans;
        
        map<int,int> mp;     //hd,node data
        queue<pair<Node*,int>> q;  // node, hd
        q.push({root,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            Node* frontNode = curr.first;
            int hd = curr.second;
            if(mp.find(hd) == mp.end()){
                mp[hd] = frontNode->data; 
            }
            
            if(frontNode->left)
                q.push({frontNode->left, hd-1});
            if(frontNode->right)
                q.push({frontNode->right, hd+1});
        }
        //store ans
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};

// 2. Bottom View
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        map<int,int> mp;     //hd,node data
        queue<pair<Node*,int>> q;  // node, hd
        q.push({root,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            Node* frontNode = curr.first;
            int hd = curr.second;
            
            mp[hd] = frontNode->data;         // no condition which is present in top view 
            
            if(frontNode->left)
                q.push({frontNode->left, hd-1});
            if(frontNode->right)
                q.push({frontNode->right, hd+1});
        }
        //store ans
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};