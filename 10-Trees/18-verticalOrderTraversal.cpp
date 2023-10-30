
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> > ans;
        if(!root)
            return ans;
        // by default map store value in ascending order
        map<int, map<int,multiset<int>>> nodes;  // hd,(level,list of nodes) []multiset store nodes in sorted order]
        queue<pair<TreeNode*, pair<int,int>>> q;   // node,(hd,level)

        q.push(make_pair(root, make_pair(0,0)));
        while(!q.empty()){
            auto curr = q.front();    
            q.pop();
            TreeNode* frontNode = curr.first;
            int& hd = curr.second.first;       // by reference means hd ki copy nhi banegi
            int& lvl = curr.second.second;

            nodes[hd][lvl].insert(frontNode->val);
            if(frontNode->left)
                q.push({frontNode->left, {hd-1,lvl+1}});
            if(frontNode->right)
                q.push({frontNode->right, {hd+1,lvl+1}});
        }
        //store ans
        //1. method
        // for(auto i:nodes){
        //     vector<int> vertical;
        //     for(auto j:i.second){
        //         for(auto k:j.second){
        //             vertical.push_back(k);
        //         }
        //     }
        //     ans.push_back(vertical);
        // }
        //2. method
        for(auto it: nodes){
            auto& colMap = it.second;   //by ref so that no copy made
            vector<int> vLine;
            for(auto colMapIt: colMap){
                auto& mset = colMapIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());  //starting se end tak mset
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};