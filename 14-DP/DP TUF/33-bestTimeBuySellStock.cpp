int maxProfit(vector<int>& prices) {
    // T.C: O(n) & S.C: O(1)
    int maxProfit = 0;
    int minSoFar = prices[0];
    for(int i=0; i<prices.size(); i++){
        minSoFar = min(minSoFar, prices[i]);
        maxProfit = max(maxProfit, prices[i]- minSoFar);
    }
    return maxProfit;
}