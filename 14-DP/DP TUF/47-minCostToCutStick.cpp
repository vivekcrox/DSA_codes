class Solution {
public:
    int solveRec(vector<int>&cuts, int i, int j){
        if(i > j)
            return 0;
        
        int mini = INT_MAX;
        for(int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + solveRec(cuts, i, k-1) + solveRec(cuts, k+1, j);
            mini = min(mini, cost);
        }
        return mini;
    }
    int solveMem(vector<int>&cuts, int i, int j, vector<vector<int>>&dp){
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + solveMem(cuts, i, k-1, dp) + solveMem(cuts, k+1, j, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int solveTab(vector<int>&cuts, int n, int c){
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        

        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i > j)
                    continue;

                int mini = INT_MAX;
                for(int k=i; k<=j; k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());  //so that subproblem will be independent.

        // return solveRec(cuts, 1, c);

        // vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        // return solveMem(cuts, 1, c, dp);

        return solveTab(cuts, n, c);
    }
};