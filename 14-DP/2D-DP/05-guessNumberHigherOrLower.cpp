class Solution {
public:
    int solveRec(int start, int end){
        if(start >= end)
            return 0;

        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i + max(solveRec(start, i-1), solveRec(i+1, end)));
        }
        return ans;
    }

    int solveMem(int start, int end, vector<vector<int>>& dp){
        if(start >= end)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i + max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveTab(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int s=n; s>=1; s--){
            for(int e=s; e<=n; e++){
                if(s == e)   //already 0 marked
                    continue;
                else{
                    int ans = INT_MAX;
                    for(int i=s; i<=e; i++){
                        ans = min(ans, i + max(dp[s][i-1], dp[i+1][e]));  // when e=n -> when i=e -> i+1 => n+1 index access -> i.e dp (n+2)
                    }
                    dp[s][e] = ans;
                }
            }
        }
        return dp[1][n];

    }

    int getMoneyAmount(int n) {
        // return solveRec(1, n);
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(1, n, dp);

        return solveTab(n);
    }
};