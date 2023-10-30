class Solution {
public:
    int solveRec(vector<int>&arr, int n, int i, int k){
        if(i == n)
            return 0;

        int len = 0;
        int maxi = INT_MIN;
        int maxSum = INT_MIN;
        for(int it=i; it < min(n, i+k); it++){
            len++;
            maxi = max(maxi, arr[it]);
            int sum = len*maxi + solveRec(arr, n, it+1, k);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    int solveMem(vector<int>&arr, int n, int i, int k, vector<int>&dp){
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int len = 0;
        int maxi = INT_MIN;
        int maxSum = INT_MIN;
        for(int it=i; it < min(n, i+k); it++){
            len++;
            maxi = max(maxi, arr[it]);
            int sum = len*maxi + solveMem(arr, n, it+1, k, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
    int solveTab(vector<int>&arr, int n, int k){
        vector<int> dp(n+1, 0);
        dp[n] = 0;

        for(int i=n-1; i>=0; i--){
            int len = 0;
            int maxi = INT_MIN;
            int maxSum = INT_MIN;
            for(int it=i; it < min(n, i+k); it++){
                len++;
                maxi = max(maxi, arr[it]);
                int sum = len*maxi + dp[it+1];
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {   // based on front partitioning.
        int n = arr.size();
        // return solveRec(arr, n, 0, k);

        // vector<int> dp(n, -1);
        // return solveMem(arr, n, 0, k, dp);

        return solveTab(arr, n, k);
    }
};