class Solution {
public:
    int solveRec(vector<int>& nums, int curr, int prev){
        //base
        if(curr == nums.size())
            return 0;
        
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveRec(nums, curr+1, curr);
        }
        int exclude = solveRec(nums, curr+1, prev);

        int ans = max(include, exclude);
        return ans;
    }

    int solveMem(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        //base
        if(curr == nums.size())
            return 0;
        
        if(dp[curr][prev+1] != -1)          // prev + 1 -> so that start access from 0th index.
            return dp[curr][prev+1];

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveMem(nums, curr+1, curr, dp);
        }
        int exclude = solveMem(nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }

    int solveTab(vector<int>& nums){
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));

        for(int curr=nums.size()-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int solveSO(vector<int>& nums){
        vector<int> currRow(nums.size()+1, 0);
        vector<int> next(nums.size()+1, 0);

        for(int curr=nums.size()-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + next[curr+1];
                }
                int exclude = next[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            next = currRow;
        }
        return next[0];
    }
    // II) Method-2: 
    int singleVector(vector<int>&nums, int n){
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i] > nums[prev]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int curr = 0;
        // return solveRec(nums,curr, prev);

        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        // return solveMem(nums, curr, prev, dp);

        // return solveTab(nums);
        // return solveSO(nums);

        return singleVector(nums, n);   //Method-2
    }
};