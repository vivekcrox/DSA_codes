class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        
        unordered_map<int,int> stoneNodes;  // track which x- & y-points have stone.
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);   //connecting node as row & col.
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int cnt = 0;
        for(auto it: stoneNodes){   // finding total components in the graph.
            if(ds.findUPar(it.first) == it.first)
                cnt++;
        }
        return n - cnt;  // total stones - no. of components
    }
};