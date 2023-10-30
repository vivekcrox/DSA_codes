class Solution {
public:
    //Using BFS is possible to calc min time to rotten the oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // {{row,col},time}
        queue<pair<pair<int,int>, int> > q;
        int visited[n][m];
        int cntFresh = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else
                    visited[i][j] = 0;
                    
                if(grid[i][j]==1)
                    cntFresh++;
            }
        }
        
        int time = 0;
        int drow[4] = {-1,0,1,0}; //U R D L
        int dcol[4] = {0,1,0,-1};
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            time = max(time, tm);
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},tm+1});
                    visited[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        
        if(cnt != cntFresh)
            return -1;
        
        return time;
    }
};