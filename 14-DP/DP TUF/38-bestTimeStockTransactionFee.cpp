class Solution {
public:
// Using BTBSS-II 
    int solveSO(vector<int>&prices, int n, int fee){
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
                    profit = max(prices[i] - fee + next[1],       //only change is after tx -fee.
                                0 + next[0]);
                }
                curr[buy] = (int)profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return solveSO(prices, n, fee);
    }
};