class Solution {
public:
    void combinationHelper(vector<int>& candidates, int target, vector<int>& output, vector<vector<int>>& ans, int index){
        //base
        if(target == 0){
            ans.push_back(output);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            output.push_back(candidates[i]);
            combinationHelper(candidates, target-candidates[i], output, ans, i);  // i send as it is, so that can use multiple times a single value
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        combinationHelper(candidates, target, output, ans, 0);
        return ans;
    }
};