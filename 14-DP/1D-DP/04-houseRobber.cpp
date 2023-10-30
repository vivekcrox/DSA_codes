class Solution {
public:

    // 1. Rec
    int solveRec(vector<int>& nums, int n){
        //base
        if(n==0)
            return nums[0];
        if(n < 0)
            return 0;

        int include = nums[n] + solveRec(nums, n-2);
        int exclude = 0 + solveRec(nums, n-1);

        int ans = max(include, exclude);
        return ans;
    }

    int solveTab(vector<int>& nums, int n, vector<int>& dp){
        //base
        if(n==0)
            return nums[0];
        if(n < 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];

        int include = nums[n] + solveRec(nums, n-2);
        int exclude = 0 + solveRec(nums, n-1);

        dp[n] = max(include, exclude);
        return dp[n];
    }

    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            int temp = 0;    // yha glti hogi merese....
            if(i-2 >= 0)    
                temp = dp[i-2];
            int include = nums[i] + temp;
            int exclude = 0 + dp[i-1];

            dp[i] = max(include, exclude);
        }
        return dp[n-1];
    }

    int solveSO(vector<int>& nums){
        int prev2 = 0;
        int prev1 = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            int include = nums[i] + prev2;
            int exclude = 0 + prev1;
            int ans = max(include, exclude);
            //shifting
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solveRec(nums, n-1);

        // vector<int> dp(n, -1);
        // return solveTab(nums, n-1, dp);

        // return solveTab(nums);
        return solveSO(nums);
    }
};