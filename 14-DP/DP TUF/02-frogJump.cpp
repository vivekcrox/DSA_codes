#include <bits/stdc++.h> 

int frogJumpSolverUsingRec(vector<int>&heights, int i){
    //base
    if(i==0)
        return 0;

    int left = frogJumpSolverUsingRec(heights, i-1) + abs(heights[i] - heights[i-1]);
    int right = INT_MAX;
    if(i-2 >= 0)
      right = frogJumpSolverUsingRec(heights, i-2) + abs(heights[i] - heights[i-2]);
    return min(left, right);
}
int frogJumpSolverUsingMem(vector<int>&heights, int i, vector<int>& dp){
    //base
    if(i==0)
        return 0;
    if(dp[i] != -1)
        return dp[i];

    int left = frogJumpSolverUsingMem(heights, i-1, dp) + abs(heights[i] - heights[i-1]);
    int right = INT_MAX;
    if(i-2 >= 0)
      right = frogJumpSolverUsingMem(heights, i-2, dp) + abs(heights[i] - heights[i-2]);
    return dp[i] = min(left, right);
}
int frogJumpSolverUsingTab(vector<int>&heights, int n){
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i-2 >= 0)
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(left, right);
    }

    return dp[n-1];
}
int frogJumpSolverUsingSO(vector<int>&heights, int n){
    int prev2 = 0;
    int prev1 = 0;

    for(int i=1; i<n; i++){
        int left = prev1 + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i-2 >= 0)
            right = prev2 + abs(heights[i] - heights[i-2]);
        
        int curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int frogJump(int n, vector<int> &heights)
{
    // return frogJumpSolverUsingRec(heights, n-1);
    
    // vector<int> dp(n, -1);
    // return frogJumpSolverUsingMem(heights, n-1, dp);

    // return frogJumpSolverUsingTab(heights, n);
    return frogJumpSolverUsingSO(heights, n);
}