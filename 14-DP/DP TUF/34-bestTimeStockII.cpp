class Solution {
public:
    int solveRec(vector<int>&prices, int i, int buy){
        if(i==prices.size())
            return 0;

        int profit = 0;
        if(buy){
            profit = max(-prices[i] + solveRec(prices, i+1, 0),
                            0 + solveRec(prices, i+1, 1));
        }
        else{
            profit = max(prices[i] + solveRec(prices, i+1, 1),
                         0 + solveRec(prices, i+1, 0));
        }
        return profit;
    }
    int solveMem(vector<int>&prices, int i, int buy, vector<vector<int>>&dp){
        if(i==prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[i] + solveMem(prices, i+1, 0, dp),
                            0 + solveMem(prices, i+1, 1, dp));
        }
        else{
            profit = max(prices[i] + solveMem(prices, i+1, 1, dp),
                         0 + solveMem(prices, i+1, 0, dp));
        }
        return dp[i][buy] = profit;
    }
    int solveTab(vector<int>&prices, int n){
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i+1][0],
                                    0 + dp[i+1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][1],
                                0 + dp[i+1][0]);
                }
                dp[i][buy] = (int)profit;
            }
        }
        return dp[0][1];
    }
    int solveSO(vector<int>&prices, int n){
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        next[0] = next[1] = 0;
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[i] + next[0],
                                    0 + next[1]);
                }
                else{
                    profit = max(prices[i] + next[1],
                                0 + next[0]);
                }
                curr[buy] = (int)profit;
            }
            next = curr;
        }
        return next[1];
    }
    int solveSOUsingVar(vector<int>&prices, int n){
        int curBuy = 0, curNotBuy = 0;
        int nextBuy = 0, nextNotBuy = 0;
        
        for(int i=n-1; i>=0; i--){
                
                curBuy = max(-prices[i] + nextNotBuy,
                                    0 + nextBuy);

                curNotBuy = max(prices[i] + nextBuy,
                                0 + nextNotBuy);
                
                nextBuy = curBuy;
                nextNotBuy = curNotBuy;
        }
        return nextBuy;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        // return solveRec(prices, 0, buy);

        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveMem(prices, 0, buy, dp);

        // return solveTab(prices, n);
        // return solveSO(prices, n);
        return solveSOUsingVar(prices, n);
    }
};