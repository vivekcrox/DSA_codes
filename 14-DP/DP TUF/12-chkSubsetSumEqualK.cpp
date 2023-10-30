#include <bits/stdc++.h> 

bool solveRec(vector<int>&arr, int i, int k){
    //base
    if(k==0)
        return true;
    if(i==0)
        return arr[0]==k;
    
    bool notTake = solveRec(arr, i-1, k);
    bool take = false;
    if(arr[i] <= k)
        take = solveRec(arr, i-1, k-arr[i]);
    
    return notTake || take;
}
bool solveMem(vector<int>&arr, int i, int k,vector<vector<int>>&dp){
    //base
    if(k==0)
        return true;
    if(i==0)
        return arr[0]==k;
    if(dp[i][k] != -1)
        return dp[i][k];
        
    bool notTake = solveMem(arr, i-1, k, dp);
    bool take = false;
    if(arr[i] <= k)
        take = solveMem(arr, i-1, k-arr[i], dp);
    
    return dp[i][k] = notTake || take;
}
bool solveTab(vector<int>&arr, int n, int k){
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k)
        dp[0][arr[0]] = true;
    
    
    for(int i=1; i<n; i++){
        for(int t=1; t<=k; t++){
            bool notTake = dp[i-1][t];
            bool take = false;
            if(arr[i] <= t)
                take = dp[i-1][t-arr[i]];
            
            dp[i][t] = notTake || take;
        }
    }
    return dp[n-1][k];
}
bool solveSO(vector<int>&arr, int n, int k){
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
    return prev[k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // return solveRec(arr, n-1, k);
    
    // vector<vector<int>> dp(n, vector<int>(k+1, -1));
    // return solveMem(arr, n-1, k, dp);
    
    // return solveTab(arr, n, k);
    return solveSO(arr, n, k);
}