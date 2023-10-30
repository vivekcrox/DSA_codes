class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        //edge case
        if(source.first==destination.first && source.second==destination.second){
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;
        queue<pair<int,pair<int,int>>> q;  //{dist, {row,col}}
        q.push({0,{source.first, source.second}});
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        
        
        
        while(!q.empty()){
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 
                    dis + 1 < dist[nrow][ncol]){
                    
                    if(nrow == destination.first && ncol == destination.second){
                        return dis+1;
                    }
                    
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1, {nrow,ncol}});
                }
                
            }
        }
        return -1;
        
    }
};