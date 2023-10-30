class Solution {
public:
    int solveRec(int row, int col, vector<vector<int>>& grid){
        if(row==0 && col==0)
            return grid[0][0];
        if(row<0 || col<0)
            return INT_MAX;
        
        int left = INT_MAX;
        if(col>0)
            left = grid[row][col] + solveRec(row, col-1, grid);
        int top = INT_MAX;
        if(row>0)
            top = grid[row][col] + solveRec(row-1, col, grid);
            
        return min(left, top);
    }
    int solveTab( vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = grid[0][0];

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(row==0 && col==0)
                    continue;
                else{
                    int left = INT_MAX, top = INT_MAX;
                    if(col>0)
                        left = grid[row][col] + dp[row][col-1];
                    if(row>0)
                        top = grid[row][col] + dp[row-1][col];
                    
                    dp[row][col] = min(left, top);
                }
            }
        }

        return dp[n-1][m-1];
    }
    int solveSO( vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(n, INT_MAX);
        vector<int> curr(m, INT_MAX);
        prev[0] = grid[0][0];
        curr[0] = grid[0][0];

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(row==0 && col==0)
                    continue;
                else{
                    int left = INT_MAX, top = INT_MAX;
                    if(col>0)
                        left = grid[row][col] + curr[col-1];
                    if(row>0)
                        top = grid[row][col] + prev[col];
                    
                    curr[col] = min(left, top);
                }
            }
            prev = curr;
        }

        return prev[m-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // return solveRec(n-1, m-1, grid);

        // return solveTab(grid);
        return solveSO(grid);
    }
};