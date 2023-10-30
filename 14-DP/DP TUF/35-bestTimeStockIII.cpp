class Solution {
public:
    int solveRec(vector<int>&prices, int i, int buy, int cap){
        if(cap == 0)
            return 0;
        if(i == prices.size())
            return 0;
        
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + solveRec(prices, i+1, 0, cap),
                            0 + solveRec(prices, i+1, 1, cap));
        }
        else{
            profit = max(prices[i] + solveRec(prices, i+1, 1, cap-1),
                            0 + solveRec(prices, i+1, 0, cap));
        }
        return profit;

    }
    int solveMem(vector<int>&prices, int i, int buy, int cap, vector<vector<vector<int>>>&dp){
        if(cap == 0)
            return 0;
        if(i == prices.size())
            return 0;
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + solveMem(prices, i+1, 0, cap, dp),
                            0 + solveMem(prices, i+1, 1, cap, dp));
        }
        else{
            profit = max(prices[i] + solveMem(prices, i+1, 1, cap-1, dp),
                            0 + solveMem(prices, i+1, 0, cap, dp));
        }
        return dp[i][buy][cap] = profit;

    }
    int solveTab(vector<int>&prices, int n, int cap){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(cap+1, 0)));
        for(int i=0; i<n; i++){
            for(int buy=0; buy<=1; buy++)
                dp[i][buy][0] = 0;
        }
        for(int buy=0; buy<=1; buy++){
            for(int c=0; c<=cap; c++)
                dp[n][buy][c] = 0;
        }

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int c=1; c<=cap; c++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i] + dp[i+1][0][c],
                                        0 + dp[i+1][1][c]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][c-1],
                                        0 + dp[i+1][0][c]);
                    }
                    dp[i][buy][c] = profit;
                }
            }
        }
        return dp[0][1][cap];
    }
    int solveSO(vector<int>&prices, int n, int cap){
        vector<vector<int>> curr(2, vector<int>(cap+1, 0));
        vector<vector<int>> next(2, vector<int>(cap+1, 0));

        for(int i=0; i<n; i++){
            for(int buy=0; buy<=1; buy++)
                next[buy][0] = 0;
        }
        for(int buy=0; buy<=1; buy++){
            for(int c=0; c<=cap; c++)
                next[buy][c] = 0;
        }

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int c=1; c<=cap; c++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i] + next[0][c],
                                        0 + next[1][c]);
                    }
                    else{
                        profit = max(prices[i] + next[1][c-1],
                                        0 + next[0][c]);
                    }
                    curr[buy][c] = profit;
                }
            }
            next = curr;
        }
        return next[1][cap];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int cap = 2;
        // return solveRec(prices, 0, buy, cap);

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap+1, -1)));
        // return solveMem(prices, 0, buy, cap, dp);

        // return solveTab(prices, n, cap);
        return solveSO(prices, n, cap);
    }
};