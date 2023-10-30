class Solution {
public:
    int solveRec(int row, int col, vector<vector<int>>&triangle){
        if(row == triangle.size()-1){
            return triangle[triangle.size()-1][col];
        }

        int down = INT_MAX, diagonal = INT_MAX;
        if(row<triangle.size())
            down = triangle[row][col] + solveRec(row+1, col, triangle);

        if(row<triangle.size() && col<triangle.size())
            diagonal = triangle[row][col] + solveRec(row+1, col+1, triangle);
        
        return min(down, diagonal);
    }
    int solveMem(int row, int col, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(row == triangle.size()-1){
            return triangle[triangle.size()-1][col];
        }
        if(dp[row][col] != -1)
            return dp[row][col];

        int down = INT_MAX, diagonal = INT_MAX;
        if(row<triangle.size())
            down = triangle[row][col] + solveMem(row+1, col, triangle, dp);
        if(row<triangle.size() && col<triangle.size())
            diagonal = triangle[row][col] + solveMem(row+1, col+1, triangle, dp);
        
        return dp[row][col] = min(down, diagonal);
    }
    int solveTab(vector<vector<int>>&triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int row=n-2; row>=0; row--){
            for(int col=row; col>=0; col--){
                int down = INT_MAX, diagonal = INT_MAX;
                if(row>=0)
                    down = triangle[row][col] + dp[row+1][col];
                if(row>=0 && col>=0)
                    diagonal = triangle[row][col] + dp[row+1][col+1];
                
                dp[row][col] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
    int solveSO(vector<vector<int>>&triangle){
        int n = triangle.size();
        vector<int> curr(n, INT_MAX);
        vector<int> next(n, INT_MAX);
        for(int j=0; j<n; j++){
            next[j] = triangle[n-1][j];
        }

        for(int row=n-2; row>=0; row--){
            for(int col=row; col>=0; col--){

                int down = triangle[row][col] + next[col];
                int diagonal = triangle[row][col] + next[col+1];
                
                curr[col] = min(down, diagonal);
            }
            next = curr;
        }

        return next[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return solveRec(0, 0, triangle); //start with (0,0) as we have fixed src o/w loop req.

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMem(0,0, triangle, dp);

        // return solveTab(triangle);
        return solveSO(triangle);
    }
};