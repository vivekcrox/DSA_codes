class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // {diff, {row,col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;    
        

        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0; //src
        pq.push({0,{0,0}});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
        
            if(row==n-1 && col==m-1)  //return ans if reached dest as now in pq there will more effort
                return diff;
            
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);//store max effort while in same path.
                    if(newEffort < dist[nrow][ncol]){ // update effort if found less effort than earlier.
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;  // unreachable
    }
};