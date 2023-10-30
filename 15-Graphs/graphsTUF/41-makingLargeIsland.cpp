class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        // step 1: connect all the 1's denoting island.
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int i=0; i<4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        int nodeNo = row*m + col;
                        int adjNo = nr*m + nc;
                        ds.unionBySize(nodeNo, adjNo);
                    }
                }
            }
        }
        // step 2: try to convert atmost one 0 to 1.
        int mx = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]==1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int> component;
                for(int i=0; i<4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        component.insert(ds.findUPar(nr*m + nc));
                    }
                }
                int totalSize = 0;
                for(auto it: component){
                    totalSize += ds.size[it];
                }
                mx = max(mx, totalSize + 1);  // +1 as one 0 converted to 1.
            }
        }
        // edge case: if all the cell have 1's (i.e single large island, no need to convert any 0)
        mx = max(mx, ds.size[0*m + 0]);

        return mx;
    }
};