class Solution {
public:
    int solveRec(vector<int>& nums, int i, int j){
        if(i > j)
            return 0;
        
        int maxi = INT_MIN;
        for(int k=i; k<=j; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] + solveRec(nums, i, k-1) + solveRec(nums, k+1, j);
            maxi = max(maxi, coins);
        }
        return maxi;
    }
    int solveTab(vector<int>& nums, int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i > j)
                    continue;
                    int maxi = INT_MIN;
                    for(int k=i; k<=j; k++){
                        int coins = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                        maxi = max(maxi, coins);
                    }
                    dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        // return solveRec(nums, 1, n);

        return solveTab(nums, n);
    }
};