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
            if(i > index && candidates[i] == candidates[i-1]){   // 3) ignore redundant value to avoid dulicate value to be picked up
                continue;
            }
            output.push_back(candidates[i]);
            combinationHelper(candidates, target-candidates[i], output, ans, i+1);  // 1) i+1 send, so that can't use multiple times a single value
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 2) to remove duplicate combinations
        vector<vector<int>> ans;
        vector<int> output;
        combinationHelper(candidates, target, output, ans, 0);

        return ans;
    }
};


//***************
// TLE ayega iss solution se kyuki...set operation m time lag jayega
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
            combinationHelper(candidates, target-candidates[i], output, ans, i+1);  // i+1 send , so that can't use multiple times a single value
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        combinationHelper(candidates, target, output, ans, 0);

        set<vector<int>> st;
        for(auto it: ans){
            st.insert(it);
        }
        ans.clear();
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};