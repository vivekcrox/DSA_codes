class Solution {
public:
    int solveRec(int row, int col, vector<vector<int>>& matrix){
        if(row == 0){
            return matrix[0][col];
        }

        int up = matrix[row][col] + solveRec(row-1, col, matrix);
        int left = INT_MAX;
        if(col-1 >= 0)
            left = matrix[row][col] + solveRec(row-1, col-1, matrix);
        int right = INT_MAX;
        if(col+1 < matrix.size())
            right = matrix[row][col] + solveRec(row-1, col+1, matrix);
        
        return min(up, min(left, right));
    }
    int solveMem(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(row == 0){
            return matrix[0][col];
        }
        if(dp[row][col] != -1)
            return dp[row][col];

        int up = matrix[row][col] + solveMem(row-1, col, matrix, dp);
        int left = INT_MAX;
        if(col-1 >= 0)
            left = matrix[row][col] + solveMem(row-1, col-1, matrix, dp);
        int right = INT_MAX;
        if(col+1 < matrix.size())
            right = matrix[row][col] + solveMem(row-1, col+1, matrix, dp);
        
        return dp[row][col] = min(up, min(left, right));
    }
    int solveTab(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                int up = matrix[row][col] + dp[row-1][col]; 
                int left = INT_MAX;
                if(col-1 >= 0)
                    left = matrix[row][col] + dp[row-1][col-1];
                int right = INT_MAX;
                if(col+1 < matrix.size())
                    right = matrix[row][col] + dp[row-1][col+1];

                dp[row][col] = min(up, min(left, right));
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
    int solveSO(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<int> prev(n, INT_MAX);
        vector<int> curr(n, INT_MAX);
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }

        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                int up = matrix[row][col] + prev[col]; 
                int left = INT_MAX;
                if(col-1 >= 0)
                    left = matrix[row][col] + prev[col-1];
                int right = INT_MAX;
                if(col+1 < matrix.size())
                    right = matrix[row][col] + prev[col+1];

                curr[col] = min(up, min(left, right));
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, prev[j]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = INT_MAX;
        // for(int j=0; j<n; j++){
        //     ans = min(ans, solveRec(n-1, j, matrix));
        // }
        // return ans;

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int j=0; j<n; j++){
        //     ans = min(ans, solveMem(n-1, j, matrix, dp));
        // }
        // return ans;

        // int ans = solveTab(matrix);
        int ans = solveSO(matrix);
        if(ans != INT_MAX)
            return ans;
        else
            return 0;
    }
};