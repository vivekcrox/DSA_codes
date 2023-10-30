class Solution {
public:
    int solveRec(string& s, string& t, int i, int j){
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;
        
        if(s[i] == t[j])
            return solveRec(s, t, i-1, j-1) + solveRec(s, t, i-1, j);
        else
            return solveRec(s, t, i-1, j);
    }
    int solveMem(string& s, string& t, int i, int j, vector<vector<int>>&dp){
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = (solveMem(s, t, i-1, j-1, dp) + solveMem(s, t, i-1, j, dp));
        else
            return dp[i][j] = solveMem(s, t, i-1, j, dp);
    }
    // shifting indecies to write base case easily.
    int solveTab(string& s, string& t, int n, int m){
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int j=1; j<=m; j++){  // as j=0 already calc in above.
            dp[0][j] = 0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
    int solveSO(string& s, string& t, int n, int m){
        vector<double> prev(m+1, 0);
        vector<double> curr(m+1, 0);
        
        prev[0] = 1;
        curr[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[m];
    }
    int solveSO2(string& s, string& t, int n, int m){
        vector<double> prev(m+1, 0);
        
        prev[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){  //right to left.
                if(s[i-1] == t[j-1])
                    prev[j] = prev[j-1] + prev[j];
            }
        }
        return (int)prev[m];
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        // return solveRec(s,t, n-1, m-1);

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMem(s, t, n-1, m-1, dp);

        // return solveTab(s, t, n, m);
        // return solveSO(s, t, n, m);
        return solveSO2(s, t, n, m);
    }
};