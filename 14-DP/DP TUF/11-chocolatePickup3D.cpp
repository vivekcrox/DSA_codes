#include <bits/stdc++.h> 

int solveRec(int i, int j1, int j2, vector<vector<int>> &grid){
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
        return INT_MIN;
    if(i==grid.size()-1){
        if(j1==j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    int maxi = INT_MIN;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            int value = 0;
            if(j1==j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            
            value += solveRec(i+1, j1+dj1, j2+dj2, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
int solveMem(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>>&dp){
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
        return INT_MIN;
    if(i==grid.size()-1){
        if(j1==j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            int value = 0;
            if(j1==j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            
            value += solveMem(i+1, j1+dj1, j2+dj2, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int solveTab(vector<vector<int>> &grid){
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    for(int j1=0; j1<c; j1++){
        for(int j2=0; j2<c; j2++){
            if(j1==j2)
                dp[r-1][j1][j2] = grid[r-1][j1];
            else
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i=r-2; i>=0; i--){
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){

                int maxi = INT_MIN;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        int value = 0;
                        if(j1==j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c)
                            value += dp[i+1][j1+dj1][j2+dj2];
                        else   
                            value = INT_MIN;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c-1];
}
int solveSO(vector<vector<int>> &grid){
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> prev(c, vector<int>(c, INT_MIN));
    vector<vector<int>> curr(c, vector<int>(c, INT_MIN));
    
    for(int j1=0; j1<c; j1++){
        for(int j2=0; j2<c; j2++){
            if(j1==j2)
                prev[j1][j2] = grid[r-1][j1];
            else
                prev[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i=r-2; i>=0; i--){
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){

                int maxi = INT_MIN;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        int value = 0;
                        if(j1==j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c)
                            value += prev[j1+dj1][j2+dj2];
                        else   
                            value = INT_MIN;
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }
    return prev[0][c-1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // return solveRec(0, 0, c-1, grid);

    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    // return solveMem(0,0,c-1,grid,dp);

    // return solveTab(grid);
    return solveSO(grid);
}