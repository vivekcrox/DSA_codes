class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1){
                    // i and j
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<V; i++){
            if(ds.parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};