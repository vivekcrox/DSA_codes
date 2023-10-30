class Solution {
public:
    int solveRec(int n){
        if(n <= 1)
            return 1;
        
        int ans = 0;
        // think i as root node
        for(int i=1; i<=n; i++){
            ans += solveRec(i-1) * solveRec(n-i);
        }
        return ans;
    }

    int solveMem(int n, vector<int>& dp){
        if(n <= 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        // think i as root node
        for(int i=1; i<=n; i++){
            ans += solveRec(i-1) * solveRec(n-i);
        }
        dp[n] = ans;
        return dp[n];
    }

    int solveTab(int n){
        vector<int> dp(n+1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for(int node=2; node<=n; node++){
            int ans = 0;
            // think i as root node
            for(int i=1; i<=n; i++){
                if(node-i >=0)
                    dp[node] += dp[i-1] * dp[node-i];
            }
        }
        return dp[n];
    }

    

    int catalan_number(int n){
        int catalan[n+1];
        catalan[0] = catalan[1] = 1;

        for(int i=2; i<=n; i++){
            catalan[i] = 0;
            for(int j=0; j<i; j++)
                catalan[i] += catalan[j]*catalan[i-j-1];
        }
        return catalan[n];
    }

    int numTrees(int n) {
        // return solveRec(n);

        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);

        return solveTab(n);

        // using Catalan number
        // return catalan_number(n);
    }
};