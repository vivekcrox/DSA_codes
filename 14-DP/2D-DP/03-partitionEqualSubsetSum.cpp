class Solution {
public:
    bool solveRec(vector<int>& nums, int target, int i){
        if(i>=nums.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        int incl = solveRec(nums,target - nums[i],i+1);
        int excl = solveRec(nums, target, i+1);
        return incl || excl;
    }

    bool solveMem(vector<int>& nums, int i, int target, vector<vector<int>>& dp){
        if(i>=nums.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[i][target] != -1)
            return dp[i][target];

        int incl = solveMem(nums, i+1, target - nums[i], dp);
        int excl = solveMem(nums, i+1, target, dp);
        return dp[i][target] = (incl || excl);
    }

    bool solveTab(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int index=n-1; index>=0; index--){  //n-1  --> 0
            for(int t=0; t<=target; t++){       // 0   --> target
                int incl = 0;
                if(t-nums[index] >= 0)
                    incl = dp[index+1][t - nums[index]];  // as index+1 --> we take n+1 dp array(i.e n-1+1 == n)
                int excl = dp[index+1][t];
                
                dp[index][t] = incl || excl;
            }
        }
        return dp[0][target];
    }


    bool solveSO(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);

        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1; index>=0; index--){  //n-1  --> 0
            for(int t=0; t<=target; t++){       // 0   --> target
                int incl = 0;
                if(t-nums[index] >= 0)
                    incl = next[t - nums[index]]; 
                int excl = next[t];
                
                curr[t] = incl || excl;
            }
            next = curr;   // next moves upward in matrix
        }
        return next[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2)  //odd sum -> no partition subset sum exist
            return false;
        
        int target = sum/2;
        
        // return solveRec(nums, target, 0);

        // vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        // return solveMem(nums, 0, target, dp);

        // return solveTab(nums, target);
        return solveSO(nums, target);
    }
};