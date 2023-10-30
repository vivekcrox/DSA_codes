class Solution{
public:
    int solveRec(vector<vector<int>>& mat, int i, int j, int& maxi){
        //base
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        int right = solveRec(mat, i, j+1, maxi);
        int down = solveRec(mat, i+1, j, maxi);
        int diagonal = solveRec(mat, i+1, j+1, maxi);
        
        if(mat[i][j] == 1){
            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    
    int solveMem(vector<vector<int>>& mat, int i, int j, int& maxi, vector<vector<int>>& dp){
        //base
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solveMem(mat, i, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
        
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    
    int solveTab(vector<vector<int>>& mat, int& maxi){
        vector<vector<int>> dp(mat.size()+1, vector<int>(mat[0].size()+1, 0));
        
        for(int i = mat.size()-1; i>=0; i--){
            for(int j=mat[0].size()-1; j>=0; j--){
                
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(down, diagonal));
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];   //doesn't matter as answer -> maxi
    }
    
    int solveSpaceOP1(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(col+1, 0);
        vector<int> next(col+1, 0);
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            next = curr;
        }
        return next[0];
    }
    
    // Here Space Complexity is O(1) as n and m at max can be 50 
    // By referring to the constraints in problem statment :- 1<= n, m <= 50
    int solveSpaceOP2(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(51, 0);
        vector<int> next(51, 0);
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            next = curr;
        }
        return next[0];
    }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        // solveRec(mat, 0, 0, maxi);
        // return maxi;
        
        // vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        // solveMem(mat, 0, 0, maxi, dp);
        // return maxi;
        
        // solveTab(mat, maxi);
        // return maxi;
        
        // solveSpaceOP1(mat, maxi);
        // return maxi;
        
        solveSpaceOP2(mat, maxi);
        return maxi;
    }
};