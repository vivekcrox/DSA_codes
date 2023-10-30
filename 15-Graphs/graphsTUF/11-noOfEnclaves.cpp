// 1. Using BFS
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        // traverse boundary 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!vis[i][j] && grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

        int enclave = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1)
                    enclave++;
            }
        }
        return enclave;
    }
};

// 2. Using DFS
class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>&grid, int drow[], int dcol[]){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,drow,dcol);
            }
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        // traverse first and last row
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j]==1)
                dfs(0,j,vis,grid,drow,dcol);
            if(!vis[n-1][j] && grid[n-1][j]==1)
                dfs(n-1,j,vis,grid,drow,dcol);
        }
        // traverse first and last col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,vis,grid,drow,dcol);
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i,m-1,vis,grid,drow,dcol);
        }
        
        int enclave = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    enclave++;
                }
            }
        }
        return enclave;
    }
};