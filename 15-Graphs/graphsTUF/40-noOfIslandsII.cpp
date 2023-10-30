class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        vector<int> ans;
        
        for(auto it: operators){
            int row = it[0];      //extracting islands pt.(i.e {row,col}=1)
            int col = it[1];
            
            if(vis[row][col]==1){   //if find islands on same coordinates, which already calc.
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==1){
                    int currNodeNo = row*m + col;  //find node no from the matrix.
                    int adjNodeNo = nr*m + nc;
                    if(ds.findUPar(currNodeNo) != ds.findUPar(adjNodeNo)){ // present in +1 dist and not connected, then connect them.
                        cnt--;
                        ds.unionBySize(currNodeNo, adjNodeNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};