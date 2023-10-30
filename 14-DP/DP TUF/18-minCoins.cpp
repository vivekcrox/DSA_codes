class Solution {
public:
    int solveRec(vector<int>&coins, int i, int target){
        if(i==0){
            if(target % coins[0] == 0) return target/coins[0];
            return INT_MAX;
        }

        int excl = 0 + solveRec(coins, i-1, target);
        int incl = INT_MAX;
        if(target-coins[i] >= 0)
            incl = 1 + solveRec(coins, i, target-coins[i]);  // remains on same index as infinite supply.

        return min(excl, incl);
    }
    int solveMem(vector<int>&coins, int i, int target, vector<vector<int>>& dp){
        if(i==0){
            if(target % coins[0] == 0) return target/coins[0];
            return 1e9;
        }
        if(dp[i][target] != -1)
            return dp[i][target];

        int excl = 0 + solveMem(coins, i-1, target, dp);
        int incl = INT_MAX;
        if(target-coins[i] >= 0)
            incl = 1 + solveMem(coins, i, target-coins[i], dp);  

        return dp[i][target] = min(excl, incl);
    }
    int solveTab(vector<int>&coins, int n, int target){
        vector<vector<int>> dp(n, vector<int>(target+1, 1e9));
        for(int t=0; t<=target; t++){
            if(t%coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int excl = 0 + dp[i-1][t];
                int incl = INT_MAX;
                if(t-coins[i] >= 0)
                    incl = 1 + dp[i][t-coins[i]];  
                dp[i][t] = min(incl, excl);
            }
        }


        return dp[n-1][target];
    }
    int solveSO(vector<int>&coins, int n, int target){
        vector<int> prev(target+1, 1e9);
        vector<int> curr(target+1, 1e9);

        for(int t=0; t<=target; t++){
            if(t%coins[0] == 0) prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int excl = 0 + prev[t];
                int incl = INT_MAX;
                if(t-coins[i] >= 0)
                    incl = 1 + curr[t-coins[i]];  
                curr[t] = min(incl, excl);
            }
            prev = curr;
        }


        return prev[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = solveRec(coins, n-1, amount);

        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = solveMem(coins, n-1, amount, dp);

        // int ans = solveTab(coins, n, amount);
        int ans = solveSO(coins, n, amount);
        if(ans < 1e9)
            return ans;
        else
            return -1;
    }
};