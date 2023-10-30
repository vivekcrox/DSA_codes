class Solution {
public:
    // BTBSS-III
    int solveSOprev(vector<int>&prices, int n, int cap){
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
/*********************************************************************************/
    int solveRec(vector<int>&prices, int i, int tranNo, int cap){
        if(i == prices.size() || tranNo == 2*cap)
            return 0;

        int profit = 0;
        if(tranNo % 2 == 0){
            profit = max(-prices[i] + solveRec(prices, i+1, tranNo+1, cap), 
                            0 + solveRec(prices, i+1, tranNo, cap));
        }
        else{
            profit = max(prices[i] + solveRec(prices, i+1, tranNo+1, cap), 
                            0 + solveRec(prices, i+1, tranNo, cap));
        }
        return profit;
    }
    int solveTab(vector<int>&prices, int n, int cap){
        vector<vector<int>> dp(n+1, vector<int>(2*cap+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int c=2*cap-1; c>=0; c--){
                int profit = 0;
                if(c % 2 == 0){
                    profit = max(-prices[i] + dp[i+1][c+1], 
                                    0 + dp[i+1][c]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][c+1], 
                                    0 + dp[i+1][c]);
                }
                dp[i][c] = profit;
            }
        }
        return dp[0][0];
    }
    int solveSO(vector<int>&prices, int n, int cap){
        vector<int> curr(2*cap+1, 0);
        vector<int> next(2*cap+1, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int c=2*cap-1; c>=0; c--){
                int profit = 0;
                if(c % 2 == 0){
                    profit = max(-prices[i] + next[c+1], 
                                    0 + next[c]);
                }
                else{
                    profit = max(prices[i] + next[c+1], 
                                    0 + next[c]);
                }
                curr[c] = profit;
            }
            next = curr;
        }
        return next[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int cap = k;
        // return solveSOprev(prices, n, cap);

        int tranNo = 0;
        // return solveRec(prices, 0, tranNo, cap);
        // return solveTab(prices, n, cap);
        return solveSO(prices, n, cap);
    }
};