class Solution {
public:
    int solveRec(int row, int col, vector<vector<int>>&obstacleGrid){
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }
        if(row>=0 && col>=0 && obstacleGrid[row][col] == 1){
            return 0;
        }

        int left = solveRec(row,col-1,obstacleGrid);
        int top = solveRec(row-1,col,obstacleGrid);
        
        long long ans = left + top;
        return (int)ans;
    }
    int solveMem(int row, int col, vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp){
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }
        if(row>=0 && col>=0 && obstacleGrid[row][col] == 1){
            return 0;
        }
        if(dp[row][col] != -1)
            return dp[row][col];

        int left = solveMem(row,col-1,obstacleGrid, dp);
        int top = solveMem(row-1,col,obstacleGrid, dp);
        
        dp[row][col] = left + top;
        return dp[row][col];
    }
    int solveTab(vector<vector<int>>&obstacleGrid){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(obstacleGrid[row][col] == 1){
                    dp[row][col] = 0;
                }
                else if(row==0 && col==0){
                    continue;
                }
                else{
                    int left = 0;
                    if(col>0)
                        left = dp[row][col-1];
                    int top = 0;
                    if(row>0)
                        top = dp[row-1][col];
                    
                    dp[row][col] = left + top;
                }
            }
        }
        return dp[n-1][m-1];
    }
    int solveSO(vector<vector<int>>&obstacleGrid){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        vector<int> curr(m, 0);
        prev[0] = 1;
        curr[0] = 1;

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(obstacleGrid[row][col] == 1){
                    curr[col] = 0;
                }
                else if(row==0 && col==0){
                    continue;
                }
                else{
                    int left = 0;
                    if(col>0)
                        left = curr[col-1];
                    int top = 0;
                    if(row>0)
                        top = prev[col];
                    
                    curr[col] = left + top;
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //edge
        if(obstacleGrid[0][0] == 1)
            return 0;

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int row = n-1;
        int col = m-1;
        // return solveRec(row, col, obstacleGrid);

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMem(row, col, obstacleGrid, dp);

        // return solveTab(obstacleGrid);
        return solveSO(obstacleGrid);
    }
};