class Solution {
public:
    int solveRec(string& s, string& t, int i, int j){
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        
        if(s[i] == t[j])
            return 0 + solveRec(s, t, i-1, j-1);
        else   //insert, delete, update
            return 1 + min(solveRec(s,t,i,j-1), min(solveRec(s,t,i-1,j), solveRec(s,t,i-1,j-1)));
    }
    int solveMem(string& s, string& t, int i, int j,vector<vector<int>>&dp){
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = 0 + solveMem(s, t, i-1, j-1,dp);
        else   //insert, delete, update
            return dp[i][j] = 1 + min(solveMem(s,t,i,j-1,dp), min(solveMem(s,t,i-1,j,dp), solveMem(s,t,i-1,j-1,dp)));
    }
    int solveTab(string& s, string& t, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j=0; j<=m; j++){
            dp[0][j] = j;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 0 + dp[i-1][j-1];
                else   //insert, delete, update
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
    int solveSO(string& s, string& t, int n, int m){
        vector<int> prev(m+1, 0); 
        vector<int> curr(m+1, 0); 

        for(int j=0; j<=m; j++){
            prev[j] = j;
        }

        for(int i=1; i<=n; i++){
            curr[0] = i;        // as for col 0 it must start with ith val.
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    curr[j] = 0 + prev[j-1];
                else   //insert, delete, update
                    curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
            }
            prev = curr;
        }
        return prev[m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(); 
        int m = word2.length();
        // return solveRec(word1, word2, n-1, m-1);

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMem(word1, word2, n-1, m-1, dp);

        // return solveTab(word1, word2, n, m);
        return solveSO(word1, word2, n, m);
    }
};