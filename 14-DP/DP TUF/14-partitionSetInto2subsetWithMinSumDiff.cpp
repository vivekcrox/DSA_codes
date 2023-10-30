int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int k = totalSum;
    // //Using Tabulation func: chk subset equal to k.
    // vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    // for(int i=0; i<n; i++){
    //     dp[i][0] = true;
    // }
    // if(arr[0] <= k)
    //     dp[0][arr[0]] = true;
    
    
    // for(int i=1; i<n; i++){
    //     for(int t=1; t<=k; t++){
    //         bool notTake = dp[i-1][t];
    //         bool take = false;
    //         if(arr[i] <= t)
    //             take = dp[i-1][t-arr[i]];
            
    //         dp[i][t] = notTake || take;
    //     }
    // }

    // int ans = INT_MAX;
    // for(int s1=0; s1<=totalSum/2; s1++){
    //     if(dp[n-1][s1] == true)
    //         ans = min(ans, abs((totalSum-s1) - s1));
    // }
    // return ans;

    //Using Space Opt. func: chk subset equal to k.
    vector<bool> prev(k+1, false);
    vector<bool> curr(k+1, false);
    prev[0] = true;
    curr[0] = true;
    if(arr[0] <= k)
        prev[arr[0]] = true;
    
    
    for(int i=1; i<n; i++){
        for(int t=1; t<=k; t++){
            bool notTake = prev[t];
            bool take = false;
            if(arr[i] <= t)
                take = prev[t-arr[i]];
            
            curr[t] = notTake || take;
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for(int s1=0; s1<=totalSum/2; s1++){
        if(prev[s1] == true)
            ans = min(ans, abs((totalSum-s1) - s1));
    }
    return ans;
}