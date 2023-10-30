class Solution {
public:
    int solveRec(int row, int col){
        //base
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }

        int left = solveRec(row, col-1);
        int top = solveRec(row-1, col);
        return left + top;
    }
    int solveMem(int row, int col, vector<vector<int>>& dp){
        //base
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }
        if(dp[row][col] != -1)
            return dp[row][col];

        int left = solveRec(row, col-1);
        int top = solveRec(row-1, col);
        return dp[row][col] = left + top;
    }
    int solveTab(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(row==0 && col==0)
                    continue;
                int left = 0;
                if(col>0)
                    left = dp[row][col-1];
                int top = 0;
                if(row>0)
                    top = dp[row-1][col];
                dp[row][col] = left + top;
            }
        }
        return dp[m-1][n-1];
    }
    int solveSO(int m, int n){
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        prev[0] = 1;
        curr[0] = 1;

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(row==0 && col==0)
                    continue;
                int left = 0;
                if(col>0)
                    left = curr[col-1];
                int top = 0;
                if(row>0)
                    top = prev[col];
                curr[col] = left + top;
            }
            prev = curr;
        }
        return prev[n-1];
    }
    int nCr(int n, int r){
        long double ans = 1;
        for(int i=0; i<r; i++){
            ans = ans*(n-i);
            ans = ans/(i+1);
        }
        return (int)ans;
    }
    int combinatoric(int m, int n){
        int totalDir = (m-1)+(n-1);
        int rightDir = m-1;
        long double ways = nCr(totalDir, rightDir);
        return (int)ways ;
    }


    int uniquePaths(int m, int n) {
        // return solveRec(m-1, n-1);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveMem(m-1, n-1, dp);

        // return solveTab(m,n);
        // return solveSO(m,n);
        
        return combinatoric(m,n);
    }
};