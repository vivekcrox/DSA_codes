class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        visited[row][col] = 1;
        
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //check 8 directions + 1 itself
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow >=0 && nrow < n && ncol>=0 && ncol < m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            // //check 4 directions(On Leetcode check only for horizontal & verical dir not diagonals)
            // This xdir & ydir array declare globally.
            // int xdir[4] = {1,0,0,-1};  // D L R U
            // int ydir[4] = {0,-1,1,0}; 

            // for(int k=0; k<4; k++){
            //     int nrow = row+xdir[k];
            //     int ncol = col+ydir[k];
            //     if(nrow >=0 && nrow < m && ncol>=0 && ncol < n && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
            //         visited[nrow][ncol] = 1;
            //         q.push({nrow, ncol});
            //     }
            // }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int island = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    island++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return island;
    }
};

// Using DFS Traversal
    int xdir[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // DUL U DUR L R DBL D DBR(idiagonal bottom right)
    int ydir[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid, int&n, int&m){
        visited[row][col] = 1;

        for(int i=0; i<8; i++){
            int nrow = row + xdir[i];
            int ncol = col + ydir[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, visited, grid,n,m);
            }
        }
        // // Or can use this method to mark all 8 directions.
        // for(int i=-1; i<=1; i++){
        //     for(int j=-1; j<=1; j++){
        //         int nrow = row+i;
        //         int ncol = col+j;
        //         if(nrow >=0 && nrow < n && ncol>=0 && ncol < m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
        //             dfs(nrow,ncol,visited,grid,n,m);
        //         }
        //     }
        // }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int row = 0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    island++;
                    dfs(row, col, visited, grid, n, m);
                }
            }
        }
        return island;
    }