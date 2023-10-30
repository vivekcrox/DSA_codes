class Solution {
public:
    int solveRec(vector<int>& cost, int n){
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        
        int ans = cost[n] + min(solveRec(cost, n-1), solveRec(cost, n-2));
        return ans;
    }

    int solveMem(vector<int>& cost, int n, vector<int>& dp){
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        
        if(dp[n] != INT_MAX)
            return dp[n];

        dp[n] = cost[n] + min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        return dp[n];
    }

    int solveTab(vector<int>& cost, int n){
        vector<int> dp(n+1, -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }

    int solveSO(vector<int>& cost, int n){
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev2, prev1);
            //shifting
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // int ans = min(solveRec(cost, n-1), solveRec(cost, n-2));
        // return ans;

        // vector<int> dp(n+1, INT_MAX);
        // int ans = min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        // return ans;

        // return solveTab(cost, n);

        return solveSO(cost, n);
        
    }
};