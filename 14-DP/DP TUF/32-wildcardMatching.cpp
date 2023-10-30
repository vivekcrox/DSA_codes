class Solution {
public:
    bool solveRec(string& s, string& p, int i, int j){
        if(i<0 && j<0) 
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j] != '*')
                    return false;
                j--;
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?'){
            return solveRec(s,p, i-1, j-1);
        }
        if(p[j] == '*'){
            return solveRec(s,p, i-1, j) || solveRec(s,p, i, j-1);
        }
        return false;
    } 
    bool solveMem(string& s, string& p, int i, int j, vector<vector<int>>&dp){
        if(i<0 && j<0) 
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j] != '*')
                    return false;
                j--;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solveMem(s,p, i-1, j-1, dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = solveMem(s,p, i-1, j, dp) || solveMem(s,p, i, j-1, dp);
        }
        return dp[i][j] = false;
    } 
    //shifting of indices i.e 1-base indexing.
    bool solveTab(string& s, string& p, int n, int m){
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            dp[i][0] = false;
        }
        for(int j=1; j<=m; j++){
            bool flag = true;
            for(int it=1; it<=j; it++){
                if(p[it-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    } 
    // first loop for: pattern string.
    bool solveSO(string& s, string& p, int m, int n){
        vector<bool> prev(m+1, false);
        vector<bool> curr(m+1, false);

        prev[0] = true;
        for(int j=1; j<=m; j++){
            prev[j] = false;
        }

        for(int i=1; i<=n; i++){
            //for every row
            //you are assigning the 0th col's val.
            bool flag = true;
            for(int it=1; it<=i; it++){
                if(p[it-1] != '*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for(int j=1; j<=m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[i-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    } 

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        // return solveRec(s, p, n-1, m-1);

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMem(s, p, n-1, m-1, dp);

        // return solveTab(s, p, n, m);
        return solveSO(s,p, n, m);
    }
};