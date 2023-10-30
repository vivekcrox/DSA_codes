class Solution {
public:
    int solveRec(string& s1, string& s2, int i, int j){
        //base
        if(i < 0 || j < 0)
            return 0;

        if(s1[i]==s2[j])
            return 1 + solveRec(s1, s2, i-1, j-1);
        
        return max(solveRec(s1, s2, i-1, j), solveRec(s1, s2, i, j-1));
    }
    int solveMem(string& s1, string& s2, int i, int j, vector<vector<int>>&dp){
        //base
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i]==s2[j])
            return dp[i][j] = 1 + solveMem(s1, s2, i-1, j-1, dp);
        
        return dp[i][j] = max(solveMem(s1, s2, i-1, j, dp), solveMem(s1, s2, i, j-1, dp));
    }
    //Shifting of index: Assuming 0 to be 1 & so on.
    int solveTab(string& s1, string& s2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=m; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int solveSO(string& s1, string& s2, int n, int m){
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        
        for(int j=0; j<=m; j++){
            prev[j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // return solveRec(text1, text2, n-1, m-1);

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMem(text1, text2, n-1, m-1, dp);

        // return solveTab(text1, text2, n, m);
        return solveSO(text1, text2, n, m);
    }
};