 int maxProfit(vector<int>& prices) {
        // T.C: O(n) & S.C: O(1)
//         int maxProfit = 0;
//         int minSoFar = prices[0];
//         int profit = 0;
//         for(int i=0; i<prices.size(); i++){
//             minSoFar = min(minSoFar, prices[i]);
//             profit = prices[i] - minSoFar;
            
//             maxProfit = max(maxProfit, profit);
//         }
        
//         return maxProfit;
        int profit = 0;
    int mini = prices[0];
    for(int i=0; i<prices.size(); i++){
        mini = min(mini, prices[i]);
        profit = max(profit, prices[i]- mini);
    }
    return profit;
    }