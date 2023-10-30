class Solution {
public:
    void permuteUniqueHelper(vector<int>& nums, vector<vector<int>>& ans, int start){
        //base
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;
        for(int i=start; i<nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;     //check already used same int or not
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            permuteUniqueHelper(nums,ans,start+1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUniqueHelper(nums, ans, 0);
    
        return ans;
    }
};

/*************************/
//using set may result in TLE
class Solution {
public:
    void permuteUniqueHelper(vector<int>& nums, vector<vector<int>>& ans, int start){
        //base
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=start; i<nums.size(); i++){
            swap(nums[i], nums[start]);
            permuteUniqueHelper(nums,ans,start+1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUniqueHelper(nums, ans, 0);

        //push ans into set
        set<vector<int>> st;
        for(auto e:ans){
            st.insert(e);
        }
        ans.clear();
        for(auto e:st){
            ans.push_back(e);
        }
        return ans;
    }
};