class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Approach 1
        // int n = nums.size();
        // vector<int> result;

        // int i = 0;
        // while(i < n){
        //     int j = i+1;
        //     while(j < n){
        //         if(nums[i] + nums[j] == target){
        //             result = {i, j};
        //             return result;
        //         }
        //         j++;
        //     }
        //     i++;
        // }
        // return {};

        /*****/
        // Approach 2 : past checking
        int n = nums.size();
        unordered_map<int,int> mp;  //{num, idx}

        vector<int> result;

        for(int i=0; i<n; i++){
            int rem = target - nums[i];
            
            if(mp.find(rem) != mp.end()){
                result = {mp[rem], i};
                return result;
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
