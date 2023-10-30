#include <bits/stdc++.h> 

int solveRec(vector<int>& arr, int i, int j){
    if(i==j)
        return 0;
    
    int mini = 1e9;
    for(int k=i; k<j; k++){
        int minOp = arr[i-1]*arr[k]*arr[j] + solveRec(arr,i,k) + solveRec(arr,k+1,j);
        mini = min(mini, minOp);
    }
    return mini;
}
int solveMem(vector<int>& arr, int i, int j,vector<vector<int>>&dp){
    if(i==j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mini = 1e9;
    for(int k=i; k<j; k++){
        int minOp = arr[i-1]*arr[k]*arr[j] + solveMem(arr,i,k,dp) + solveMem(arr,k+1,j,dp);
        mini = min(mini, minOp);
    }
    return dp[i][j] = mini;
}
int solveTab(vector<int>& arr, int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){  //as j always be ahead of i.
            int mini = 1e9;
            for(int k=i; k<j; k++){
                int minOp = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, minOp);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // return solveRec(arr, 1, N-1);

    // vector<vector<int>> dp(N, vector<int>(N, -1));
    // return solveMem(arr,1,N-1, dp);

    return solveTab(arr, N);
}