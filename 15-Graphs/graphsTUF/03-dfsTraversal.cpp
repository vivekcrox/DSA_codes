class Solution {
  public:
    // Function to return a list containing the DFS traversal of the connected graph.
    
    void dfs(int src, vector<int>& dfsAns, vector<int>& visited, vector<int> adj[]){
        visited[src] = 1;
        dfsAns.push_back(src);
        
        for(auto nbr: adj[src]){
            if(!visited[nbr])
                dfs(nbr, dfsAns, visited, adj);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int src = 0;
        vector<int> dfsAns;
        vector<int> visited(V, 0);
        
        dfs(src, dfsAns, visited, adj);
        return dfsAns;
    }